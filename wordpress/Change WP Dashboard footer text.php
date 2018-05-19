<?php
/**
 * Change WP Dashboard footer text
 */
function remove_footer_admin() {
	echo '<span id="footer-thankyou">Developed by <a href="http://www.thewebsitecompany.be" target="_blank">The Website Company</a></span>';
}
add_filter( 'admin_footer_text', 'remove_footer_admin' );