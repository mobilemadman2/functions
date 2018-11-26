<?php
define( 'VC_ICON', THEME_URL . '/assets/images/vc-icon.png' );
define( 'VC_CATEGORY', __( 'JONAS Elements', 'theme' ) );

/*
 * TWC Instagram Feed
 */

vc_map( array(
	"name"     => __( "Instagram Feed", "theme" ),
	"base"     => "twc_insta_feed",
	"category" => VC_CATEGORY,
	"icon"     => VC_ICON,
	"params"   => array(
		array(
			'type'       => 'textarea',
			'heading'    => __( 'Titel', 'theme' ),
			'param_name' => 'content',
			'holder'     => 'h4'
		),
		array(
			'type'       => 'textfield',
			'heading'    => __( 'Instagram tag', 'theme' ),
			'param_name' => 'ig_tag',
			'holder'     => 'i'
		),
		array(
			'type'       => 'textfield',
			'heading'    => __( 'Instagram shortcode', 'theme' ),
			'param_name' => 'ig_shortcode'
		)
	)
) );

add_shortcode( "twc_insta_feed", "twc_insta_feed_shortcode" );
function twc_insta_feed_shortcode( $attr, $content ) {
	$html = '<div class="insta-feeds">';

	$html = '<div class="insta-feeds-info">';
	$html .= '<div class="insta-title">' . $content . '</div>';
	$html .= '<div class="insta-tag">' . $attr['ig_tag'] . '</div>';
	$html .= '</div>';

	$html .= '<div class="insta-feeds-wrapper">' . do_shortcode( '[' . $attr['ig_shortcode'] . ']' ) . '</div>';

	$html .= '</div>';

	return $html;
}