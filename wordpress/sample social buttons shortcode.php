<?php
/**
 * Social buttons [sociaal-knoppen]
 */
function social_buttons_shortcode() {
	$data = get_field( 'social_links', 'option' );
	if ( isset( $data ) && ! empty( $data ) ) {
		$html = '<div class="social-buttons">';
		foreach ( $data as $item ) {
			$icon  = $item['social_icon'];
			$title = $item['social_text'];
			$url   = $item['social_url'];
			$html  .= '<a class="social-buttons__link" href="' . $url . '" title="' . $title . '" target="_blank">' . $icon . '</a>';
		}
		$html .= '</div>';

		return $html;
	}
}

add_shortcode( 'sociale-knoppen', 'social_buttons_shortcode' );