<?php
$related = get_posts(
	array(
		'post_type'    => PRODUCT_TYPE,
		'category__in' => wp_get_post_categories( get_the_ID() ),
		'numberposts'  => 9,
		'post__not_in' => array( get_the_ID() )
	)
);

if ( $related ) :?>
    <div class="related-products product-list">
        <div class="related-slider custom-slick-arrow">
            <div class="related-slider-inner">
				<?php
				foreach ( $related as $post ) {
					setup_postdata( $post );
					get_template_part( 'partials/content', 'product' );
				}
				wp_reset_postdata();
				?>
            </div>
        </div>
    </div>
<?php endif; ?>