<?php
/**
 * Email Button
 */
vc_map( array(
	"name"     => __( "Email Knoppen", "dekoolputten" ),
	"base"     => "twc_email_button",
	"category" => VC_CATEGORY,
	"icon"     => VC_ICON,
	"params"   => array(
		array(
			"type"        => "textfield",
			"heading"     => __( "Email", "dekoolputten" ),
			"param_name"  => "email",
			"admin_label" => true,
		),
		array(
			"type"        => "textfield",
			"heading"     => __( "Knoppen tekst", "dekoolputten" ),
			"param_name"  => "btn_txt",
			"admin_label" => true,
		),
		array(
			"type"        => "textfield",
			"heading"     => __( "Class naam", "dekoolputten" ),
			"param_name"  => "class",
			"admin_label" => true,
		),
	)
) );

add_shortcode( "twc_email_button", "twc_email_button_shortcode" );
function twc_email_button_shortcode( $attr, $content ) {
	$html    = '';
	$email   = $attr['email'];
	$btn_txt = $attr['btn_txt'];
	$class   = $attr['class'];

	$html .= '<div class="twc-email-button" data-button-text="'.$btn_txt.'" data-class-name="'.$class.'">';
	$html .= $email;
	$html .= '</div>';

	return $html;
}

/**
-- Script --
TWC.emailButton = function () {
$('.twc-email-button').each(function () {
var className = $(this).attr('data-class-name'),
buttonText = $(this).attr('data-button-text'),
$a = $(this).children('a');
$a.addClass(className);
$a.html(buttonText);
});
};
 */