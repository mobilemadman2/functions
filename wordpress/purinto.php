<?php
/**
 * Print readable vars
 *
 * @param bool $obj
 */
function purinto( $obj = false ) {
	if ( ! $obj ) {
		$obj = get_queried_object();
	}
	echo '<pre>';
	print_r( $obj );
	echo '</pre>';
}