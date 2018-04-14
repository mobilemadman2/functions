https://iconicwp.com/blog/update-custom-cart-count-html-ajax-add-cart-woocommerce/

// header.php
<span id="cart-count"><?php echo WC()->cart->get_cart_contents_count(); ?></span>

// functions.php
/**
 * Update cart count using AJAX
 */
add_filter( 'woocommerce_add_to_cart_fragments', 'iconic_cart_count_fragments', 10, 1 );
function iconic_cart_count_fragments( $fragments ) {
	$fragments['#cart-count'] = '<span id="cart-count">' . WC()->cart->get_cart_contents_count() . '</span>';
	return $fragments;

}