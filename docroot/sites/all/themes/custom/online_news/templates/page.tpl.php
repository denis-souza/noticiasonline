<?php

/**
 * @file
 * Online news theme implementation to display a single Drupal page.
 *
 * * Regions:
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 */

?>

<div id="page">

	<?php if (!empty($page['header'])): ?>
		<div id="header">
			<?php print render($page['header']); ?>
		</div>
	<?php endif; ?>

	<?php if ($main_menu): ?>
	  <div id="main-menu" class="navigation">
	    <?php print theme('links__system_main_menu', array(
	      'links' => $main_menu,
	      'attributes' => array(
	        'id' => 'main-menu-links',
	        'class' => array('links', 'clearfix'),
	      ),
	      'heading' => array(
	        'text' => t('Main menu'),
	        'level' => 'h2',
	        'class' => array('element-invisible'),
	      ),
	    )); ?>
	  </div> 
	<?php endif; ?>
	
	<?php if (!empty($page['highlighted'])): ?>
		<div id="highlighted">
			<?php print render($page['highlighted']); ?>
		</div>
	<?php endif; ?>
	
	<?php if (!empty($page['featured'])): ?>
		<div id="featured">
			<?php print render($page['featured']); ?>
		</div>
	<?php endif; ?>
	
	<?php if (!empty($page['content'])): ?>
		<div id="content">
			<?php print render($page['content']); ?>
		</div>
	<?php endif; ?>
	
	<?php if (!empty($page['footer'])): ?>
		<div id="footer">
			<?php print render($page['footer']); ?>
		</div>
	<?php endif; ?>

</div>