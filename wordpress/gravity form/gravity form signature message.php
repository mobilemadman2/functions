<?php
/**
 * Gravity form: add an option to hide label
 */
add_filter( 'gform_enable_field_label_visibility_settings', '__return_true' );

/**
 * Append signature to message
 */
add_filter( 'gform_notification', 'my_gform_notification_signature', 10, 3 );
function my_gform_notification_signature( $notification, $form, $entry ) {
	// append a signature to the existing notification
	// message with .=
	$notification['message'] .= get_field( 'form_signature', 'option' );

	return $notification;
}