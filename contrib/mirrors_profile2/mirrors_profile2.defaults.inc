<?php

/**
 * @file
 * Mirrors Profile2 Defaults.
 */

/**
 * Returns Profile2 entity types.
 */
function mirrors_profile2_entity_types_defaults() {
  $mirrors_profile2_entity_types = array();

  // Profile2 Entity Types
  $profile2_entity_types = array(
    'profile2',
  );

  // We do this loop, so our module files are easier to read
  foreach ($profile2_entity_types as $type) {
    module_load_include('inc', 'mirrors_profile2', 'entity/' . $type);

    $function = 'mirrors_profile2_entity_types_' . $type;
    if (function_exists($function)) {
      $function($mirrors_profile2_entity_types);
    }
  }

  return $mirrors_profile2_entity_types;
}
