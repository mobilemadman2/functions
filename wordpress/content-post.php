<?php
$categories     = get_the_category( get_the_ID() );
$category_class = '';
if ( count( $categories ) > 0 ) {
	foreach ( $categories as $category ) {
		$category_class .= ' ' . $category->slug;
	}
}
$title    = get_the_title();
$time     = get_the_date( 'F Y' );
$location = ! empty( get_field( 'location' ) ) ? '<span>' . get_field( 'location' ) . '</span>' : '';
$excerpt  = get_the_excerpt();
$img      = wp_get_attachment_image_url( get_post_thumbnail_id(), "full" );
if ( empty( $img ) ) {
	$img = DEFAULT_THUMBNAIL;
}
$url = get_the_permalink();
?>
<div class="post-home-item <?= $category_class ?>">
    <div class="inner">
        <div class="text">
            <h3 class="title"><?= $title ?></h3>
            <div class="loc-time"><?= $location ?><?= $time ?></div>
            <div class="excerpt"><?= $excerpt ?></div>
            <div class="view-post">
                <a href="<?= $url ?>"><?= __( 'See Post', 'danyonen' ) ?></a>
            </div>
        </div>
        <div class="thumbnail">
            <div class="inner" style="background-image: url(<?= $img ?>)">
                <img src="<?= $img ?>" alt="<?= $title ?>">
            </div>
        </div>
    </div>
</div>
