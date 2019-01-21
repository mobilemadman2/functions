This ACF use to render a Google map in frontend.
Users are able to edit map location, pointer and add custom style.

Here are what you need to apply this ACF:

1. Import this ACF using ACF importer.

2. Copy the google-map.js (which was modified for this ACF) to your theme folder.
   Make sure that you have the ACF Visual Composer Bridge plugin as well.

3. Add this script to your theme with wp_enqueue_script() in functions.php

4. Add this css line to your style.css (take care of the height)
   .acf-map {width: 100%; height: 100%; border: #ccc solid 1px;}

5. Put the code below to your template file.

   <?php
   // Get map info
   $fields   = get_fields( get_the_ID() );
   $map_bg = $fields['map_bg'];
   $location = $map_bg['location'];
   $pointer = $map_bg['pointer'];
   $custom_style = $map_bg['custom_style'];

   // Render map if possible
   if ( ! empty( $location ) ): ?>
      <span class="map-icon-url hidden"><?php echo $pointer; ?></span>
      <span class="map-custom-style hidden"><?php echo $custom_style; ?></span>
      <div class="acf-map">
         <div class="marker" data-lat="<?php echo $location['lat']; ?>"
            data-lng="<?php echo $location['lng']; ?>"></div>
      </div>
   <?php endif; ?>

6. Add the code below to your functions.php, replace XXX with your API key.

   function my_acf_init() {
	acf_update_setting('google_api_key', 'XXX');
   }
   add_action('acf/init', 'my_acf_init');

Now you can use it!