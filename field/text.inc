<?php

/**
 * @file
 * Mirrors field declaration: text.
 */

/**
 * Field Declaration: text.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_field_types_alter() from other modules.
 */
function mirrors_field_types_text(&$mirrors_field_types) {
  $mirrors_field_types['text'] = array(
    'views' => array(),
    'feeds' => array(),
  );
}
