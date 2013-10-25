<?php

/**
 * @file
 * Mirrors property declaration: text.
 */

/**
 * Property Declaration: text.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_property_types_alter() from other modules.
 */
function mirrors_property_types_text(&$mirrors_property_types) {
  $mirrors_property_types['text'] = array(
    'views' => array(),
    'feeds' => array(),
  );
}
