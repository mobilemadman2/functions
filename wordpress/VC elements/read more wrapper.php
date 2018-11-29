<?php
/*
 * TWC Read More Begin
 */

vc_map( array(
	"name"     => __( "Lees Meer Begin", "paul" ),
	"base"     => "twc_read_more_begin",
	"category" => VC_CATEGORY,
	"icon"     => VC_ICON,
	"params"   => array()
) );

add_shortcode( "twc_read_more_begin", "twc_read_more_begin_shortcode" );
function twc_read_more_begin_shortcode( $attr ) {
	$html = '<div class="read-more-begin"></div>';

	return $html;
}

/*
 * TWC Read More End
 */

vc_map( array(
	"name"     => __( "Lees Meer End", "paul" ),
	"base"     => "twc_read_more_end",
	"category" => VC_CATEGORY,
	"icon"     => VC_ICON,
	"params"   => array()
) );

add_shortcode( "twc_read_more_end", "twc_read_more_end_shortcode" );
function twc_read_more_end_shortcode( $attr ) {
	$html = '<div class="read-more-end">';
	$html .= '<a class="btn_right_arrow_bg_red read-more-button" href="#">Lees Meer</a>';
	$html .= '</div>';

	return $html;
}