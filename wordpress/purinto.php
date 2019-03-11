<?php
/**
 * Print readable vars
 *
 * @param bool $obj
 */
function _print_r( $obj = false ) {
	if ( ! $obj ) {
		$obj = get_queried_object();
	}
	echo '<pre>';
	print_r( $obj );
	echo '</pre>';
}