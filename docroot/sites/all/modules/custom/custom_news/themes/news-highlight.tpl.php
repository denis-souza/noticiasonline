<?php

/**
 * @file
 * Default theme implementation to display a news highlight.
 *
 * Available variables:
 * - $news_highlight: the (array) with the following keys:
 * 	 - title: the title of content.
 * 	 - link: the link to content. 
 * 	 - image: url used to access the file.	 
 */

?>

<div id="banner-fade">
	<?php print $news_highlight; ?>
</div>
