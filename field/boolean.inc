<?php

/**
 * @file
 * Mirrors field declaration: boolean.
 * To display boolean correctly the module 'boolean_formatter' is used.
 */

/**
 * Field Declaration: boolean.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_field_types_alter() from other modules.
 */
function mirrors_field_types_boolean(&$mirrors_field_types) {
  $mirrors_field_types['boolean'] = array(
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
