<?php
/**
 * Get current page url
 * https://wordpress.stackexchange.com/questions/274569/how-to-get-url-of-current-page-displayed
 */
global $wp;
var_dump( home_url( $wp->request ) );