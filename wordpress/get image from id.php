<?php
$imgURL = wp_get_attachment_image_src( $thumbnail_id, 'full' )[0];
$imgTag = wp_get_attachment_image( $thumbnail_id, 'full' );