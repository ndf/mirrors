<?php

/**
 * @file
 * Field Declarations
 */

/**
  * Called directly from mirrors.module
  * User hook_field_types_alter() from other modules
 */
function mirrors_field_types_boolean(&$field_types) {
  $field_types['boolean'] = array(
    'views' => array(
      'type' => 'boolean_yes_no',
      'settings' => array(
        'format' => 'boolean',
        'custom_on' => '',
        'custom_off' => '',
        'reverse' => 0,
      ),
    ),
    'feeds' => array(),
  );
}
