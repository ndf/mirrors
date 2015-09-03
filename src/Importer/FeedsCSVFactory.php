<?php

/**
 * @file
 * Mirrors Feeds Factory.
 */

namespace Drupal\mirrors\Importer;

/**
 * Class Mirrors.
 */
class FeedsCSVFactory {
  public function createFeed($name, $entity_type, $entity_id, $mirrors_entity) {
    $processor = $mirrors_entity['feeds']['processor'];
    $config = mirrors_feeds_default_template($name, $entity_type, $entity_id, $processor);
    $mapping = mirrors_feeds_mapping_create($mirrors_entity);

    $config['processor']['config']['mappings'] = $mapping;

    $feeds_importer = new stdClass();
    $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
    $feeds_importer->api_version = 1;
    $feeds_importer->id = $name;

    $feeds_importer->config = $config;

    return $feeds_importer;
  }

  private function createMapping($mirrors_entity) {
    $mapping = array();

    // We do properties and fields in one shot.
    $mappers = array_merge(
      $mirrors_entity['properties'],
      $mirrors_entity['fields']
    );

    foreach ($mappers as $key => $property) {

      $mapper = array();
      $mapper['source'] = $key;
      $mapper['target'] = $key;

      // Now enable specific feeds overrides.
      if (isset($property['feeds'])) {
        foreach ((array) $property['feeds'] as $override => $value) {
          // Parse key override supporter (with '<$key>:extension' structure).
          mirrors_feeds_mapping_extend_token($key, $override, $value);
          $mapper[$override] = $value;
        }
      }

      // Set GUID field.
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

  private function extendToken($key, $override, $value) {
    // If "SELF" is passed, replace it with the key.
    $value = preg_replace('/SELF/', $key, $value, 1);

    $key_length = strlen($override);
    // Check if we are dealing with a list.
    if (substr($value, 0, $key_length + 2) == '<' . $override . '>') {
      $extension = substr($value, $key_length + 2);
      dpm($extension);
      $value = $key . $extension;
      // Extract field_type "list<$field_type>".
    }
    return $value;
  }
}
