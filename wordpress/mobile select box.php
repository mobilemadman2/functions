<?php
/**
 * Direct to url on select change
 */
$select_box = '<select class="product-category-select hidden" onchange="if (this.value) window.location.href=this.value">';
foreach($cats as $cat){
	$link = 'YOUR URL';
	$name = 'OPTION NAME';
	$selected = get_queried_object()->term_id == $cat->term_id ? 'selected' : '';
	$select_box .= '<option ' . $selected . ' value="' .$link. '">' . $name . '</option>';
}
$select_box .= '</select>';