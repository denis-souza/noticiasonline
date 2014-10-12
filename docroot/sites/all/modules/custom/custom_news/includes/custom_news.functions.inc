<?php

/**
 * @file
 * File with the callback functions.
 */

/**
 * Implements function callback.
 * @return array An array of objects from the database records.
 */
function _custom_news_select_content() {

  $query = db_select('node', 'n');
	$query->join('field_data_field_is_highlight', 'hf', 'n.nid = hf.entity_id');
	$query->join('field_data_field_image_highlight', 'ih', 'n.nid = ih.entity_id');
	$query
  	->fields('n', array('nid', 'title'))
  	->condition('n.type', 'news')
  	->condition('n.status', '1')
  	->condition('hf.field_is_highlight_value', '1', '=')
  	->addField('ih', 'field_image_highlight_fid', 'fid');
  	
  return $query->execute()->fetchAll();
}

/**
 * function to get the contents of the block.
 * @return string String with html
 */
function custom_news_format_highlight_content() {

	$content = array();
  $results = _custom_news_select_content();
  foreach ($results as $key => $result) {
      
    $file = file_load($result->fid);
    $conf_image = array(
      'path' => $file->uri,
      'alt' => $result->title,
      'title' => $result->title,
      'width' => $file->image_dimensions['width'],
      'height' => $file->image_dimensions['height'],
      'attributes' => array('class' => 'image'),
    );
    $image = theme('image', $conf_image);
	 
    // see https://www.drupal.org/node/930760
    // https://api.drupal.org/api/examples/render_example!render_example.module/function/render_example_arrays/7
		$link_render = array(
      '#theme' => 'link',
      '#text' => $image,
      '#path' => "node/" . $result->nid,
      '#options' => array(
        'attributes' => array(),
        'html' => TRUE,
      ),
    );

    $items[] = array(
    	'data' => render($link_render),
    	'id' => 'element-' . $result->nid,
    	'class' => array('element-list'),
    );
	}
	
	$content = theme('item_list', array(
  	'items' => $items, 
  	'title' => '', 
  	'type' => 'ul', 
  	'attributes' => array(
  		'class' => array('highlight-list', 'bjqs')
  	),
  ));
  
	return $content;
}