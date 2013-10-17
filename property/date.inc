<?php

/**
 * @file
 * Property Declarations
 */

/**
 * Property Declaration: date.
 *
 * Called directly from mirrors.module.
 * Use hook_property_types_alter() from other modules.
 */
function mirrors_property_types_date(&$property_types) {
  $property_types['date'] = array(
    'views' => array(
      'date_format' => 'custom',
      'custom_date_format' => 'U',
    ),
    'feeds' => array(),
  );
}
