<?php

/**
 * @file
 * Property Declarations
 */

/**
  * Called directly from mirrors.module
  * User hook_property_types_alter() from other modules
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
