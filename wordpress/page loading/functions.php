<?php
/**
 * Add body class
 */
function add_slug_body_class( $classes ) {
	$classes[] = 'twc-page-loading';

	return $classes;
}

add_filter( 'body_class', 'add_slug_body_class' );