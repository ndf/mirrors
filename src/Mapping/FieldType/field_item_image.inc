<?php

/**
 * @file
 * Mirrors field declaration: field_item_image.
 */

/**
 * Field Declaration: field_item_image.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_field_types_alter() from other modules.
 */
function mirrors_field_types_field_item_image(&$mirrors_field_types) {
  $mirrors_field_types['field_item_image'] = array(
    'views' => array(
      'type' => 'image_url',
      'settings' => array(
        'url_type' => '0',
        'image_style' => '',
        'image_link' => '',
      ),
    ),
    'feeds' => array(),
  );
}
