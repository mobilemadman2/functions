/**
 * Pagination with dropdown
 * @reference: http://jamescollings.co.uk/blog/add-products-per-page-dropdown-woocommerce-product-archive/
 */
/**
 * Get current users preference
 * @return int
 */
function jc_get_products_per_page(){

	global $woocommerce;

	$default = 12;
	$count = $default;
	$options = jc_get_products_per_page_options();

	// capture form data and store in session
	if(isset($_POST['jc-woocommerce-products-per-page'])){

		// set products per page from dropdown
		$products_max = intval($_POST['jc-woocommerce-products-per-page']);
		if($products_max != 0 && $products_max >= -1){

			if(is_user_logged_in()){

				$user_id = get_current_user_id();
				$limit = get_user_meta( $user_id, '_product_per_page', true );

				if(!$limit){
					add_user_meta( $user_id, '_product_per_page', $products_max);
				}else{
					update_user_meta( $user_id, '_product_per_page', $products_max, $limit);
				}
			}

			$woocommerce->session->jc_product_per_page = $products_max;
			return $products_max;
		}
	}

	// load product limit from user meta
	if(is_user_logged_in() && !isset($woocommerce->session->jc_product_per_page)){

		$user_id = get_current_user_id();
		$limit = get_user_meta( $user_id, '_product_per_page', true );

		if(array_key_exists($limit, $options)){
			$woocommerce->session->jc_product_per_page = $limit;
			return $limit;
		}
	}

	// load product limit from session
	if(isset($woocommerce->session->jc_product_per_page)){

		// set products per page from woo session
		$products_max = intval($woocommerce->session->jc_product_per_page);
		if($products_max != 0 && $products_max >= -1){
			return $products_max;
		}
	}

	return $count;
}
add_filter('loop_shop_per_page','jc_get_products_per_page');

/**
 * Fetch list of avaliable options
 * @return array
 */
function jc_get_products_per_page_options(){
	$options = apply_filters( 'jc_products_per_page', array(
		6 => __('6', 'woocommerce'),
		12 => __('12', 'woocommerce'),
		24 => __('24', 'woocommerce'),
		48 => __('48', 'woocommerce'),
		96 => __('96', 'woocommerce'),
		-1 => 'Alle'
	));

	return $options;
}

/**
 * Display dropdown form to change amount of products displayed
 * @return void
 */
function jc_woocommerce_products_per_page(){
	$options = jc_get_products_per_page_options();
	$current_value = jc_get_products_per_page();
	$current_root_url = get_term_link(get_queried_object()->term_id, get_queried_object()->taxonomy);
	?>
	<div class="products-per-page">
		<span>Products Per Page:</span>
		<form action="<?php echo $current_root_url;?>" method="POST" class="woocommerce-products-per-page">
			<select name="jc-woocommerce-products-per-page" onchange="this.form.submit()">
				<?php foreach($options as $value => $name): ?>
					<option value="<?php echo $value; ?>" <?php selected($value, $current_value); ?>><?php echo $name; ?></option>
				<?php endforeach; ?>
			</select>
		</form>
	</div>
	<?php
}
add_action('woocommerce_before_shop_loop', 'jc_woocommerce_products_per_page', 25);