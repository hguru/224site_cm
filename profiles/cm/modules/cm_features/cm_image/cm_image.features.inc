<?php
/**
 * @file
 * cm_image.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cm_image_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
