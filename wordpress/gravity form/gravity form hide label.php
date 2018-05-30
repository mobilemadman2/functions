<?php
/**
* Gravity form: add an option to hide label
* Ref: https://gravitywiz.com/how-to-hide-gravity-form-field-labels-when-using-placeholders/
*/
add_filter( 'gform_enable_field_label_visibility_settings', '__return_true' );