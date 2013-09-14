<?php

/**
 * @file
 * Feeds Related
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function mirrors_ctools_plugin_api($module = 'mirrors', $api = '') {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    // The current API version is 1.
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_feeds_importer_default().
 */
function mirrors_feeds_importer_default() {
  $export = array();
  
  $bundles = mirrors_get_entity_field_mappers();
  foreach ($bundles as $entity_type => $bundle) {
    foreach ($bundle as $entity_id => $entity_field_mappers) {
    
      $importer_name = "mirrors_" . $entity_type . "__" . $entity_id;
      $try = mirrors_feeds_get_importer_config($importer_name, $entity_type, $entity_id, $entity_field_mappers);
      if ($try !== FALSE) {
        $export[$importer_name] = $try;
      }
    }
  }

  return $export;
}

/**
 * Default definition of 'myimporter'
 */ 
function mirrors_feeds_get_importer_config($importer_name, $entity_type, $entity_id, $entity_field_mappers) {
  if ($entity_type == 'node') {
    $processor = 'FeedsNodeProcessor';
  }
  elseif ($entity_type == 'taxonomy_term') {
    $processor = 'FeedsTermProcessor';
  }
  elseif ($entity_type == 'user') {
    $processor = 'FeedsUserProcessor';
  }
  else {
    return FALSE;
  }

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = $importer_name;
  $config = array(
    'name' => $importer_name,
    'description' => 'Import ' . $entity_type . 's from CSV file.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ';',
      ),
    ),
    'processor' => array(
      'plugin_key' => $processor,
      'config' => array(
        'bundle' => $entity_id,
        'update_existing' => 1,
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'input_format' => 'plain_text',
        'author' => 0,
      ),
    ),
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 0,
    'import_on_create' => 1,
  );
  
  // Add fields and properties mapping
  foreach ($entity_field_mappers as $key => $field_mapper) {
    $mapper = array();
    
    $mapper['source'] = $key;
    $mapper['target'] = $key;
    
    if (isset($field_mapper['unique'])) {
      $mapper['unique'] = $field_mapper['unique'];
    }
    else {
      $mapper['unique'] = 0;
    }
    
    $config['processor']['config']['mappings'][] = $mapper;
  }
  
  $feeds_importer->config = $config;

  return $feeds_importer;
}

