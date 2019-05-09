<?php
/**
 * https://kb.wpbakery.com/docs/developers-how-tos/nested-shortcodes-container/
 */

/**
 * Home slider parent
 */
vc_map( array(
	"name"                    => __( "Home slider", "miasaigon" ),
	"base"                    => "vi_home_slider_parent",
	"category"                => VC_CATEGORY,
	"icon"                    => VC_ICON,
	"as_parent"               => array( 'only' => 'vi_home_slider_child' ),
	"show_settings_on_create" => false,
	"is_container"            => true,
	"js_view"                 => 'VcColumnView',
	"params"                  => array()
) );

add_shortcode( "vi_home_slider_parent", "vi_home_slider_parent_shortcode" );
function vi_home_slider_parent_shortcode( $atts, $content ) {

	$html = '<div class="vi-home-slider">' . do_shortcode( $content ) . '</div>';

	return $html;
}

/**
 * Home slider children
 */
vc_map( array(
	"name"     => __( "Slide", "miasaigon" ),
	"base"     => "vi_home_slider_child",
	"icon"     => VC_ICON,
	"as_child" => array( 'only' => 'vi_home_slider_parent' ),
	"params"   => array(
		array(
			'type'       => 'attach_image',
			'heading'    => __( 'Image', 'miasaigon' ),
			'param_name' => 'image'
		),
		array(
			'type'       => 'textarea_html',
			'heading'    => __( 'Content', 'miasaigon' ),
			'param_name' => 'content',
		),
	)
) );

add_shortcode( "vi_home_slider_child", "vi_home_slider_child_shortcode" );
function vi_home_slider_child_shortcode( $atts, $content = null ) {
	$url = wp_get_attachment_image_src( $atts['image'], 'full' )[0];
	$img = wp_get_attachment_image( $atts['image'], 'full' );

	$html = '';
	$html .= '<div class="vi-home-slider__item">';
	$html .= '<div class="vi-home-slider__item-bg" style="background-image: url(' . $url . ')">';
	$html .= $img;
	$html .= '<div class="vi-home-slider__item-content">' . $content . '</div>';
	$html .= '</div>';
	$html .= '</div>';

	return $html;
}

// Extend Classes
if ( class_exists( 'WPBakeryShortCodesContainer' ) ) {
	class WPBakeryShortCode_vi_home_slider_parent extends WPBakeryShortCodesContainer {
	}
}
if ( class_exists( 'WPBakeryShortCode' ) ) {
	class WPBakeryShortCode_vi_home_slider_child extends WPBakeryShortCode {
	}
}