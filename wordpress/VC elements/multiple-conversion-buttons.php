<?php

define( 'VC_ICON', get_template_directory_uri() . '/images/vc-icon.png' );
define( 'VC_CATEGORY', __( 'ThemeName Elements', 'theme' ) );

/***** Element Description: Multiple Conversation buttons *****/
// Element Class
class vcMultipleConversation extends WPBakeryShortCode {
	// Element Init
	function __construct() {
		add_action( 'init', array( $this, 'vc_multiconver_mapping' ) );
		add_shortcode( 'vc_multiconver', array( $this, 'vc_multiconver_html' ) );
	}

	public function getAllPagesAndTerms() {
		$allPages = '';
		$pages = get_pages( array(
			'post_type'   => 'page',
			'sort_column' => 'menu_order',
			'post_status' => 'publish'
		) );
		foreach ( $pages as $page ) {
			$allPages[ $page->post_title ] = get_the_permalink( $page->ID );
		}

		// loop through all terms
		foreach ( array( 'categorieen-aanbod', 'categorieen-projecten' ) as $tax ) {
			// get the terms of taxonomy
			$terms = get_terms( $tax, [ 'hide_empty' => false ] );
			foreach ( $terms as $term ) {
				$allPages[ $term->name ] = get_term_link( $term );
			}
		}

		return $allPages;
	}

	// Element Mapping
	public function vc_multiconver_mapping() {
		// Stop all if VC is not enabled
		if ( ! defined( 'WPB_VC_VERSION' ) ) {
			return;
		}

		// Get all pages
		$allPages = $this->getAllPagesAndTerms();

		// Map the block with vc_map()
		vc_map(
			array(
				'name'        => __( 'Meerdere conversies', 'theme' ),
				'base'        => 'vc_multiconver',
				'description' => __( 'Toon meerdere conversies.', 'theme' ),
				'category'    => VC_CATEGORY,
				'icon'        => VC_ICON,
				'params'      => array(
					array(
						'type'        => 'dropdown',
						'holder'      => 'span',
						'class'       => '',
						'heading'     => __( 'Selecteer pagina\'s', 'theme' ),
						'param_name'  => 'conversion_url',
						'value'       => $allPages,
						'description' => __( 'Geselecteerde pagina\'s worden weergegeven als conversieknoppen.', 'theme' )
					),
					array(
						'type'        => 'textarea',
						'holder'      => '',
						'class'       => '',
						'heading'     => __( 'Uittreksel', 'theme' ),
						'param_name'  => 'conversion_excerpt',
						'value'       => '',
						'description' => __( '', 'theme' )
					),
					array(
						'type'        => 'attach_image',
						'holder'      => '',
						'class'       => '',
						'heading'     => __( 'Afbeelding', 'theme' ),
						'param_name'  => 'conversion_img',
						'value'       => '',
						'description' => __( '', 'theme' )
					)
				)
			)
		);

	}

	// Element HTML
	public function vc_multiconver_html( $atts ) {
		// Get value from element
		$url     = $atts['conversion_url'];
		$imgUrl  = wp_get_attachment_image_src( $atts['conversion_img'], 'full' )[0];
		$excerpt = $atts['conversion_excerpt'];
		$title   = '';

		// Get all pages
		$allPages = $this->getAllPagesAndTerms();
		if(!isset($url)){$url='getFirstItem';}
		foreach ( $allPages as $key => $val ) {
			if ( $url=='getFirstItem' || $val == $url ) {
				if ( $url=='getFirstItem' ) {$url=$val;}
				$title = $key;
				break;
			}
		}

		// render HTML
		$html = "";

		$html .= '<div class="conversion-item">';
		$html .= '<div class="item-inner">';
		$html .= '<a href="' . $url . '">';

		$html .= '<div class="item-img" style="background-image: url(\'' . $imgUrl . '\')">';
		$html .= '<img src="' . $imgUrl . '" alt="' . $title . '"/>';
		$html .= '</div>';

		$html .= '<div class="item-content">';
		$html .= '<h3 class="item-title">' . $title . '</h3>';
		$html .= '<p class="item-excerpt">' . $excerpt . '</p>';
		$html .= '</div>';

		$html .= '<div class="hover-border-top"></div><div class="hover-border-right"></div>';
		$html .= '<div class="hover-border-bottom"></div><div class="hover-border-left"></div>';
		$html .= '</a>';
		$html .= '</div>';
		$html .= '</div>';

		return $html;
	}

} // End Element Class
// Element Class Init
new vcMultipleConversation();

?>