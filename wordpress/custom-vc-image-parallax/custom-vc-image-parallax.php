<?php
/*
    Plugin Name: Visual Composer Image Parallax
    Plugin URI: https://www.viivue.com/
    Description: Image parallax add-on for visual composer
    Author: Viivue Web Design Company
    Author URI: https://www.viivue.com/
    Version: 1.0.0
    Text Domain: custom_vc_image_parallax
    License: GPL version 2 or later - http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
*/

// If this file is called directly, abort.
if ( ! defined( 'WPINC' ) ) {
    die;
}

if (!defined('ABSPATH')) exit;

/**
 * Function when plugin is activated
 *
 * @param void
 *
 * @return void
 */
function vc_plugin_active(){
    // checking if visual composer is active
    if ( ! is_plugin_active( 'js_composer/js_composer.php' ) ) {
        wp_die( 'Please activate Visual Composer, and try again' );
    }
}
register_activation_hook( __FILE__ , 'vc_plugin_active' );

class Custom_VC_Image_Parallax
{
    /**
     * The single class instance.
     *
     * @var $_instance
     */
    private static $_instance = null;

    /**
     * Main Instance
     * Ensures only one instance of this class exists in memory at any one time.
     */
    public static function instance()
    {
        if (is_null(self::$_instance)) {
            self::$_instance = new self();
            self::$_instance->init();
            self::$_instance->init_hooks();
        }
        return self::$_instance;
    }

    /**
     * Path to the plugin directory
     *
     * @var $plugin_path
     */
    public $plugin_path;

    /**
     * URL to the plugin directory
     *
     * @var $plugin_url
     */
    public $plugin_url;

    /**
     * Custom_VC_Image_Parallax constructor.
     */
    public function __construct()
    {
        /* We do nothing here! */
    }

    /**
     * Init
     */
    public function init()
    {
        $this->plugin_path = plugin_dir_path(__FILE__);
        $this->plugin_url = plugin_dir_url(__FILE__);

        add_action('init', array($this, 'custom_img_parallax_integrate'));

        add_shortcode("image_parallax_add_on", array($this, "vc_custom_image_parallax_shortcode"));
    }

    /**
     * Init hooks
     */
    public function init_hooks()
    {
        add_action( 'init', array( $this, 'register_scripts' ) );

        add_action('wp_enqueue_scripts', array($this, 'enqueue_scripts'));
    }

    /**
     * Register scripts that will be used in the future when portfolio will be printed.
     */
    public function register_scripts() {
        wp_register_script('ofi', Custom_VC_Image_Parallax()->plugin_url . 'assets/js/ofi.min.js', array('jquery'), '1.0.0', true);
        wp_register_script('jarallax', Custom_VC_Image_Parallax()->plugin_url . 'assets/js/jarallax.min.js', array('jquery'), '1.0.0', true);
        wp_register_script('jarallax-init', Custom_VC_Image_Parallax()->plugin_url . 'assets/js/jarallax-init.js', array('jquery'), '1.0.0', true);
        wp_register_style('jarallax', Custom_VC_Image_Parallax()->plugin_url . 'assets/css/jarallax.css', '', '1.0.0');
    }

    /**
     * Enqueue scripts.
     */
    public function enqueue_scripts()
    {
        // add styles to header to fix image jumping.
        wp_enqueue_style('jarallax');
    }

    public function custom_img_parallax_integrate()
    {

        vc_map(array(
            "name" => __("Image Parallax", "vc_custom_img_parallax"),
            "base" => "image_parallax_add_on",
            'icon' => 'icon-wpb-single-image',
            "category" => __("My shortcodes", "vc_custom_img_parallax"),
            "params" => array(
                array(
                    'type' => 'attach_image',
                    'heading' => __( 'Image Parallax', 'vc_custom_img_parallax' ),
                    'param_name' => 'vc_img_parallax',
                    'value' => '',
                    'description' => __( 'Select image from media library.', 'js_composer' ),
                    'dependency' => array(
                        'element' => 'source',
                        'value' => 'media_library',
                    ),
                    'admin_label' => true,
                ),
            )
        ));

    }

    public function vc_custom_image_parallax_shortcode($atts, $content)
    {
        extract( shortcode_atts( array(
            'vc_img_parallax' => 'Image Parallax'
        ), $atts ) );
        $html = '';
        if($vc_img_parallax){
            wp_enqueue_script('ofi');
            wp_enqueue_script('jarallax');
            wp_enqueue_script('jarallax-init');

            $imageSrc = wp_get_attachment_image_src($vc_img_parallax, 'full');
            if( $imageSrc ) {
                $html .= '<div class="jarallax-keep-img">';
                $html .= '<img class="jarallax-img" src="'.$imageSrc[0].'" alt="'.get_the_title($vc_img_parallax).'">';
                $html .= '</div>';
            }
        }
        return $html;
    }

}

/**
 * Function works with the Custom_VC_Image_Parallax class instance
 *
 * @return object Custom_VC_Image_Parallax
 */
function Custom_VC_Image_Parallax() {
    return Custom_VC_Image_Parallax::instance();
}
add_action( 'plugins_loaded', 'Custom_VC_Image_Parallax' );