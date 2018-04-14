/**** print object - for testing only ****/
function purinto( $obj = '' ) {
	if ( $obj == '' ) {
		$obj = get_queried_object();
	}
	echo '<pre>';
	print_r( $obj );
	echo '</pre>';
}