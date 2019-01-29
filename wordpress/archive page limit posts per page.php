<?php
/**
 * Limit posts per page
 * https://wordpress.stackexchange.com/questions/181487/archive-page-limiting-posts-per-page
 * @param $query
 */
function wpd_testimonials_query( $query ){
	if( ! is_admin()
	    && $query->is_post_type_archive( 'testimonials' )
	    && $query->is_main_query() ){
		$query->set( 'posts_per_page', 5 );
	}
}
add_action( 'pre_get_posts', 'wpd_testimonials_query' );