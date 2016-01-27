<?php
/**
 * @file
 * cm_panel.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cm_panel_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_manager_node_view_disabled';
  $strongarm->value = FALSE;
  $export['page_manager_node_view_disabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_cm_panel';
  $strongarm->value = array(
    'status' => 1,
    'default' => 1,
    'choice' => 1,
  );
  $export['panelizer_defaults_node_cm_panel'] = $strongarm;

  return $export;
}
