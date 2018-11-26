<?php

define('VC_ICON', get_template_directory_uri().'/images/vc-logo.png');
define('VC_CATEGORY', __( 'Theme Elements', 'theme' ));

/***** Element Description: Conversion buttons *****/
// Element Class
class vcConversion extends WPBakeryShortCode {
// Element Init
	function __construct() {
		add_action( 'init', array( $this, 'vc_conversion_mapping' ) );
		add_shortcode( 'vc_conversion', array( $this, 'vc_conversion_html' ) );
	}

// Element Mapping
	public function vc_conversion_mapping() {
// Stop all if VC is not enabled
		if ( ! defined( 'WPB_VC_VERSION' ) ) { return; }

// Get all parent pages
		$args = get_pages(array(
			'sort_order' => 'asc',
			'sort_column' => 'post_title',
			'parent' => 0,
			'post_type' => 'page',
			'post_status' => 'publish'
		));
		$pages = '';
		foreach ( $args as $item ) {
			$pages[ $item->post_title ] = $item->ID;
		}

// Map the block with vc_map()
		vc_map(
			array(
				'name'        => __( 'Conversion Buttons', 'theme' ),
				'base'        => 'vc_conversion',
				'description' => __( 'Visual conversion buttons with services.', 'theme' ),
				'category'    => VC_CATEGORY,
				'icon' => VC_ICON,
				'params'      => array(
					array(
						'type' => 'textfield',
						'holder' => 'h3',
						'class' => 'title-class',
						'heading' => __( 'Title', 'theme' ),
						'param_name' => 'conv_title'
					),
					array(
						'type' => 'textarea',
						'holder' => 'div',
						'class' => '',
						'heading' => __( 'Introduction', 'theme' ),
						'param_name' => 'conv_intro'
					),
					array(
						'type'       => 'dropdown',
						'heading'    => __( 'Conversion buttons', 'theme' ),
						'param_name' => 'page_id',
						'value'      => $pages,
						'description' => __( 'Select page that you want to show its sub-pages as conversion buttons.', 'theme' )
					)
				)
			)
		);

	}

// Element HTML
	public function vc_conversion_html( $atts ) {
// Params extraction
		extract(
			shortcode_atts(
				array(
					'conv_title' => '',
					'conv_intro' => '',
					'page_id'   => ''
				),
				$atts
			)
		);

// Get sub-pages
		$query = new WP_Query( array(
			'post_type'      => 'page',
			'posts_per_page' => - 1,
			'post_parent'    => $page_id,
			'orderby'        => 'menu_order',
			'order'          => 'ASC'
		));

		$html = '';
		$isFirstItem = true;

		if ( $query->have_posts() ) :
			$html .= '<div class="conversion-section">';
			$html .= '<div class="inner">';
			while ( $query->have_posts() ) : $query->the_post();
				$url    = get_the_permalink();
				$title   = get_the_title();
				$excerpt = get_the_excerpt();

				// conversion img's priority: ACF > Featured image > Default banner
				// get image from custom field
				$imgUrl = get_field('diensten_home_image', get_the_ID());
				if ( $imgUrl == '' ) {
					// get image from featured image
					$imgUrl = get_the_post_thumbnail_url(get_the_ID(),'full');
					if($imgUrl == ''){
						// get default banner
						$imgUrl = get_field('default_banner', 'option');
					}

				}
				//$imgUrl = get_field('default_banner', 'option');
				if($isFirstItem){
					$html .= '<div class="conversion-item">';
					$html .= '<div class="item-inner">';

					$html .= '<div class="item-content">';
					$html .= '<h3 class="item-title title_haft_line">' . $conv_title . '</h3>';
					$html .= '<p class="item-excerpt">' . $conv_intro . '</p>';
					$html .= '</div>';

					$html .= '</div>';
					$html .= '</div>';

					$isFirstItem = false;
				}
				$html .= '<div class="conversion-item frame">';
				$html .= '<div class="item-inner">';

				$html .= '<div class="item-img" style="background-image: url(\'' . $imgUrl . '\')">';
				$html .= '<img src="' . $imgUrl . '" alt="' . $title . '"/>';
				$html .= '</div>';

				$html .= '<div class="item-content">';
				$html .= '<h3 class="item-title">' . $title . '</h3>';
				$html .= '<p class="item-excerpt">' . $excerpt . '</p>';
				$html .= '<div class="lees-meer"><a href="' . $url . '" class="btn_green">lees meer</a></div>';
				$html .= '</div>';

				$html .= '</div>';
				$html .= '</div>';


			endwhile;
			$html .= '</div>';
			$html .= '</div>';
		endif;
		wp_reset_postdata();

		return $html;
	}

} // End Element Class
// Element Class Init
new vcConversion();

?>