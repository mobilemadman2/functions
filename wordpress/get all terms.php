/**** get all terms name and link ****/
function get_all_terms($tax_list){
	$terms_list = array();
	// loop through all terms
	foreach ($tax_list as $tax){
		// get the terms of taxonomy
		$terms = get_terms( $tax, [ 'hide_empty' => false ]);
		foreach( $terms as $term ) {
			$terms_list[$term->name] = get_term_link( $term );
		}
	}
	return $terms_list;
}

- input: array( 'taxonomy-slug', 'taxonomy-slug' );
- output: array( 'name'=>'link', 'name'=>'link' );