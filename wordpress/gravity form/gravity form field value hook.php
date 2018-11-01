<?php
/**
 * Populate dynamic value to GForm
 * https://docs.gravityforms.com/gform_field_value_parameter_name/
 */
add_filter( 'gform_field_value_page_title', 'populate_page_title' );
function populate_page_title( $value ) {
	return get_the_title();
}