<?php
/**
 * @file
 * cm_defaults.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cm_defaults_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cm_defaults_node_info() {
  $items = array(
    'cm_block' => array(
      'name' => t('Block'),
      'base' => 'node_content',
      'description' => t('A small piece of content that can be plugged in as a component of other pages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'cm_page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => t('A static page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'mega_dropdown' => array(
      'name' => t('Mega Dropdown'),
      'base' => 'node_content',
      'description' => t('The body of a Mega Dropdown node can be used as the contents of a dropdown menu.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
