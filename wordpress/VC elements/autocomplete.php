<?php
/**
 * VC Element with Auto Complete
 */

vc_map( array(
	"name"     => __( "Auto Complete Element", "textdomain" ),
	"base"     => "vc_element_base", // [base]
	"category" => VC_CATEGORY,
	"icon"     => VC_ICON,
	"params"   => array(
		array(
			"type"        => "autocomplete",
			"heading"     => __( "Select", "textdomain" ),
			"param_name"  => 'ids', // [para_name]
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

add_filter( 'vc_autocomplete_[base]_[para_name]_callback', "autoCompleteSuggester", 10, 1 );
add_filter( 'vc_autocomplete_[base]_[para_name]_render', "autoCompleteRender", 10, 1 );

add_shortcode( "[base]", "vc_element_base_shortcode" );

function vc_element_base_shortcode( $attrs ) {
	$html = "";
	$arr  = explode( ",", $attrs['ids'] );
	print_r( $arr );

	return $html;
}

function autoCompleteSuggester( $query ) {
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

	$result = get_posts( array(
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

	return $array_list;
}

function autoCompleteRender( $query ) {
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