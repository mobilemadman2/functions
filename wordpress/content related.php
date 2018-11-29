<?php
$categories     = get_the_category( get_the_ID() );
$category_class = '';
if ( count( $categories ) > 0 ) {
	foreach ( $categories as $category ) {
		$category_class .= ' ' . $category->slug;
	}
}
$link = get_the_permalink();
$img  = wp_get_attachment_image_url( get_post_thumbnail_id(), "post-thumbnail" );
if ( ! empty( get_field( "news_image_overview" ) ) ) {
	$img = get_field( "news_image_overview" );
}
if ( empty( $img ) ) {
	$default = get_field( "default_thumbnail", "option" );
	$img     = $default["sizes"]["post-thumbnail"];
}
$title     = get_the_title();
$category_name = '';
if(get_post_type(get_the_ID()) != 'post'){
    $category_name = get_post_type(get_the_ID());
}else{
    $category_id = twc_get_primary_category(get_the_ID());
    $term = get_term_by( 'id', absint( $category_id ), 'category' );
    if($term){
        $category_name = $term->name;
    }else{
        global $wp_post_types;
        $obj = $wp_post_types['post'];
        $category_name = $obj->labels->singular_name;
    }
}
?>
<div class="item element-item<?= $category_class; ?>" data-year="<?= $year ?>">
    <div class="item-inner" data-link="<?= $link ?>">
        <div class="item-thumbnail" style="background-image: url('<?= $img; ?>')">
            <img src="<?= $img; ?>" alt="<?= $title; ?>"/>
        </div>
        <div class="item-info">
            <div class="item-type"><?= $category_name; ?></div>
            <h3 class="item-title"><?= $title ?></h3>
        </div>
    </div>
</div>

<!-- USE THIS CODE TO SHOW RELATED ITEMS -->
<div class="related-wrapper">
	<?php
	$related = get_posts( array(
		'numberposts'  => 9,
		'post__not_in' => array( get_the_ID() ),
		'post_type'        => CAREER_TYPE
	) );
	if ( $related ):
		?>
        <div class="related-inner">
            <h2 class="related-title"><span><?php echo __( 'gelijkaardige jobs', 'campine' ); ?></span></h2>
            <div class="related-list-content">
                <div class="related-list list-items"
                     data-slick='{
                             "slidesToShow": 3,
                             "slidesToScroll": 1,
                             "infinite": true,
                             "dots": true,
                             "arrows": false,
                             "responsive": [
                             {
                             "breakpoint": 1170,
                             "settings": {"slidesToShow": 2}
                             },
                             {
                             "breakpoint": 680,
                             "settings": {"slidesToShow": 1}
                             }]}'>
					<?php
					foreach ( $related as $post ) {
						setup_postdata( $post );
						get_template_part( 'partials/content', 'related' );
					}
					?>
                </div>
            </div>
        </div>
		<?php
		wp_reset_postdata();
	endif;
	?>
</div>