<?php
/**
 * Sample vc_map type values
 * Ref: https://kb.wpbakery.com/docs/inner-api/vc_map/
 */

vc_map( array(
	"name"     => __( "Sample Type Values", "theme" ),
	"base"     => "sample_type_values",
	"category" => VC_CATEGORY,
	"icon"     => VC_ICON,
	"params"   => array(
		array(
			'type'       => 'attach_image',
			'heading'    => __( 'Image', 'theme' ),
			'param_name' => 'img'
		),
		array(
			'type'       => 'dropdown',
			'heading'    => __( 'Style', 'theme' ),
			'param_name' => 'style_class',
			'value'      => array(
				'Style 1'  => 'style_1',
				'Style 2'  => 'style_2',
				'Style 3'  => 'style_3',
				'Has text' => 'has_text'
			),
			'std'        => 'Style 1',
			'holder'     => "i"
		),
		array(
			'type'       => 'textarea',
			'heading'    => __( 'Text', 'theme' ),
			'param_name' => 'text',
			'dependency' => array(
				'element' => 'style_class',
				'value'   => "has_text"
			),
		),
		array(
			'type'       => 'textfield',
			'heading'    => __( 'Extra class', 'theme' ),
			'param_name' => 'extra_class'
		),
		array(
			"type"       => "colorpicker",
			"heading"    => __( "Kleur", "deroeve" ),
			"param_name" => "color",
			"value"      => '#dfdfdf'
		),
	)
) );

add_shortcode( "sample_type_values", "sample_type_values_shortcode" );
function sample_type_values_shortcode( $attr ) {
	$html = '';

	return $html;
}