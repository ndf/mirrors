<?php

/**
 * @file
 * Property Declarations
 */

/**
 * Property Declaration: text.
 *
 * Called directly from mirrors.module.
 * Use hook_property_types_alter() from other modules.
 */
function mirrors_property_types_text(&$property_types) {
  $property_types['text'] = array(
    'views' => array(),
    'feeds' => array(),
  );
}
