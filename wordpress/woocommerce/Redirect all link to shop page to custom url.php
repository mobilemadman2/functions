<?php
/**
 * Redirect all link to shop page to custom url
 * @param $link
 *
 * @return string
 */
function return_to_shop_url( $link ) {
	// Get all product categories
	return SITE_URL . "/product-category/badkamermeubels/";
}
add_filter( 'woocommerce_return_to_shop_redirect', 'return_to_shop_url' );