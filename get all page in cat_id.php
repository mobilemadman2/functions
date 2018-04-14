// Get all page in cat_id
		$query = new WP_Query( array(
			'post_type'      => 'page',
			'tax_query'     => array(
				array(
					'taxonomy'  => 'category',
					'field'     => 'id',
					'terms'     => $cat_id,
				),
			),
			'posts_per_page' => 3,
			'orderby'        => 'menu_order',
			'order'          => 'ASC'
		) );