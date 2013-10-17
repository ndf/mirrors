<?php

/**
 * @file
 * Property Declarations
 */

/**
 * Property Declaration: boolean.
 *
 * Called directly from mirrors.module.
 * Use hook_property_types_alter() from other modules.
 */
function mirrors_property_types_boolean(&$property_types) {
  $property_types['boolean'] = array(
    'views' => array(
      'type' => 'boolean',
      'settings' => array(
        'format' => 'boolean',
        'custom_on' => '',
        'custom_off' => '',
        'reverse' => 1,
      ),
    ),
    'feeds' => array(),
  );
}
