<?php

/**
 * @file
 * Field Declarations
 */

/**
  * Called directly from mirrors.module
  * User hook_field_types_alter() from other modules
 */
function mirrors_field_types_text_formatted(&$field_types) {
  $field_types['text_formatted'] = array(
    'views' => array(),
    'feeds' => array(),
  );
}
