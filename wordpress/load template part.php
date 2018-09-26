<?php
/**
 * To return template part as variable
 * https://stackoverflow.com/questions/5817726/wordpress-save-get-template-part-to-variable
 *
 * @param $template_name
 * @param null $part_name
 *
 * @return string
 */
function load_template_part( $template_name, $part_name = null ) {
	ob_start();
	get_template_part( $template_name, $part_name );
	$var = ob_get_contents();
	ob_end_clean();

	return $var;
}