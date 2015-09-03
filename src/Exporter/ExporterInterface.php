<?php

/**
 * @file
 * ExporterInterface.
 */

namespace Drupal\mirrors\Importer;

use Drupal\mirrors\Mapping;

/**
 * Interface ExporterInterface
 * @package Drupal\mirrors\Importer
 */
interface ExporterInterface {

  /**
   * Return Exporter Object.
   */
  public function toCode();

  /**
   * @param FieldMappingInterface $field
   *
   * @return mixed
   */
  public function addField(FieldMappingInterface $field);

  /**
   * @param SortMappingInterface $sort
   *
   * @return mixed
   */
  public function addSort(SortMappingInterface $sort);

  /**
   * @param BundleMappingInterface $bundle
   *
   * @return mixed
   */
  public function setBundle(BundleMappingInterface $bundle);
}
