<?php
/**
 * Separator
 */

vc_map( array(
	"name"     => __( "Separator", "deroeve" ),
	"base"     => "twc_separator",
	"category" => VC_CATEGORY,
	"icon"     => VC_ICON,
	"params"   => array(
		array(
			"type"       => "colorpicker",
			"heading"    => __( "Kleur", "deroeve" ),
			"param_name" => "color",
			"value"      => '#dfdfdf'
		),
		array(
			'type'       => 'dropdown',
			'heading'    => __( 'Stijl', 'deroeve' ),
			'param_name' => 'style',
			'value'      => array(
				'Solid'  => 'solid',
				'Dashed' => 'dashed',
				'Dotted' => 'dotted'
			),
			'holder'     => 'i'
		)
	)
) );

add_shortcode( "twc_separator", "twc_separator_shortcode" );
function twc_separator_shortcode( $attrs ) {
	$color       = empty( $attrs['color'] ) ? '#dfdfdf' : $attrs['color'];
	$style       = empty( $attrs['style'] ) ? 'solid' : $attrs['style'];
	$borderColor = "border-color:" . $color . ";";
	$borderStyle = "border-style:" . $style . ";";

	$html = '<div class="twc-separator">';
	$html .= '<div class="twc-separator__line" style="' . $borderColor . $borderStyle . '"></div>';
	$html .= '</div>';

	return $html;
}