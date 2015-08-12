<?php

/**
 * @file
 * Mirrors field declaration: struct. (date)
 */

/**
 * Field Declaration: struct.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_field_types_alter() from other modules.
 */
function mirrors_field_types_struct(&$mirrors_field_types) {
  $mirrors_field_types['struct'] = array(
    'views' => array(
      'type' => 'date_plain',
      'settings' => array(
        'format_type' => 'long',
        'fromto' => 'both',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
      )
    ),
    'feeds' => array(),
  );
}
