<?php
/**
 * @file
 * Contains: EntityTypeInterface.
 */

/**
 * Interface EntityTypeInterface.
 */
interface EntityTypeInterface {

  /**
   * Return properties.
   */
  public function getEntityProperties();

  /**
   * Return Feeds settings that must be used for generating feeds exporter.
   */
  public function getImporterSettings();

  /**
   * Return Views settings that must be used for generating feeds exporter.
   */
  public function getExporterSettings();
}
