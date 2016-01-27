<?php
/**
 * @file
 * cm_location.features.content.inc
 */

/**
 * Implements hook_content_defaults().
 */
function cm_location_content_defaults() {
$content = array();
$content['corporate-headquarters'] = (object)array(
  'exported_path' => 'content/corporate-headquarters',
  'title' => 'Corporate Headquarters',
  'status' => 1,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'location',
  'language' => 'und',
  'created' => 1335487509,
  'comment' => 1,
  'translate' => 0,
  'machine_name' => 'corporate-headquarters',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'This is our home base, where all the magic happens.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>This is our home base, where all the magic happens.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_location_geo' => array(
    'und' => array(
      0 => array(
        'wkt' => 'POINT (-79.9897312 40.4386793)',
        'geo_type' => 'point',
        'lat' => 40.4387,
        'lon' => -79.9897,
        'left' => -79.9897,
        'top' => 40.4387,
        'right' => -79.9897,
        'bottom' => 40.4387,
        'srid' => NULL,
        'accuracy' => NULL,
        'source' => NULL,
      ),
    ),
  ),
  'field_location_location' => array(
    'und' => array(
      0 => array(
        'country' => 'US',
        'administrative_area' => 'PA',
        'sub_administrative_area' => NULL,
        'locality' => 'Pittsburgh',
        'dependent_locality' => NULL,
        'postal_code' => 15219,
        'thoroughfare' => '1034 Fifth Ave.',
        'premise' => '',
        'sub_premise' => NULL,
        'organisation_name' => NULL,
        'name_line' => NULL,
        'first_name' => NULL,
        'last_name' => NULL,
        'data' => NULL,
      ),
    ),
  ),
);
return $content;
}
