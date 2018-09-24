<?php
/**
 * Advanced Custom Field | Google map set up
 */
define( 'GOOGLE_MAP_API', 'AIzaSyBTQtDyESOlI739C52WowmVLyX_9B2x2Xc' );

/**
 * Enqueue script
 */
// Remove this line if you already have WP Google Map plugin
wp_enqueue_script( 'ggmap-api', 'https://maps.googleapis.com/maps/api/js?key=AIzaSyBTQtDyESOlI739C52WowmVLyX_9B2x2Xc' );
wp_enqueue_script( 'acf-ggmap', get_template_directory_uri() . '/js/acf-google-map.js' );

/**
 * ACF Google map
 */
function my_acf_init() {
	acf_update_setting( 'google_api_key', GOOGLE_MAP_API );
}

add_action( 'acf/init', 'my_acf_init' );