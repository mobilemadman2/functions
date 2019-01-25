<?php
/**
 * Redirect with custom url structure
 */
function twc_redirect_cpt_url() {
	/* in this array: old URLs => new URLs  */
	$redirect_rules = array(
		array( 'old' => site_url( '/services/' ), 'new' => site_url( '/diensten/' ) ),
	);

	global $wp;
	$currentURL = home_url( $wp->request ) . '/';

	foreach ( $redirect_rules as $rule ) {
		// if URL of request matches with the one from the array, then redirect
		if ( strpos( $currentURL, $rule['old'] ) !== false ) {
			wp_redirect( str_replace( $rule['old'], $rule['new'], $currentURL ), 301 );
			exit();
		}
	}
}

add_action( 'template_redirect', 'twc_redirect_cpt_url' );