<?php
/**
 * Place this on top of header.php as it need to be loaded as quick as possible
 */
?>
<div class="vi-loading-layer">
	<?php
	echo wp_get_attachment_image( get_field( "logo", "option" ), 'full', false, array(
		'title' => get_bloginfo( "name" ),
		'alt'   => get_bloginfo( "name" ) . " - " . get_bloginfo( "description" ),
		'class' => 'vi-loading__logo'
	) );
	?>
</div>