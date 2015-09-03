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

  /**
   * @param $name
   * @param $entity_type
   * @param $entity_id
   * @param $mirrors_entity
   *
   * @return stdClass
   */
  public function createFeed($name, $entity_type, $entity_id, $mirrors_entity) {
    $processor = $mirrors_entity['feeds']['processor'];
    $config = $this->getDefaultTemplate($name, $entity_type, $entity_id, $processor);
    $mapping = $this->createMapping($mirrors_entity);

    $config['processor']['config']['mappings'] = $mapping;

    $feeds_importer = new stdClass();
    $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
    $feeds_importer->api_version = 1;
    $feeds_importer->id = $name;

    $feeds_importer->config = $config;

    return $feeds_importer;
  }

  /**
   * @param $mirrors_entity
   *
   * @return array
   */
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
          $this->extendToken($key, $override, $value);
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

  /**
   * @param $key
   * @param $override
   * @param $value
   *
   * @return mixed|string
   */
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

  /**
   * @param $name
   * @param $entity_type
   * @param $bundle
   * @param $processor
   *
   * @return array
   */
  private function getDefaultTemplate($name, $entity_type, $bundle, $processor) {
    $vars = array(
      '@entity_type' => $entity_type,
      '@bundle' => $bundle,
    );
    if ($entity_type == $bundle) {
      $description = t('Import @entity_type entities from a CSV file.', $vars);
    }
    else {
      $description = t('Import @entity_type entities of type @bundle from a CSV file.', $vars);
    }

    return array(
      'name' => $name,
      'description' => $description,
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
          'bundle' => $bundle,
          'update_existing' => 1,
          'expire' => '-1',
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
  }
}
