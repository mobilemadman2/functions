<?php

/***** Element Description: Multiple Posts *****/
// Element Class
class vcMultiplePost extends WPBakeryShortCode {
	// Element Init
	function __construct() {
		add_action( 'init', array( $this, 'vc_multiplepost_mapping' ) );
		add_shortcode( 'vc_multiplepost', array( $this, 'vc_multiplepost_html' ) );
	}

	// Element Mapping
	public function vc_multiplepost_mapping() {
		// Stop all if VC is not enabled
		if ( ! defined( 'WPB_VC_VERSION' ) ) {
			return;
		}

		// Get all pages
		$allPages = '';
		$query    = new WP_Query( array(
			'post_type'      => 'projecten',
			'post_status'    => 'publish',
			'posts_per_page' => - 1
		) );
		$count    = 1;
		foreach ( $query->posts as $post ) {
			$allPages[ '#' . $count . ' - ' . $post->post_title ] = $post->ID;
			$count ++;
		}

		// Map the block with vc_map()
		vc_map(
			array(
				'name'        => __( 'Items van projecten', 'theme' ),
				'base'        => 'vc_multiplepost',
				'description' => __( 'Toon items van projecten.', 'theme' ),
				'category'    => VC_CATEGORY,
				'icon'        => VC_ICON,
				'admin_enqueue_css' => array( get_template_directory_uri() . '/css/vc-style.css' ),
				'params'      => array(
					array(
						'type'        => 'checkbox',
						'holder'      => 'h3',
						'class'       => '',
						'heading'     => __( 'Selecteer items', 'theme' ),
						'param_name'  => 'multiplepost',
						'value'       => $allPages,
						'description' => __( 'Geselecteerde items worden weergegeven als aanbevolen items.', 'theme' )
					)
				)
			)
		);

	}

	// Element HTML
	public function vc_multiplepost_html( $atts ) {
		$post_list = array();
		foreach ( explode( ',', $atts['multiplepost'] ) as $postID ) {
			$post_list[] = get_post( $postID );
		}

		$terms = get_terms('categorieen-projecten');
		$viewProjectenUrl = get_term_link($terms[0]->slug,'categorieen-projecten');

		$html = '<div class="projecten-section">';
		foreach ( $post_list as $key => $post ) {
			$colThumb  = '';
			$colIntro  = '';
			$permalink = get_permalink( $post->ID );
			$imgUrl    = get_the_post_thumbnail_url( $post->ID, 'full' );
			$title     = $post->post_title;
			$excerpt   = $post->post_excerpt;

			$odd_even = $key % 2 == 0 ? 'odd-item' : 'even-item';
			$html     .= '<div class="projecten-item ' . $odd_even . '"><div class="projecten-inner">';

			$colThumb .= '<div class="col-thumb">';
			$colThumb .= '<a href="' . $permalink . '">';
			$colThumb .= '<div class="item-bg" style="background-image: url(\'' . $imgUrl . '\')">';
			$colThumb .= '<img src="' . $imgUrl . '" alt="'.$title.'">';
			$colThumb .= '</div><span class="search-circle"></span>';
			$colThumb .= '<div class="hover-border-top"></div><div class="hover-border-right"></div>';
			$colThumb .= '<div class="hover-border-bottom"></div><div class="hover-border-left"></div>';
			$colThumb .= '</a></div>';

			$colIntro .= '<div class="col-intro"><div>';
			$colIntro .= '<h3 class="item-title title_line_top">' . $title . '</h3>';
			$colIntro .= '<div class="item-excerpt">' . $excerpt . '</div>';
			$colIntro .= '<a class="btn_yellow" href="' . $permalink . '">'.__('Lees meer','theme').'</a>';
			$colIntro .= '</div></div>';

			if ( $key % 2 == 0 ) {
				$html .= $colThumb . $colIntro;
			} else {
				$html .= $colIntro . $colThumb;
			}

			$html .= '</div></div>';
		}

		$html .= '<div class="loadmore-wrapper"><a class="btn_dark" id="loadmore" href="'.$viewProjectenUrl.'">'.__('BEKIJK ALLES','theme').'</a></div>';
		$html .= '</div>';

		return $html;
	}

} // End Element Class
// Element Class Init
new vcMultiplePost();

?>