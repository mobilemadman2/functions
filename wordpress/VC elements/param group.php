<?php
/**
 * VC Element with Group has Auto Complete
 */

vc_map( array(
	"name"     => __( "Group Auto Complete Element", "textdomain" ),
	"base"     => "vc_element_base", // [base]
	"category" => VC_CATEGORY,
	"icon"     => VC_ICON,
	"params"   => array(
		array(
			'type'       => 'param_group',
			'value'      => '',
			"heading"    => __( "Group", "textdomain" ),
			'param_name' => 'group',
			'params'     => array(
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
		)
	)
) );

add_filter( 'vc_autocomplete_[base]_[para_name]_[para_name]_callback', "[base]_autoCompleteSuggester", 10, 1 );
add_filter( 'vc_autocomplete_[base]_[para_name]_[para_name]_render', "[base]_autoCompleteRender", 10, 1 );

add_shortcode( "[base]", "vc_element_base_shortcode" );

function vc_element_base_shortcode( $attrs ) {
	$html = "";
	$group_items    = vc_param_group_parse_atts( $attrs['group'] );
	print_r( $group_items );

	return $html;
}

function autoCompleteSuggester( $query ) {

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