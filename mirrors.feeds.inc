<?php

/**
 * @file
 * Feeds Related
 */

module_load_include('inc', 'mirrors', 'mirrors.feeds.template');

/**
 * Implements hook_ctools_plugin_api().
 */
function mirrors_ctools_plugin_api($module = 'mirrors', $api = '') {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    // The current API version is 1.
    return array("version" => 1);
  }
}

/**
 * Implements hook_feeds_importer_default().
 */
function mirrors_feeds_importer_default() {
  $export = array();

  $bundles = mirrors_bundles();
  foreach ($bundles as $entity_type => $bundle) {
    foreach ($bundle as $entity_id => $mirrors_entity) {

      $importer_name = "mirrors_" . $entity_type . "__" . $entity_id;
      $try = mirrors_feeds_importer_create($importer_name, $entity_type, $entity_id, $mirrors_entity);

      if ($try !== FALSE) {
        $export[$importer_name] = $try;
      }
    }
  }

  return $export;
}

/**
 * Creates a Feed object (the importer).
 */
function mirrors_feeds_importer_create($importer_name, $entity_type, $entity_id, $mirrors_entity) {
  $processor = $mirrors_entity['feeds']['processor'];
  $config = mirrors_feeds_default_template($importer_name, $entity_type, $entity_id, $processor);
  $mapping = mirrors_feeds_mapping_create($mirrors_entity);

  $config['processor']['config']['mappings'] = $mapping;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = $importer_name;

  $feeds_importer->config = $config;

  return $feeds_importer;
}

/**
 * Returns feeds field mapping.
 */
function mirrors_feeds_mapping_create($mirrors_entity) {
  $mapping = array();

  // We do properties and fields in one shot
  $mappers = array_merge(
    $mirrors_entity['properties'],
    $mirrors_entity['fields']
  );

  foreach ($mappers as $key => $property) {

    $mapper = array();
    $mapper['source'] = $key;
    $mapper['target'] = $key;

    // Now enable specific feeds overrides
    if (isset($property['feeds'])) {
      foreach ((array)$property['feeds'] as $key => $value) {
        $mapper[$key] = $value;
      }
    }

    // Set GUID field
    if (isset($property['unique']) && $property['unique'] == 1) {
      $mapper['unique'] = $property['unique'];
    }
    else {
      $mapper['unique'] = 0;
    }

    $mapping[] = $mapper;
  }

  return $mapping;
}
