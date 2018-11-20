<?php
/**
 * Add body class
 */
function add_slug_body_class( $classes ) {
	global $post;
	if ( isset( $post ) ) {
		$classes[] = 'twc-page-loading';
	}

	return $classes;
}

add_filter( 'body_class', 'add_slug_body_class' );