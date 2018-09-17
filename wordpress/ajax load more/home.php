<?php get_header(); ?>

    <div id="primary" class="content-area">
        <main id="content" class="site-content main_content">

            <div class="container">

                <div class="inner-content">
					<?php
					if ( get_field( 'blog_intro_tekst' ) ) {
						?>
                        <div class="extra-top-content">
							<?php echo apply_filters( "the_content", get_field( 'blog_intro_tekst' ) ); ?>
                        </div>
						<?php
					}
					get_template_part( "partials/blog", "categories" );

					if ( have_posts() ):; ?>
                        <div class="list-items">
                            <div class="list-items-inner" data-load-more-container>
								<?php
								while ( have_posts() ) {
									the_post();
									get_template_part( 'partials/content', 'post' );
								}
								?>
                            </div>
                        </div>

						<?php
						global $wp_query;
						$queried_object = get_queried_object();
						$term_id        = $queried_object->term_id;
						if ( $wp_query->max_num_pages > 1 ):
							?>
                            <div class="load-more-wrapper">
								<?php
								if ( ! $term_id ) {
									$term_id = 0;
								}
								?>
                                <a class="load-more-btn btn_bg_white" href="#" data-category="<?php echo $term_id; ?>"
                                   data-post-type="post"
                                   data-current="2"
                                   data-post-per-page="10"><span><?php echo __( 'Show older stories', 'campine' ); ?></span></a>
                            </div>
						<?php
						endif;
						echo apply_filters( "the_content", get_field( 'blog_cta_section' ) );
					else:;
						?>
                        <div class="no-item"><h3><?php _e( "Niet gevonden", "campine" ); ?></h3></div>
					<?php endif; ?>
                </div>

            </div>

        </main>
    </div>

<?php get_footer(); ?>