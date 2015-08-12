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
   *
   * @return PropertyType[]
   *   Array object that implements PropertyTypeInterface and extends PropertyType.
   */
  public function getProperties();

  /**
   * Return Feeds settings that must be used for generating feeds exporter.
   */
  public function getImporterSettings();

  /**
   * Return Views settings that must be used for generating feeds exporter.
   */
  public function getExporterSettings();
}
