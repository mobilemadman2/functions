<?php
foreach ($recent_posts as $recent_post) :
	global $post;
	$post = get_post($recent_post['ID']);
	setup_postdata($post);
	ob_start();
	get_template_part( 'partials/content', 'post' );
	$html .= ob_get_clean();
endforeach;