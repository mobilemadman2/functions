$query = new WP_Query(array(
			'post_type' => 'projecten',
			'post_status' => 'publish',
			'posts_per_page' => -1
		));