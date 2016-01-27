<?php
/**
 * @file
 * cm_rotator.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cm_rotator_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cm_rotator';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'rotator';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_cm_rotator_item_url']['id'] = 'field_cm_rotator_item_url';
  $handler->display->display_options['fields']['field_cm_rotator_item_url']['table'] = 'field_data_field_cm_rotator_item_url';
  $handler->display->display_options['fields']['field_cm_rotator_item_url']['field'] = 'field_cm_rotator_item_url';
  $handler->display->display_options['fields']['field_cm_rotator_item_url']['label'] = '';
  $handler->display->display_options['fields']['field_cm_rotator_item_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_rotator_item_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_rotator_item_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_cm_rotator_item_url']['type'] = 'plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_cm_rotator_item_image']['id'] = 'field_cm_rotator_item_image';
  $handler->display->display_options['fields']['field_cm_rotator_item_image']['table'] = 'field_data_field_cm_rotator_item_image';
  $handler->display->display_options['fields']['field_cm_rotator_item_image']['field'] = 'field_cm_rotator_item_image';
  $handler->display->display_options['fields']['field_cm_rotator_item_image']['label'] = '';
  $handler->display->display_options['fields']['field_cm_rotator_item_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_cm_rotator_item_image']['alter']['path'] = '[field_cm_rotator_item_url]';
  $handler->display->display_options['fields']['field_cm_rotator_item_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_rotator_item_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_rotator_item_image']['settings'] = array(
    'image_style' => 'cm_rotator_image',
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_class'] = 'flex-caption';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cm_rotator_item' => 'cm_rotator_item',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['cm_rotator'] = $view;

  return $export;
}
