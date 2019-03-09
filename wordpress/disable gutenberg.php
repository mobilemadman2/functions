<?php
/**
 * Disable Gutenberg
 * https://blogaid.net/top-4-ways-to-turn-off-gutenberg-in-wordpress-5-0/
 */
add_filter('use_block_editor_for_post', '__return_false');