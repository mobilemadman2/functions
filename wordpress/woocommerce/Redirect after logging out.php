<?php
/**
 * Redirect after logging out
 */
add_action( 'wp_logout', 'auto_redirect_external_after_logout');
function auto_redirect_external_after_logout(){
	wp_redirect(SITE_URL);
	exit();
}