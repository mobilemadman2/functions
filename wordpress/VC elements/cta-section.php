<?php

define('VC_ICON', get_template_directory_uri().'/images/vc-logo.png');
define('VC_CATEGORY', __( 'Theme Elements', 'theme' ));

/***** Element Description: CTA Section *****/
// Element Class
class vcCTASection extends WPBakeryShortCode {
	// Element Init
	function __construct() {
		add_action( 'init', array( $this, 'vc_ctasection_mapping' ) );
		add_shortcode( 'vc_ctasection', array( $this, 'vc_ctasection_html' ) );
	}

	// Element Mapping
	public function vc_ctasection_mapping() {
		// Stop all if VC is not enabled
		if ( ! defined( 'WPB_VC_VERSION' ) ) { return; }

		// Map the block with vc_map()
		vc_map(
			array(
				'name'        => __( 'CTA Section', 'theme' ),
				'base'        => 'vc_ctasection',
				'description' => __( 'Get CTA section.', 'theme' ),
				'category'    => VC_CATEGORY,
				'icon' => VC_ICON,
				'params'      => array(
					array(
						'type' => 'just_title',
						'holder' => 'h3',
						'class' => 'title-class',
						'param_name' => 'conv_title',
						'value' => __( 'Get CTA section.', 'theme' ),
						'description' => 'You can edit this section in Option page.'
					),
				)
			)
		);

	}

	// Element HTML
	public function vc_ctasection_html() {

		$html = "";
		$cta = get_field('cta_section', 'option');
		$call_to_action = $cta['call_to_action'];
		$text = $cta['short_text'];
		$icon = $call_to_action['icon'];
		$isCustomUrl = $call_to_action['use_custom_url'];
		$url = $isCustomUrl ? $call_to_action['custom_url'] : $call_to_action['page'];
		$target = $call_to_action['new_tab'] ? ' target="_blank"' : '';

		$html .= '<div class="cta-section" data-href="'.$url.'">';
		//$html .= '<div class="cta-section">';

		$html .= '<div class="cta-button"><a href="'.$url.'" '.$target.'>'.$icon.'</a></div>';
		$html .= '<div class="cta-text">'.$text.'</div>';

		$html .= '</div>';
		return $html;
	}

} // End Element Class
// Element Class Init
new vcCTASection();

?>