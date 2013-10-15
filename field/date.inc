<?php

/**
 * @file
 * Field Declarations
 */

/**
  * Called directly from mirrors.module
  * User hook_field_types_alter() from other modules
 */
function mirrors_field_types_date(&$field_types) {
  $field_types['date'] = array(
    'views' => array(
      'date_format' => 'custom',
      'custom_date_format' => 'U',
    ),
    'feeds' => array(),
  );
}
