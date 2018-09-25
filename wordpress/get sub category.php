<?php
// Get sub categories by parent id
$parent_id = 0;
$cats      = get_categories( array(
	'taxonomy' => 'product_cat',
	'orderby'  => 'name',
	'order'    => 'ASC',
	'parent'   => $parent_id
) );