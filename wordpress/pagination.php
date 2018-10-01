<div class="pagination">
	<?php
	global $wp_query;

	$total_pages = $wp_query->max_num_pages;

	if ( $total_pages > 1 ) {
		$current_page = max( 1, get_query_var( 'paged' ) );

		$big = 999999999; // need an unlikely integer

		echo paginate_links( array(
			'base'      => get_pagenum_link( 1 ) . '%_%',
			'format'    => '?paged=%#%',
			'current'   => $current_page,
			'total'     => $total_pages,
			'prev_text' => '<span class="pagination-arrow left"><i class="fa fa-angle-left"></i></span>',
			'next_text' => '<span class="pagination-arrow right"><i class="fa fa-angle-right"></i></span>'
		) );
	}
	?>
</div>