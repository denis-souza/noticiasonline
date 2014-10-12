<?php

/**
 * Implements theme_preprocess_html().
 */
function sub_bartik_preprocess_html(&$vars) {
	
	$data = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'author',
      'content' => 'Pepe',
    ),
  );
  
  drupal_add_html_head($data, 'sub_bartik_tag_author');
}
