<?php

/**
 * @file
 * Defaults
 */

/**
 * Returns default entity types.
 */
function mirrors_entity_types_defaults() {
  $entity_types = array();

  // Core entity_types are supported by default.
  $core_entity_types = array(
    'node',
    'taxonomy_term',
    'user',
    'not_working',
  );

  // We do this loop, so our module files are easier to read.
  foreach ($core_entity_types as $type) {
    module_load_include('inc', 'mirrors', 'entity/' . $type);

    $function = 'mirrors_entity_types_' . $type;
    if (function_exists($function)) {
      $function($entity_types);
    }
  }

  return $entity_types;
}

/**
 * Returns default field types.
 */
function mirrors_field_types_defaults() {
  $field_types = array();

  // Core field_types are supported by default.
  $core_field_types = array(
    'boolean',
    'date',
    'decimal',
    'integer',
    'taxonomy_term',
    'text',
    'text_formatted',
  );

  // We do this loop, so our module files are easier to read.
  foreach ($core_field_types as $type) {
    module_load_include('inc', 'mirrors', 'field/' . $type);

    $function = 'mirrors_field_types_' . $type;
    if (function_exists($function)) {
      $function($field_types);
    }
  }

  return $field_types;
}

/**
 * Returns default property types.
 */
function mirrors_property_types_defaults() {
  $property_types = array();

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
      $function($property_types);
    }
  }

  return $property_types;
}
