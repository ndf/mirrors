<?php

/**
 * @file
 * Declaration of Mirror class.
 */

namespace Drupal\mirrors_classy\Controller;

use Drupal\mirrors_classy\Exporter\Exporter;
use Drupal\mirrors_classy\Importer\Importer;

/**
 * Class Mirror
 * @package Drupal\mirrors_classy
 */
class Mirror {

  /**
   * Variable definitions.
   */
  protected $label;
  protected $bundle;
  protected $entity_type;
  protected $fields;
  protected $properties;
  protected $strict;

  /**
   * Return Importer / Exporter.
   *
   * @todo: should cast importer/exporter with same configuration.
   */
  function getImporter() {
    return new Importer();
  }

  function getExporter() {
    return new Exporter();
  }


  function __construct($label = "") {
    if (!empty($label)) {
      $this->label = $label;
    }
    else {
      $this->label = "A Label";
    }
  }

  public function getLabel() {
    return $this->label;
  }

  public function setLabel($label) {
    $this->label = (string) $label;
  }


  /**
   * Bundle property.
   */


}
