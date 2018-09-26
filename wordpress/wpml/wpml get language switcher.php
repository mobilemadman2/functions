<?php
/**
 * Get language switcher
 * https://wpml.org/documentation/getting-started-guide/language-setup/custom-language-switcher/
 */
function get_language_switcher() {
	// Get raw arrays of languages
	$languages = icl_get_languages( 'skip_missing=0&orderby=custom&order=asc&link_empty_to=str' );

	// Loop
	$active_item = '';
	$list_items  = '<ul class="language-list">';
	foreach ( $languages as $language ) {
		$native_name      = $language['native_name'];
		$url              = $language['url'];
		$active           = $language['active'];
		//$translated_name  = $language['translated_name'];
		//$country_flag_url = $language['country_flag_url'];

		if ( $active ) {
			$active_item = '<span class="active">' . $native_name . '</span>';
		} else {
			$list_items .= '<li><a href="' . $url . '">' . $native_name . '</a></li>';
		}
	}
	$list_items .= '</ul>';

	// Build html
	$lang_switcher = '<div class="language-switcher">';
	$lang_switcher .= $active_item . $list_items;
	$lang_switcher .= '</div>';

	return $lang_switcher;
}