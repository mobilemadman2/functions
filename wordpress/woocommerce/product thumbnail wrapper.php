<?php
/**
 * This snippet removes the action that inserts thumbnails to products in teh loop
 * and re-adds the function customized with our wrapper in it.
 * It applies to all archives with products.
 * https://gist.github.com/krogsgard/3015581
 *
 * @original plugin: WooCommerce
 * @author of snippet: Brian Krogsard
 * @customizer: BMP
 */

remove_action( 'woocommerce_before_shop_loop_item_title', 'woocommerce_template_loop_product_thumbnail', 10 );
add_action( 'woocommerce_before_shop_loop_item_title', 'woocommerce_template_loop_product_thumbnail', 10 );
/**
* WooCommerce Loop Product Thumbs
**/
if ( ! function_exists( 'woocommerce_template_loop_product_thumbnail' ) ) {
function woocommerce_template_loop_product_thumbnail() {
echo woocommerce_get_product_thumbnail();
}
}
/**
* WooCommerce Product Thumbnail
**/
if ( ! function_exists( 'woocommerce_get_product_thumbnail' ) ) {

function woocommerce_get_product_thumbnail( $size = 'shop_catalog' ) {
global $post;
$thumbnail_url = get_the_post_thumbnail_url( $post->ID, $size );
if ( empty( $thumbnail_url ) ) {
$thumbnail_url = woocommerce_placeholder_img_src();
}

$output = '<div class="product-thumbnail" style="background-image: url(' . $thumbnail_url . ')">';
	if ( has_post_thumbnail() ) {
	$output .= get_the_post_thumbnail( $post->ID, $size );
	} else {
	$output .= '<img src="' . $thumbnail_url . '" alt="Placeholder" />';
	}

	$output .= '</div>';

return $output;
}
}