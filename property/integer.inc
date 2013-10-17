<?php

/**
 * @file
 * Property Declarations
 */

/**
 * Property Declaration: integer.
 *
 * Called directly from mirrors.module.
 * Use hook_property_types_alter() from other modules.
 */
function mirrors_property_types_integer(&$property_types) {
  $property_types['integer'] = array(
    'views' => array(
      'type' => 'number_unformatted',
    ),
    'feeds' => array(),
  );
}
