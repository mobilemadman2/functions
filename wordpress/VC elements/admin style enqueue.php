<?php
/**
 * Style for VC Elements in backend
 */
function wpdocs_enqueue_custom_admin_style() {
	wp_register_style( 'custom_wp_admin_css', THEME_URL . '/assets/css/admin-style.css', false, '1.0.0' );
	wp_enqueue_style( 'custom_wp_admin_css' );
}

add_action( 'admin_enqueue_scripts', 'wpdocs_enqueue_custom_admin_style' );