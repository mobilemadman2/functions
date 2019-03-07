// get image from custom field
<?php
$imgUrl = get_field( 'diensten_home_image', get_the_ID() );
if ( $imgUrl == '' ) {
	// get image from featured image
	$imgUrl = get_the_post_thumbnail_url( get_the_ID(), 'full' );
	if ( $imgUrl == '' ) {
		// get default banner
		$imgUrl = get_field( 'default_banner', 'option' );
	}

}