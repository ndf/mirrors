<?php

/**
 * @file
 * Mirrors Entity Defaults.
 */

/**
 * Returns Entity entity types.
 */
function mirrors_entity_entity_types_defaults() {
  $mirrors_entity_entity_types = array();

  // Entity Entity Types
  $commerce_entity_types = array();

  // We do this loop, so our module files are easier to read
  foreach ($commerce_entity_types as $type) {
    module_load_include('inc', 'mirrors_entity', 'entity/' . $type);

    $function = 'mirrors_entity_entity_types_' . $type;
    if (function_exists($function)) {
      $function($mirrors_entity_entity_types);
    }
  }

  return $mirrors_entity_entity_types;
}
