<?php
/**
 * Add custom item to Yoast breadcrumb
 *
 * @param $links
 *
 * @return mixed
 */
function customize_yoast_breadcrumb( $links ) {
	$machine_cat = new \stavelse\machinebouw_category();

	// Check if is in taxonomy page
	if ( $machine_cat->is_machinebouw_tax() || $machine_cat->is_machinebouw_single() ) {

		// Add new item
		$breadcrumb[] = array(
			'url'  => $machine_cat->get_archive_page()['permalink'],
			'text' => $machine_cat->get_archive_page()['title'],
		);

		array_splice( $links, 1, - 2, $breadcrumb );
	}

	return $links;
}

add_filter( 'wpseo_breadcrumb_links', 'customize_yoast_breadcrumb' );