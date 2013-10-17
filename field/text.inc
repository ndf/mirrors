<?php

/**
 * @file
 * Field Declarations
 */

/**
 * Field Declaration: text.
 *
 * Called directly from mirrors.module.
 * Use hook_field_types_alter() from other modules.
 */
function mirrors_field_types_text(&$field_types) {
  $field_types['text'] = array(
    'views' => array(),
    'feeds' => array(),
  );
}
