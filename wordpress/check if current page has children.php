<?php
/**
 * Check if current page has children
 *
 * @param null $post_id
 *
 * @return bool
 */
function has_children( $post_id = null ) {
	if ( $post_id == null ) {
		global $post;
		$post_id = $post->ID;
	}

	$children = get_pages( array( 'child_of' => $post_id ) );
	if ( count( $children ) == 0 ) {
		return false;
	} else {
		return true;
	}
}