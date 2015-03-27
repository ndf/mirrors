<?php

/**
 * @file
 * Defaults
 */

/**
 * Returns default entity types.
 */
function mirrors_entity_types_defaults() {
  $mirrors_entity_types = array();

  // Core entity_types are supported by default.
  $core_entity_types = array(
    'node',
    'taxonomy_term',
    'user',
  );

  // We do this loop, so our module files are easier to read.
  foreach ($core_entity_types as $type) {
    module_load_include('inc', 'mirrors', 'entity/' . $type);

    $function = 'mirrors_entity_types_' . $type;
    if (function_exists($function)) {
      $function($mirrors_entity_types);
    }
  }

  return $mirrors_entity_types;
}

/**
 * Returns default field types.
 */
function mirrors_field_types_defaults() {
  $mirrors_field_types = array();

  // Core field_types are supported by default.
  $core_field_types = array(
    'boolean',
    'date',
    'decimal',
    'field_item_file',
    'field_item_image',
    'field_item_link',
    'entityreference',
    'integer',
    'struct',
    'taxonomy_term',
    'text',
    'text_formatted',
    'video_embed_field',
  );

  // We do this loop, so our module files are easier to read.
  foreach ($core_field_types as $type) {
    module_load_include('inc', 'mirrors', 'field/' . $type);

    $function = 'mirrors_field_types_' . $type;
    if (function_exists($function)) {
      $function($mirrors_field_types);
    }
  }

  return $mirrors_field_types;
}

/**
 * Returns default property types.
 */
function mirrors_property_types_defaults() {
  $mirrors_property_types = array();

  // Core field_types are supported by default.
  $core_property_types = array(
    'boolean',
    'date',
    'integer',
    'text',
  );

  // We do this loop, so our module files are easier to read.
  foreach ($core_property_types as $type) {
    module_load_include('inc', 'mirrors', 'property/' . $type);

    $function = 'mirrors_property_types_' . $type;
    if (function_exists($function)) {
      $function($mirrors_property_types);
    }
  }

  return $mirrors_property_types;
}
