<?php
/**
 * @file
 * Contains: PropertyTypeInterface.
 */

/**
 * Interface PropertyTypeInterface.
 */
interface PropertyTypeInterface {


  /**
   * Return Feeds settings that must be used for generating feeds exporter.
   */
  public function getImporterSettings();

  /**
   * Return Views settings that must be used for generating feeds exporter.
   */
  public function getExporterSettings();
}
