<?php

/**
 * @file: Defines the callback function for the services resource for regions_server.
 */

 /**
  * Callback for regions_server resource.
  * 
  * @param $path
  *   String. The path of the page to return region data from.
  * @param $regions
  *   Array (optional). A list of regions to return.
  * 
  * @return
  *   Array. A keyed array of regions and their content.
  */
function _region_resource_retrieve($path, $regions = array()) {
  if($path == "<front>") {
    $path = variable_get('site_frontpage', 'node');
  }

  $page = menu_execute_active_handler($path, FALSE);
  
  if($page == MENU_NOT_FOUND || $page == MENU_ACCESS_DENIED || $page == MENU_SITE_OFFLINE) {
    return array('Error' => '404');
  }
  
  unset($_REQUEST['destination'], $_GET['q'], $_GET['path'], $_GET['regions']);
  
  // Allow menu callbacks to return strings or arbitrary arrays to render.
  // If the array returned is not of #type page directly, we need to fill
  // in the page with defaults.
  if (is_string($page) || (is_array($page) && (!isset($page['#type']) || ($page['#type'] != 'page')))) {
    drupal_set_page_content($page);
    $page = element_info('page');
  }

  // Modules can add elements to $page as needed in hook_page_build().
  foreach (module_implements('page_build') as $module) {
    $function = $module . '_page_build';
    $function($page);
  }
  // Modules alter the $page as needed. Blocks are populated into regions like
  // 'sidebar_first', 'footer', etc.
  drupal_alter('page', $page);

  $regiondata = array();

  if( !empty($regions)) {
    foreach($regions as $region) {
     if(isset($page[$region])) {
       $regiondata[$region] = drupal_render($page[$region]);
     }
    }
    
  }
  else {
    foreach($page as $section => $element) {
     $regiondata[$section] = drupal_render($element);
    }
  }

  return $regiondata;
}
