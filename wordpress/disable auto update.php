<?php
/**
 * Disable automatic WordPress plugin updates
 * Disable automatic WordPress theme updates
 * Disable admin bar on front-end
 */
add_filter( 'auto_update_plugin', '__return_false' );
add_filter( 'auto_update_theme', '__return_false' );
add_filter( 'show_admin_bar', '__return_false' );