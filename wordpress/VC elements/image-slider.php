<?php

define( 'VC_ICON', get_template_directory_uri() . '/images/vc-logo.png' );
define( 'VC_CATEGORY', __( 'Theme Elements', 'theme' ) );

/***** Element Description: Image Slider *****/
// Element Class
class vcImageSlider extends WPBakeryShortCode {
	// Element Init
	function __construct() {
		add_action( 'init', array( $this, 'vc_imageslider_mapping' ) );
		add_shortcode( 'vc_imageslider', array( $this, 'vc_imageslider_html' ) );
	}

	// Element Mapping
	public function vc_imageslider_mapping() {
		// Stop all if VC is not enabled
		if ( ! defined( 'WPB_VC_VERSION' ) ) {
			return;
		}

		// Map the block with vc_map()
		vc_map(
			array(
				'name'        => __( 'Image Slider', 'theme' ),
				'base'        => 'vc_imageslider',
				'description' => __( 'Custom image slider.', 'theme' ),
				'category'    => VC_CATEGORY,
				'icon'        => VC_ICON,
				'params'      => array(
					array(
						'type'        => 'textfield',
						'holder'      => 'div',
						'class'       => '',
						'heading'     => __( 'Extra class', 'theme' ),
						'param_name'  => 'extra_class',
						'description' => __( '', 'theme' )
					),
					array(
						'type'        => 'attach_images',
						'holder'      => 'div',
						'class'       => '',
						'heading'     => __( 'List of images', 'theme' ),
						'param_name'  => 'list_img',
						'description' => __( 'Select images', 'theme' )
					),
					array(
						'type'        => 'checkbox',
						'holder'      => 'div',
						'class'       => '',
						'heading'     => __( 'Add social icons', 'theme' ),
						'param_name'  => 'has_social_icon',
						'description' => __( '', 'theme' )
					)
				)
			)
		);

	}

	// Element HTML
	public function vc_imageslider_html( $atts ) {
		// Params extraction
		$list_img = array();
		extract( shortcode_atts( array(
			'list_img'        => array(),
			'has_social_icon' => '',
			'extra_class'     => ''
		), $atts ) );
		$list = explode( ",", $list_img );
		$html = "";
		if ( ! empty( $list ) ) {
			$html .= '<div class="image-slider-wrapper ' . $atts['extra_class'] . '" slide-to-show="' . count( $list ) . '">';

			$html .= '<div class="image-slider-inner">';
			$html .= '<div class="slider-for slider-main">';
			foreach ( $list as $img ) {
				$html .= "<div class='slide-item background-parallax-slick' style=\"background-image: url('" . wp_get_attachment_image_src( $img, 'img-large' )[0] . "\")'>";
				$html .= '<img src="' . wp_get_attachment_image_src( $img, "img-large" )[0] . '" alt="' . $img . '"/>';
				$html .= '</div>';
			}
			$html .= '</div>';
			$html .= '<div class="slider-nav slider-thumb">';
			foreach ( $list as $img ) {
				$html .= "<div class='slide-item' style=\"background-image: url('" . wp_get_attachment_image_src( $img, 'thumb-small' )[0] . "\")'>";
				$html .= '<img src="' . wp_get_attachment_image_src( $img, "thumb-small" )[0] . '" alt="' . $img . '"/>';
				$html .= '</div>';
			}
			$html .= '</div>';
			$html .= '</div>';

			if ( $atts['has_social_icon'] ) {
				$html .= '<div class="social-icons-wrapper">';

				$social = get_field( "social_icons", "option" );
				$html   .= '<span class="fb"><a href="' . $social['facebook']['url'] . '" target="_blank">' . $social["facebook"]['icon'] . '</a></span>';
				$html   .= '<span class="ig"><a href="' . $social['instagram']['url'] . '" target="_blank">' . $social["instagram"]['icon'] . '</a></span>';
				$html   .= '<span class="twitter"><a href="' . $social['twitter']['url'] . '" target="_blank">' . $social["twitter"]['icon'] . '</a></span>';

				$html .= '</div>';
			}

			$html .= '</div>';
		}


		return $html;
	}

} // End Element Class
// Element Class Init
new vcImageSlider();