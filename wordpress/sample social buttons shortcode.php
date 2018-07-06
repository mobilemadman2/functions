<?php
/**
 * Social buttons [sociaal-knoppen]
 */
function social_buttons_shortcode() {
// Get data
	$data = get_field( 'social_buttons', 'option' );
	if ( isset( $data ) && ! empty( $data ) ) {
// Build html
		$html = '<ul class="social-buttons">';
		foreach ( $data as $item ) {
			$icon  = $item['icon'];
			$title = $item['title'];
			$url   = $item['url'];
			$html  .= '<li><a href="' . $url . '" title="' . $title . '" target="_blank">' . $icon . '</a></li>';
		}
		$html .= '</ul>';

		return $html;
	} else {
		return 'No social button found!';
	}
}

add_shortcode( 'sociaal-knoppen', 'social_buttons_shortcode' );