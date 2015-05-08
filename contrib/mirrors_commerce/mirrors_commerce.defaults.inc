<?php

/**
 * @file
 * Mirrors Commerce Defaults.
 */

/**
 * Returns Commerce entity types.
 */
function mirrors_commerce_entity_types_defaults() {
  $mirrors_commerce_entity_types = array();

  // Commerce Entity Types
  $commerce_entity_types = array();

  // We do this loop, so our module files are easier to read
  foreach ($commerce_entity_types as $type) {
    module_load_include('inc', 'mirrors_commerce', 'entity/' . $type);

    $function = 'mirrors_commerce_entity_types_' . $type;
    if (function_exists($function)) {
      $function($mirrors_commerce_entity_types);
    }
  }

  return $mirrors_commerce_entity_types;
}

/**
 * Returns Commerce field types.
 */
function mirrors_commerce_field_types_defaults() {
  $mirrors_commerce_field_types = array();

  // Commerce Field Types
  $commerce_field_types = array(
    'addressfield',
    'price',
    'commerce_product',
  );

  // We do this loop, so our module files are easier to read
  foreach ($commerce_field_types as $type) {
    module_load_include('inc', 'mirrors_commerce', 'field/' . $type);

    $function = 'mirrors_commerce_field_types_' . $type;
    if (function_exists($function)) {
      $function($mirrors_commerce_field_types);
    }
  }

  return $mirrors_commerce_field_types;
}
