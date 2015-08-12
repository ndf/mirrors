<?php

/**
 * @file
 * Mirrors field declaration: text_formatted.
 */

/**
 * Field Declaration: text_formatted.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_field_types_alter() from other modules.
 */
function mirrors_field_types_text_formatted(&$mirrors_field_types) {
  $mirrors_field_types['text_formatted'] = array(
    'views' => array(),
    'feeds' => array(),
  );
}
