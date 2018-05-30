<?php
/**
 * Change Gravity form submit button
 */
function form_submit_button( $button, $form ) {
	return "<button id='gform_submit_button_{$form['id']}'><span class='btn_black'>{$form['button']['text']}</span></button>";
}
add_filter( 'gform_submit_button', 'form_submit_button', 10, 2 );