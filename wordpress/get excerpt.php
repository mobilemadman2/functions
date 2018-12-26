<?php
/**
 * Get excerpt
 * https://developer.wordpress.org/reference/hooks/excerpt_length
 * https://developer.wordpress.org/reference/functions/wp_trim_excerpt
 */

// custom length
function custom_excerpt_length( $length ) {
	return 20;
}
add_filter( 'excerpt_length', 'custom_excerpt_length', 999 );

// auto trim excerpt from content if excerpt field is empty
$excerpt  = ! empty( get_the_excerpt() ) ? get_the_excerpt() : wp_trim_excerpt();