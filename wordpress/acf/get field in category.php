<?php
/**
 * Get custom field in category
 * https://support.advancedcustomfields.com/forums/topic/get-custom-taxonomy-field-value/
 */

$term        = get_term( $cat_id, 'machinebouw-categorie' );
$field_value = get_field( 'category_image', $term->taxonomy . '_' . $term->term_id );