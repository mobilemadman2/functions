<?php
define( 'VC_ICON', THEME_URL . '/assets/images/vc-icon.png' );
define( 'VC_CATEGORY', __( 'JONAS Elements', 'jonas' ) );

/*
 * TWC Instagram Feed
 */

vc_map( array(
	"name"     => __( "Instagram Feed", "jonas" ),
	"base"     => "twc_insta_feed",
	"category" => VC_CATEGORY,
	"icon"     => VC_ICON,
	"params"   => array(
		array(
			'type'       => 'textarea_html',
			'heading'    => __( 'Titel', 'jonas' ),
			'param_name' => 'content',
			'holder'     => 'div'
		),
		array(
			'type'       => 'textfield',
			'heading'    => __( 'Instagram shortcode', 'jonas' ),
			'param_name' => 'ig_shortcode'
		)
	)
) );

add_shortcode( "twc_insta_feed", "twc_insta_feed_shortcode" );
function twc_insta_feed_shortcode( $attr, $content ) {
	$html = '<div class="insta-feed">';

	$html .= '<div class="insta-title">' . $content . '</div>';
	$html .= '<div class="insta-content">' . do_shortcode( '[' . $attr['ig_shortcode'] . ']' ) . '</div>';

	$html .= '</div>';

	return $html;
}