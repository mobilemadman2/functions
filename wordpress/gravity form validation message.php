<?php
/**
 * Change Gravity form validation message
 */
function change_message( $message, $form ) {
	return "<div class='validation_error'>Oeps! We konden uw bericht helaas niet versturen. Kijkt u aub even na dat u alle velden correct heeft ingevuld en verstuurt u ons nogmaals uw vraag?</div>";
}
add_filter( 'gform_validation_message', 'change_message', 10, 2 );