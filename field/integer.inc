<?php

/**
 * @file
 * Field Declarations
 */

/**
  * Called directly from mirrors.module
  * User hook_field_types_alter() from other modules
 */
function mirrors_field_types_integer(&$field_types) {
  $field_types['integer'] = array(
    'views' => array(
      'type' => 'number_unformatted',
    ),
    'feeds' => array(),
  );
}
