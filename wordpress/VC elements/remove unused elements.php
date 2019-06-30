<?php
/**
 * Remove unused elements
 */
if ( get_current_user_id() !== 1 ) {
	add_action( 'vc_after_init', 'vc_after_init_actions' );
}

function vc_after_init_actions() {
	// Remove VC Elements
	if ( function_exists( 'vc_remove_element' ) ) {
		vc_remove_element( 'vc_icon' );
		vc_remove_element( 'vc_gallery' );
		vc_remove_element( 'vc_section' );
		vc_remove_element( 'vc_message' );
		vc_remove_element( 'vc_images_carousel' );
		vc_remove_element( 'vc_cta' );
		vc_remove_element( 'vc_custom_heading' );
		vc_remove_element( 'vc_round_chart' );
		vc_remove_element( 'vc_line_chart' );
		vc_remove_element( 'vc_masonry_grid' );
		vc_remove_element( 'vc_pie' );
		vc_remove_element( 'vc_basic_grid' );
		vc_remove_element( 'vc_media_grid' );
		vc_remove_element( 'vc_posts_slider' );
		vc_remove_element( 'vc_progress_bar' );
		vc_remove_element( 'vc-acf-field-picker' );
		vc_remove_element( 'vc_gutenberg' );
		vc_remove_element( 'vc_posts_slider' );
		vc_remove_element( 'vc_wp_search' );
		vc_remove_element( 'vc_wp_meta' );
		vc_remove_element( 'vc_wp_recentcomments' );
		vc_remove_element( 'vc_wp_calendar' );
		vc_remove_element( 'vc_wp_pages' );
		vc_remove_element( 'vc_wp_tagcloud' );
		vc_remove_element( 'vc_wp_custommenu' );
		vc_remove_element( 'vc_wp_text' );
		vc_remove_element( 'vc_wp_posts' );
		vc_remove_element( 'vc_wp_categories' );
		vc_remove_element( 'vc_wp_archives' );
		vc_remove_element( 'vc_wp_rss' );
		vc_remove_element( 'vc_hoverbox' );
		vc_remove_element( 'vc_facebook' );
		vc_remove_element( 'vc_tweetmeme' );
		vc_remove_element( 'vc_pinterest' );
		vc_remove_element( 'vc_toggle' );
		vc_remove_element( 'vc-vc-snippet' );
		vc_remove_element( 'vc_masonry_media_grid' );
		vc_remove_element( 'vc_tta_pageable' );
		vc_remove_element( 'vc_raw_js' );
		vc_remove_element( 'vc_raw_html' );
		vc_remove_element( 'vc_widget_sidebar' );
		vc_remove_element( 'vc_btn' );
		vc_remove_element( 'vc-acf-template-field-picker' );
		vc_remove_element( 'vc_acf' );
		vc_remove_element( 'vc_googleplus' );
		vc_remove_element( 'vc_tabs' );
		vc_remove_element( 'vc_accordion' );
		vc_remove_element( 'vc_tour' );
		vc_remove_element( 'vc_flickr' );
		vc_remove_element( 'vc_tta_tour' );
		vc_remove_element( 'vc_empty_space' );
		vc_remove_element( 'vc_zigzag' );

		// Woo
		vc_remove_element( 'recent_products' );
		vc_remove_element( 'featured_products' );
		vc_remove_element( 'product' );
		vc_remove_element( 'products' );
		vc_remove_element( 'add_to_cart' );
		vc_remove_element( 'add_to_cart_url' );
		vc_remove_element( 'product_page' );
		vc_remove_element( 'product_category' );
		vc_remove_element( 'product_categories' );
		vc_remove_element( 'sale_products' );
		vc_remove_element( 'best_selling_products' );
		vc_remove_element( 'top_rated_products' );
		vc_remove_element( 'product_attribute' );

	}
}