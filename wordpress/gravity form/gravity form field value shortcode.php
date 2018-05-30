<?php
/**
 * Gravity form shortcode with custom value
 */
$shortcode = '[gravityform id=2 title=false description=false ajax=true field_values="job_title='.$job->title.'"]';
echo do_shortcode($shortcode);