<?php
/**
 * @file
 */

/**
 * Class Mirror.
 */
class Mirror {

  protected $importer;
  protected $exporter;

  protected $bundle;

  /**
   * Construction.
   */
  public function __construct($bundle, Exporter $exporter, Importer $importer) {
    $this->$bundle = $bundle;
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
