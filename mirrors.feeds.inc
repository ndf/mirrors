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
  $feeds_mirror = array(
    'taxonomy_term' => array(
      'processor' => 'FeedsTermProcessor',
      'base_table' => 'taxonomy_term_data',
      'filters' => array(
        'machine_name', 'taxonomy_vocabulary',
      ),
      // Sort only with lineage module (hook?)
      'sorts' => array(
        'depth' => 'taxonomy_term_lineage',
        'lineage' => 'taxonomy_term_lineage',
      ),
      'properties' => array(
        'machine_name' => array(
          'type' => 'text',
          'table' => 'taxonomy_vocabulary',
        
        ),
        'depth' => array(
          'type' => 'integer',
          'table' => 'taxonomy_term_lineage',
          'sort' => TRUE,
        ),
        'tid' => array(
          'guid' => TRUE,
          'type' => 'integer',
        ),
        'status' => array(
          'type' => 'boolean',
        ),
      ),
    ),
    'commerce_customer_profile' => array(
      'base_table' => 'commerce_customer_profile',
      'properties' => array(
        'profile_id' => array(
          'guid' => TRUE,
          'relationship' => 'uid',
          'table' => 'users',
          'sort' => 'ASC',
          'type' => 'integer',
        )
      ),
    ),
  )
  
  ;
  
  
  
  if ($entity_type == 'node') {
    $processor = 'FeedsNodeProcessor';
  }
  elseif ($entity_type == 'taxonomy_term') {
    $processor = 'FeedsTermProcessor';
  }
  elseif ($entity_type == 'user') {
    $processor = 'FeedsUserProcessor';
  }
  elseif ($entity_type == 'commerce_product') {
    $processor = 'FeedsCommerceProductProcessor';
  }
  elseif ($entity_type == 'commerce_customer_profile') {
    $processor = 'FeedsCommerceCustomerProfileProcessor';
  }
  else {
    //dvm('unsupported entity type: ' . $entity_type . ' @mirror.feeds.inc');
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
        'allowed_extensions' => 'txt csv tsv xml opml',
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ';',
        'no_headers' => 0,
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
    'update_existing' => 2,
    'import_period' => '-1',
    'expire_period' => 0,
    'import_on_create' => 1,
  );
  
  // Add fields and properties mapping
  foreach ($entity_field_mappers as $key => $field_mapper) {
    $mapper = array();
    
    // Kill reference fields
    if ($key == 'commerce_customer_address') {
      break;
    }
    
    // Set source and target
    $mapper['source'] = $key;
    $mapper['target'] = $key;
  
    // Get field settings
    if (isset($field_mapper['type'])) {
      $mapper = mirrors_feeds_set_field_formatter($mapper, $field_mapper['type']);
    }
    
    // Set Unique Target
    if (isset($field_mapper['unique'])) {
      $mapper['unique'] = $field_mapper['unique'];
    }
    else {
      $mapper['unique'] = 0;
    }
    
    // Save the config
    $config['processor']['config']['mappings'][] = $mapper;
  }
  
  $feeds_importer->config = $config;

  return $feeds_importer;
}

function mirrors_feeds_set_field_formatter($mapper, $field_type) {
  $mapper['type'] = $field_type;
  
  // Check if we are dealing with a list
  if(substr($field_type, 0, 4) == 'list') {
    $mapper['separator'] = '/';
    
    // Extract field_type "list<$field_type>"
    $length = strlen($field_type);
    $field_type = substr($field_type, 5, $length - 6);
  }
  
  // Per field parsing
  if ($field_type == 'boolean') {
  }
  elseif ($field_type == 'date') {
  }
  elseif ($field_type == 'list') {
  }
  elseif ($field_type == 'decimal') {
  }
  elseif ($field_type == 'integer') {
  }
  elseif ($field_type == 'text_formatted') {
  }
  elseif ($field_type == 'text') {
  }
  elseif ($field_type == 'taxonomy_term') {
  }
  elseif ($field_type == 'commerce_product') {
  }
  elseif ($field_type == 'commerce_price') {
    $mapper['target'] = $mapper['target'] . ':amount';
  }
  elseif ($field_type == 'addressfield') {
    $mapper['target'] = 'commerce_customer_address:' . $mapper['target'];
  }
  else {
    dpm('unsupported field_type: ' . $field_type . ' @mirror.feeds.inc');
  }
  

  return $mapper;
}


/**
 * Implementation of hook_commerce_mirrors_say_alter().
 */
function mirrors_mirrors_say_alter(&$data) {
  $data['mirrors_mirrors_say_alter'] = 'mirrors_mirrors_say_alter';
}
