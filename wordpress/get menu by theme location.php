<?php
/**
 * Extra Menu
 * http://www.wphats.com/get-menu-id-theme-location/
 */
vc_map( array(
	"name"     => __( "Extra Menu", "vandewalle" ),
	"base"     => "twc_extra_menu",
	"category" => VC_CATEGORY,
	"icon"     => VC_ICON,
	"params"   => array()
) );

add_shortcode( "twc_extra_menu", "twc_extra_menu_shortcode" );
function twc_extra_menu_shortcode( $attr, $content ) {
	$theme_location  = 'extra-menu';
	$theme_locations = get_nav_menu_locations();
	$menu_obj        = get_term( $theme_locations[ $theme_location ], 'nav_menu' );
	$menuID          = $menu_obj->term_id;

	$html = '<div class="twc-extra-menu">';
	$html .= '<div class="twc-extra-menu__inner container">';
	$html .= do_shortcode( '[vc_wp_custommenu nav_menu="' . $menuID . '"]' );
	$html .= '</div>';
	$html .= '</div>';

	return $html;
}