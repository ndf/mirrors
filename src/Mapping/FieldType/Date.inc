<?php

/**
 * @file
 * Mirrors field declaration: date.
 * UNIX timestamp is used as mapper.
 */

/**
 * Field Declaration: date.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_field_types_alter() from other modules.
 */
function mirrors_field_types_date(&$mirrors_field_types) {
  $mirrors_field_types['date'] = array(
    'views' => array(
      'date_format' => 'custom',
      'custom_date_format' => 'U',
    ),
    'feeds' => array(),
  );
}
