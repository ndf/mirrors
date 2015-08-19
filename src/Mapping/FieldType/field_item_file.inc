<?php

/**
 * @file
 * Mirrors field declaration: field_item_file.
 */

/**
 * Field Declaration: field_item_file.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_field_types_alter() from other modules.
 */
function mirrors_field_types_field_item_file(&$mirrors_field_types) {
  $mirrors_field_types['field_item_file'] = array(
    'views' => array(
      'type' => 'file_url_plain',
    ),
    'feeds' => array(),
  );
}
