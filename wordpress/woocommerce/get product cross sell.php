<?php
/**
 * Get product cross sell
 */
function get_product_cross_sell(){
	// Get cross sell ids
	global $product;
	$cross_sell_ids = $product->get_cross_sell_ids();

	// Start product loop
	woocommerce_product_loop_start();
	foreach($cross_sell_ids as $cross_sell_id){
		// Get post
		$post_object = get_post( $cross_sell_id );

		// Assign post to global post
		setup_postdata( $GLOBALS['post'] =& $post_object );

		// Print product with global post
		wc_get_template_part( 'content', 'product' );
	}
	woocommerce_product_loop_end();

	// Reset post data
	wp_reset_postdata();
}

/**
 * Add cross sell to single product page
 */
add_action( 'woocommerce_after_single_product_summary', 'get_product_cross_sell', 15 );