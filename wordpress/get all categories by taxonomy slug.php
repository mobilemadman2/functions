<?php
// Get all product categories
$cats = get_categories( array(
	'taxonomy' => 'product_cat',
	'orderby'  => 'name',
	'order'    => 'ASC',
	'parent'   => 0
) );