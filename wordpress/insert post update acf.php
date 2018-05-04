<?php
/**
 * Insert post and update ACF
 * https://developer.wordpress.org/reference/functions/wp_insert_post
 * https://www.advancedcustomfields.com/resources/update_field/
 */

// vars
$my_post = array(
	'post_title'	=> 'My post',
	'post_type'		=> 'post',
	'post_status'	=> 'publish'
);


// insert the post into the database
$post_id = wp_insert_post( $my_post );


// save a basic text value
$field_key = "field_123456";
$value = "some new string";
update_field( $field_key, $value, $post_id );


// save a checkbox or select value
$field_key = "field_1234567";
$value = array("red", "blue", "yellow");
update_field( $field_key, $value, $post_id );


// save a repeater field value
$field_key = "field_12345678";
$value = array(
	array(
		"sub_field_1"	=> "Foo",
		"sub_field_2"	=> "Bar"
	)
);
update_field( $field_key, $value, $post_id );


// save a flexible content field value
$field_key = "field_123456789";
$value = array(
	array( "sub_field_1" => "Foo1", "sub_field_2" => "Bar1", "acf_fc_layout" => "layout_1_name" ),
	array( "sub_field_x" => "Foo2", "sub_field_y" => "Bar2", "acf_fc_layout" => "layout_2_name" )
);
update_field( $field_key, $value, $post_id );

/**
 * My note: to get field's key use get_post_meta()
 * https://developer.wordpress.org/reference/functions/get_post_meta/
 */