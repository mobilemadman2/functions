<?php
/**
 * Check if current page has children
 * @return bool
 */
function has_children() {
	global $post;

	$children = get_pages( array( 'child_of' => $post->ID ) );
	if( count( $children ) == 0 ) {
		return false;
	} else {
		return true;
	}
}