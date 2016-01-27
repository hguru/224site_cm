<?php
/**
 * @file
 * cm_media_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cm_media_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function cm_media_gallery_image_default_styles() {
  $styles = array();

  // Exported image style: cm_media_gallery_full_size.
  $styles['cm_media_gallery_full_size'] = array(
    'name' => 'cm_media_gallery_full_size',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1200,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'cm_media_gallery_full_size',
  );

  // Exported image style: cm_media_gallery_square_thumbnail.
  $styles['cm_media_gallery_square_thumbnail'] = array(
    'name' => 'cm_media_gallery_square_thumbnail',
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
          'width' => 90,
          'height' => 90,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'cm_media_gallery_square_thumbnail',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function cm_media_gallery_node_info() {
  $items = array(
    'media_gallery' => array(
      'name' => t('Media Gallery'),
      'base' => 'node_content',
      'description' => t('A gallery of media files, presented as a slideshow.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
