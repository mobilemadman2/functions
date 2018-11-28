<?php
/**
 * Facebook feed
 */

vc_map( array(
	"name"     => __( "Facebook Feeds", "sumherb" ),
	"base"     => "vii_fb_feed",
	"category" => VC_CATEGORY,
	"icon"     => VC_ICON,
	"params"   => array(
		array(
			'type'       => 'textfield',
			'heading'    => __( 'Facebook page URL', 'sumherb' ),
			'param_name' => 'fb_link',
			'holder'     => 'i'
		)
	)
) );

add_shortcode( "vii_fb_feed", "vii_fb_feed_shortcode" );
function vii_fb_feed_shortcode( $attr ) {
	$html = '<div class="vii-facebook-feed">';

	$html .= '<div class="fb-page" data-href="' . $attr['fb_link'] . '" data-tabs="timeline" data-width="450"
     data-small-header="false" data-adapt-container-width="false" data-hide-cover="false" data-show-facepile="true">';
	$html .= '<blockquote cite="' . $attr['fb_link'] . '" class="fb-xfbml-parse-ignore">';
	$html .= '<a href="' . $attr['fb_link'] . '">Sumherb Pty Ltd</a>';
	$html .= '</blockquote>';
	$html .= '</div>';

	$html .= '</div>';

	return $html;
}