<?php
/**
 * Get language switcher
 * https://wpml.org/documentation/getting-started-guide/language-setup/custom-language-switcher/
 */
function get_language_switcher() {
	// List of languages
	$languages = icl_get_languages( 'skip_missing=0&orderby=custom&order=asc&link_empty_to=str' );

	foreach ( $languages as $language ) {
		echo $language;
	}
}