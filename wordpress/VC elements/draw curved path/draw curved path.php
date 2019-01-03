<?php
/**
 * VI Curved Path
 * Define by a wrapper class ".vi-path-wrapper", this element provides needed data
 * Add starting point and ending point using these classes ".vi-path-begin", ".vi-path-end"
 * And some css for the line
 */
vc_map( array(
	"name"     => __( "Curved Path", "theme" ),
	"base"     => "vi_curved_path",
	"category" => VC_CATEGORY,
	"icon"     => VC_ICON,
	"params"   => array(
		array(
			'type'        => 'textfield',
			'heading'     => __( 'Number of Curved Points', 'theme' ),
			'param_name'  => 'curved_count',
			"description" => "Place this element inside \".vi-path-wrapper\", then add these classes \".vi-path-begin\", \".vi-path-end\" to the relevant elements.",
		),
		array(
			'type'       => 'dropdown',
			'heading'    => __( 'Start from', 'theme' ),
			'param_name' => 'start_from',
			'value'      => array(
				'Left side'  => 'from_left',
				'Right side' => 'from_right'
			)
		)
	)
) );

add_shortcode( "vi_curved_path", "vi_curved_path_shortcode" );
function vi_curved_path_shortcode( $attr ) {
	$curved_count = $attr['curved_count'];
	$start_from   = $attr['start_from'];
	$html         = '';

	if ( ! empty( $curved_count ) ) {
		$html .= '<div class="vi-curved-path-data hidden" data-curved-points="' . $curved_count . '" data-start-from="' . $start_from . '"></div>';
	}

	return $html;
}