<?php
/**
 * Get popular posts
 * Ref: https://www.wpbeginner.com/wp-tutorials/how-to-track-popular-posts-by-views-in-wordpress-without-a-plugin/
 */

/**
 * Count post view
 * @param $postID
 */
function wpb_set_post_views($postID) {
	$count_key = 'wpb_post_views_count';
	$count = get_post_meta($postID, $count_key, true);
	if($count==''){
		$count = 0;
		delete_post_meta($postID, $count_key);
		add_post_meta($postID, $count_key, '0');
	}else{
		$count++;
		update_post_meta($postID, $count_key, $count);
	}
}
//To keep the count accurate, lets get rid of prefetching
remove_action( 'wp_head', 'adjacent_posts_rel_link_wp_head', 10, 0);

/**
 * Get popular post
 */
$popular_posts = new WP_Query( array(
	'posts_per_page' => 4,
	'meta_key'       => 'wpb_post_views_count',
	'orderby'        => 'meta_value_num',
	'order'          => 'DESC'
) );

/**
 * Get view count
 */
$count_key = 'wpb_post_views_count';
$count     = get_post_meta( $post->ID, $count_key, true );