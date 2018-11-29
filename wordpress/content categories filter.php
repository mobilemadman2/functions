<?php
/**
 * Categories filter in page for post and category.php
 */
$categories = get_categories(array(
    'hide_empty' => false
));

if(count($categories) > 0){
    ?>
    <div class="list-categories">
        <div class="list-category-title">
            <?= __('Category', 'campine'); ?>
        </div>
        <div class="list-categories-content">
            <ul class="list-categories-items">
                <li class="list-category-item">
                    <?php
                    $blog_id = get_option('page_for_posts', true);
                    ?>
                    <a href="<?= esc_url(get_the_permalink($blog_id)); ?>"
                       title="<?= __('All', 'campine'); ?>"
                       class="<?php if(is_home()) echo 'active'; ?> btn_bg_white" data-filter="*"><?= __('All', 'campine'); ?></a>
                </li>
                <?php
                $current_category = get_category( get_query_var( 'cat' ) );
                $current_category_id = $current_category->term_id;
                foreach( $categories as $category ) {
                    $check = false;
                    if($category->term_id == $current_category_id){
                        $check = true;
                    }
                    ?>
                    <li class="list-category-item">
                        <a href="<?= esc_url(get_category_link( $category->term_id )); ?>"
                           title="<?= $category->name; ?>"
                           class="<?php if($check) echo 'active'; ?> btn_bg_white" data-filter=".<?= $category->slug; ?>"><?= esc_html( $category->name ); ?></a>
                    </li>
                    <?php
                }
                ?>
            </ul>
            <div class="mobile-select">
                <select class="wide nice-select list-categories-items" onchange="this.options[this.selectedIndex].value && (window.location = this.options[this.selectedIndex].value);">
                    <?php
                    $blog_id = get_option('page_for_posts', true);
                    ?>
                    <option class="list-category-item" value="<?= esc_url(get_the_permalink($blog_id)); ?>" <?php if(is_home()) echo 'selected'; ?>>
                        <?= __('All', 'campine'); ?>
                    </option>
                    <?php
                    foreach( $categories as $category ) {
                        $selected = '';
                        if($category->term_id == $current_category_id){
                            $selected = 'selected';
                        }
                        ?>
                        <option class="list-category-item" value="<?= get_term_link($category->term_id); ?>" <?php if($selected) echo 'selected' ?>>
                            <?= $category->name; ?>
                        </option>
                        <?php
                    }
                    ?>
                </select>
            </div>
        </div>
    </div>
    <?php
}