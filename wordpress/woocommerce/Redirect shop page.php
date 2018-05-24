<?php
/**
 * Redirect shop page
 */
function custom_shop_page_redirect() {
	if( is_shop() ){
		wp_redirect( home_url( '/product-category/badkamermeubels/' ) );
		exit();
	}
}