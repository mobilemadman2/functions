// Get all categories by taxonomy slug
$args = get_categories( array(
		'taxonomy' => 'product_cat',
		'orderby' => 'name',
		'order' => 'ASC',
		'parent'  => 0
	) );