<?php

/**
 * @file
 * Mirrors Class
 */

namespace Drupal\mirrors;



/**
 * Class Mirrors.
 */
class Mirrors {

  protected $importer;
  protected $exporter;

  protected $properties;
  protected $fields;
  protected $entityType;
  protected $bundle;


  /**
   * Construction.
   */
  public function __construct($entity_type, $bundle) {
    $this->entityType = $entity_type;
    $this->bundle = $bundle;
  }

  public function addField($key, $settings) {
    $this->fields[$key] = $settings;
  }

  public function addProperty($key, $settings) {
    $this->properties[$key] = $settings;
  }

  /**
   *
   */
  public function export() {

  }

  /**
   *
   */
  public function import() {

  }
}
