<?php
// Get related posts as slider
$related = get_posts( array(
	'category__in' => wp_get_post_categories( get_the_ID() ),
	'numberposts'  => 9,
	'post__not_in' => array( get_the_ID() )
) );
if ( $related ) :;
	?>
    <div class="related-items">
        <h2 class="related-title"><?php echo __( 'Related items', 'econocom' ); ?></h2>
        <div class="related-list-content">
            <div class="related-list">
				<?php
				foreach ( $related as $post ) {
					setup_postdata( $post );
					get_template_part( 'partials/content', 'post' );
				}
				?>
            </div>
        </div>
    </div>
	<?php
	wp_reset_postdata();
endif;
?>