<?php

/**
 * @file
 * Mirrors field declaration: entity_reference.
 */

/**
 * Field Declaration: entity_reference.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_field_types_alter() from other modules.
 */
function mirrors_field_types_entityreference(&$mirrors_field_types) {
  $mirrors_field_types['entityreference'] = array(
    'views' => array(
      'settings' => array('link' => 0),
    ),
    'feeds' => array(),
  );
}
