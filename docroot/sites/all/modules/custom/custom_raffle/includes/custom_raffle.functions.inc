<?php

/**
 * @file
 * File with the callback functions.
 */

/**
 * Private function. Search all records in the raffle table.
 * @param  array  $header Contains header to sort.
 * @param  int    $limit  Limit value for the query.
 * @return object         Object with the results of the database.
 */
function _custom_raffle_select_people($header, $limit) {
	
  // See https://api.drupal.org/api/drupal/includes!database!database.inc/7
	return db_select('raffle', 'ra')
    ->fields('ra')
    ->extend('PagerDefault')
    ->extend('TableSort')
    ->orderByHeader($header)
    ->limit($limit)
    ->execute()
    ->fetchAll();
}

/**
 * Function callback to menu.
 * @return form page.
 */
function custom_raffle_table_list() {
  
  $output = '';
 
  // Table header.
  $header = array(
  	'name' => array('data' => t('Name'), 'field' => 'name'),
  	'email' => array('data' => t('Email'), 'field' => 'email'),
  	'prize' => array('data' => t('Prize'), 'field' => 'prize'),
  	'date' => array('data' => t('Date'), 'field' => 'date'),
  );
  
  // Search results in the database
  $results = _custom_raffle_select_people($header, 3);

  // Iterate over the result to set the table rows.
  foreach ($results as $key => $data) {
    $rows[] = array($data->name, $data->email, $data->prize, $data->date);
  }

  // Create the table and pagination.
  $output = theme_table(
    array(
      'header' => $header,
      'rows' => $rows,
      'attributes' => array(),
      'sticky' => TRUE,
      'caption' => '',
      'colgroups' => array(),
      'empty' => t("No results")
    )
  ).theme('pager');

  return $output;
}