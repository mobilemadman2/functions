<?php
$cta_list     = get_field( "cta_button", "option" );
$cta_position = get_field( 'cta_position', 'option' );
$cta_active   = get_field( "cta_active", "option" );
if ( ! empty( $cta_list ) && ! empty( $cta_position ) && $cta_active ):
	$horizontal = $cta_position['horizontal'] . ':0;';
	$vertical = 'top:' . $cta_position['vertical'] . '%;';
	?>
	<div id="cta-buttons" style="<?= $horizontal . $vertical ?>">
		<?php foreach ( $cta_list as $item ):
			$target = $item['new_tab'] ? "_blank" : "";
			?>
			<div class="cta-item">
				<a class="cta-item__link" href="<?= $item['url'] ?>" target="<?= $target ?>"
				   title="<?= $item['hover'] ?>"><?= $item['icon'] ?></a>
			</div>
		<?php endforeach; ?>
	</div>
<?php endif; ?>