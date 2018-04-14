/**
 * Change number product shown per page
 */
function new_loop_shop_per_page( $cols ) {
	// $cols contains the current number of products per page based on the value stored on Options -> Reading
	// Return the number of products you wanna show per page.
	$cols = 9;
	return $cols;
}
add_filter( 'loop_shop_per_page', 'new_loop_shop_per_page', 20 );