<?php

/**
 * @file
 * Mirrors property declaration: date.
 * UNIX timestamp is used as mapper.
 */

/**
 * Property Declaration: date.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_property_types_alter() from other modules.
 */
function mirrors_property_types_date(&$mirrors_property_types) {
  $mirrors_property_types['date'] = array(
    'views' => array(
      'date_format' => 'custom',
      'custom_date_format' => 'U',
    ),
    'feeds' => array(),
  );
}
