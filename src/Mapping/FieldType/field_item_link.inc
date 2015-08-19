<?php

/**
 * @file
 * Mirrors field declaration: field_item_link.
 */

/**
 * Field Declaration: field_item_link.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_field_types_alter() from other modules.
 */
function mirrors_field_types_field_item_link(&$mirrors_field_types) {
  $mirrors_field_types['field_item_link'] = array(
    'views' => array(
      'type' => 'link_absolute',
    ),
    'feeds' => array(),
  );
}
