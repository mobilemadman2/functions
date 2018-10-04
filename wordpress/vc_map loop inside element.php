<?php
/**
 * Conversie secties
 */

vc_map( array(
	"name"             => __( "Conversie secties", "verhelle" ),
	"base"             => "conversion_sections",
	"category"         => VC_CATEGORY,
	"icon"             => VC_ICON,
	'admin_enqueue_js' => array( THEME_URL . '/assets/js/vc_map.js' ),
	"params"           => array(
		array(
			'type'       => 'param_group',
			'value'      => '',
			'param_name' => 'conversion_item',
			'params'     => array(
				array(
					"type"        => "autocomplete",
					"heading"     => __( "Product category", "vfm" ),
					"param_name"  => 'product_cats',
					"settings"    => array(
						'multiple'      => true,
						'sortable'      => true,
						'unique_values' => true,
						'auto_focus'    => true,
						'min_length'    => 1,
						'groups'        => true,
						'delay'         => 500
					),
					'save_always' => true
				),
				array(
					'type'        => 'textarea',
					'heading'     => __( 'Beschrijving', 'verhelle' ),
					'param_name'  => 'description',
					'admin_label' => true
				),
				array(
					'type'       => 'attach_image',
					'heading'    => __( 'Afbeelding', 'verhelle' ),
					'param_name' => 'image'
				)
			),
			'callbacks'  => array(
				'after_add' => 'callBackFunction',
			),
		)
	)
) );

add_shortcode( "conversion_sections", "conversion_sections" );
function conversion_sections( $attr ) {
	extract( shortcode_atts( array(
		'conversion_item' => ''
	), $attr ) );

	$conversion_items = vc_param_group_parse_atts( $attr['conversion_item'] );

	$html = '';
	purinto( $conversion_items );

	return $html;
}