<?php
/*
Template Name: Điều hướng tới trang con đầu tiên
*/
if ( have_posts() ) {
	while ( have_posts() ) {
		the_post();
		$child_pages = get_pages( "child_of=" . $post->ID . "&sort_column=menu_order" );
		$first_child = $child_pages[0];
		wp_redirect( get_permalink( $first_child->ID ) );
	}
}