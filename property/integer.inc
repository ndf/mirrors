<?php

/**
 * @file
 * Mirrors property declaration: integer.
 */

/**
 * Property Declaration: integer.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_property_types_alter() from other modules.
 */
function mirrors_property_types_integer(&$mirrors_property_types) {
  $mirrors_property_types['integer'] = array(
    'views' => array(
      'type' => 'number_unformatted',
    ),
    'feeds' => array(),
  );
}
