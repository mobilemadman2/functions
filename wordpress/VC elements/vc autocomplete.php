<?php
/**
 * VC Element with Auto Complete (replace [base] and [param_name])
 * https://cactusthemes.com/blog/autocomplete-param-type-visual-composer/
 */

vc_map( array(
	"name"     => __( "Auto Complete Element", "textdomain" ),
	"base"     => "[base]",
	"category" => VC_CATEGORY,
	"icon"     => VC_ICON,
	"params"   => array(
		array(
			"type"        => "autocomplete",
			"heading"     => __( "Select", "textdomain" ),
			"param_name"  => 'ids',
			"settings"    => array(
				'multiple'      => true,
				'sortable'      => true,
				'unique_values' => true,
				'auto_focus'    => true,
				'min_length'    => 1,
				'groups'        => true,
				'delay'         => 500
			),
			'save_always' => true,
			'admin_label' => true
		)
	)
) );

add_filter( 'vc_autocomplete_[base]_[param_name]_callback', "[base]_autoCompleteSuggester", 10, 1 );
add_filter( 'vc_autocomplete_[base]_[param_name]_render', "[base]_autoCompleteRender", 10, 1 );

add_shortcode( "[base]", "[base]_shortcode" );

function [base]_shortcode( $attrs ) {
	$html = "";
	$arr  = explode( ",", $attrs['ids'] );
	print_r( $arr );

	return $html;
}

function [base]_autoCompleteSuggester( $query ) {
	/*$result = get_terms( array(
		'taxonomy'   => PRODUCT_CATEGORY,
		'hide_empty' => false,
		'name__like' => $query
	) );
	foreach ( $result as $item ) {
		$temp          = array();
		$temp["value"] = $item->term_id;
		$temp["label"] = $item->name;
		$array_list[]  = $temp;
	}*/

	/*$result = get_posts( array(
		'post_type'   => 'product',
		'post_status' => 'publish',
		'name__like'  => $query
	) );
	foreach ( $result as $item ) {
		$temp          = array();
		$temp["value"] = $item->ID;
		$temp["label"] = $item->post_title;
		$array_list[]  = $temp;
	}

	return $array_list;*/

	global $wpdb;
	$post_type    = "page";
	$post_id      = (int) $query;
	$post_results = $wpdb->get_results(
		$wpdb->prepare( "SELECT a.ID AS id, a.post_title AS title FROM {$wpdb->posts} AS a
		WHERE a.post_type ='{$post_type}' AND a.post_status != 'trash' AND ( a.ID = '%d' OR a.post_title LIKE '%%%s%%' )",
			$post_id > 0 ? $post_id : - 1,
			stripslashes( $query ),
			stripslashes( $query ) ),
		ARRAY_A
	);
	$results      = array();
	if ( is_array( $post_results ) && ! empty( $post_results ) ) {
		foreach ( $post_results as $value ) {
			$data          = array();
			$data['value'] = $value['id'];
			$data['label'] = $value['title'];
			$results[]     = $data;
		}
	}

	return $results;
}

function [base]_autoCompleteRender( $query ) {
	/*$value = trim( $query['value'] );
	if ( ! empty( $value ) ) {
		$p             = get_term( $value );
		$data          = array();
		$data['value'] = (int) $value;
		$data['label'] = $p->name;

		return ! empty( $data ) ? $data : false;
	}*/

	$value = trim( $query['value'] );
	if ( ! empty( $value ) ) {
		$p             = get_post( $value );
		$data          = array();
		$data['value'] = (int) $value;
		$data['label'] = $p->post_title;

		return ! empty( $data ) ? $data : false;
	}

	return false;
}