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
					'type'       => 'attach_image',
					'heading'    => __( 'Image', 'theme' ),
					'param_name' => 'img'
				),
				array(
					'type'       => 'textfield',
					'heading'    => __( 'Extra class', 'theme' ),
					'param_name' => 'extra_class'
				),
			)
		)
	)
) );
add_shortcode( "vc_element_base", "vc_element_base_shortcode" );

function vc_element_base_shortcode( $attrs ) {
	$html        = "";
	$group_items = vc_param_group_parse_atts( $attrs['group'] );
	print_r( $group_items );

	return $html;
}