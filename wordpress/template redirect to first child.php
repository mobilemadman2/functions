<?php
/*
Template Name: Go to the first child page
*/

$page_child = get_pages("child_of=".$post->ID."&sort_column=menu_order&sort_order=DESC");

if ($page_child) {
	$first_child = $page_child[0];
	wp_redirect(get_permalink($first_child->ID));
}