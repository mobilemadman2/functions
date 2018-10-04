<?php
$featured_products = new WP_Query( array(
	'post_type'  => 'product',
	'tax_query'  => array(
		array(
			'taxonomy' => 'product-categorie',
			'field'    => 'id',
			'terms'    => $current_term->term_id,
		),
	),
	'meta_query' => array(
		array(
			'key'     => 'is_featured_product', // custom field name
			'value'   => true,
			'type'    => 'BOOL',
			'compare' => '='
		)
	),
	'orderby'    => 'menu_order',
	'order'      => 'ASC'
) );