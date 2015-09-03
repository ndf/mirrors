<?php

/**
 * @file
 * Mirrors Factory.
 */

namespace Drupal\mirrors;

use Drupal\mirrors\Exporter\ViewsCSVFactory;
use EntityMetadataWrapper;

/**
 * Class MirrorsFactory.
 *
 * @package Drupal\mirrors
 *
 * Use factory pattern, because we can use this to discover if entity-type
 * bundle is supported and such.
 */
class MirrorsFactory {

  private $discoveredPlugins = [];

  /**
   * @param EntityMetadataWrapper $bundle
   */
  public function createMirrors(EntityMetadataWrapper $bundle) {


    $mirrors = new Mirrors($bundle->type(), $bundle->getBundle());

    // Create a mapping that is supported.
    $mirrors = $this->addMirrorsSupportedProperties($bundle, $mirrors);
    $mirrors = $this->addMirrorsSupportedFields($bundle, $mirrors);


    // Create the mirror object with the mapping.
    $mirrors->setExporter(new ViewsCSVFactory::getInstance());
    $mirrors->validateExporter($mirrors->getExporterMapping());

    // Validate the mirror object.

    // Return the mirror object.
    return $mirrors;
  }

  public function __construct() {

    // Discover Plugins.
    ctools_include('plugins');
    $this->discoveredPlugins['entity_type'] = ctools_get_plugins('mirrors', 'entity_type');
    $this->discoveredPlugins['field_type'] = ctools_get_plugins('mirrors', 'field_type');
    $this->discoveredPlugins['property_type'] = ctools_get_plugins('mirrors', 'property_type');
  }

  /**
   * Adds Fields to Mirrors object if type is supported by a plugin.
   *
   * @param EntityMetadataWrapper $bundle
   * @param Mirrors $mirrors
   */
  private function addMirrorsSupportedFields(EntityMetadataWrapper $bundle, Mirrors $mirrors) {

    // Filters out anything that doesn't match.
    $discovered_plugins = $this->discoveredPlugins;


    // Get fields from bundle.
    $fields = array_filter($bundle->getPropertyInfo(), function ($field) {
      if (isset($field['field']) && $field['field'] === TRUE) {
        return $field;
      }
    });
    // Add supported fields to mirrors.
    foreach ($fields as $key => $field) {
      if (in_array($field['type'], array_keys($this->discoveredPlugins['property_type']))) {
        $mirrors->addField($key, $field);
      }
      else {
        // Schema fields ('node:title', 'term:description', 'term:name' not catched now.
//        dpm($field);
      }
    }


    return $mirrors;
  }

  /**
   * Adds Properties to Mirrors object if type is supported by a plugin.
   *
   * @param EntityMetadataWrapper $bundle
   * @param Mirrors $mirrors
   */
  private function addMirrorsSupportedProperties(EntityMetadataWrapper $bundle, Mirrors $mirrors) {

    // Filters out anything that doesn't match.
    $discovered_plugins = $this->discoveredPlugins;


    // Get properties passed bundle.
    $properties = array_filter($bundle->getPropertyInfo(), function ($property) {
      if (isset($property['schema field'])) {
        return $property;
      }
    });
    // Add supported properties to mirrors.
    foreach ($properties as $key => $property) {
      if (in_array($property['type'], array_keys($this->discoveredPlugins['property_type']))) {
        $mirrors->addProperty($key, $property);
      }
      else {
        // Schema fields ('node:title', 'term:description', 'term:name' not catched now.
//        dpm($property);
      }
    }


    return $mirrors;
  }
}
