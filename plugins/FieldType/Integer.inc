<?php

/**
 * @file
 * Mirrors field declaration: integer.
 */

/**
 * Field Declaration: integer.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_field_types_alter() from other modules.
 */
function mirrors_field_types_integer(&$mirrors_field_types) {
  $mirrors_field_types['integer'] = array(
    'views' => array(
      'type' => 'number_unformatted',
    ),
    'feeds' => array(),
  );
}
