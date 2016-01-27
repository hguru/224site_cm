<?php
/**
 * @file
 * cm_rotator.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cm_rotator_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cm_rotator_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function cm_rotator_image_default_styles() {
  $styles = array();

  // Exported image style: cm_rotator_image.
  $styles['cm_rotator_image'] = array(
    'name' => 'cm_rotator_image',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'cm_rotator_image',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function cm_rotator_node_info() {
  $items = array(
    'cm_rotator_item' => array(
      'name' => t('Rotator Item'),
      'base' => 'node_content',
      'description' => t('One of a series of items to be displayed in a Rotator.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
