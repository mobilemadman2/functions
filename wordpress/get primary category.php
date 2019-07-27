<?php
/**
 * Get primary category
 * https://stackoverflow.com/questions/43114986/get-primary-category-if-more-than-one-is-selected
 *
 * @param $product_id
 *
 * @return mixed
 */
function get_product_primary_category( $product_id ) {
	$terms = wp_get_post_terms( $product_id, PRODUCT_CATEGORIES );
	foreach ( $terms as $term ) {
		if ( get_post_meta( $product_id, '_yoast_wpseo_primary_' . PRODUCT_CATEGORIES, true ) == $term->term_id ) {
			// this is a primary category
			return $term;
		}
	}
}