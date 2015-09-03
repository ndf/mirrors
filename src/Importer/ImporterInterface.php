<?php

/**
 * @file
 * ImporterInterface.
 */

namespace Drupal\mirrors\Importer;

use Drupal\mirrors\Mapping;

interface ImporterInterface{

  /**
   * Return Importer Object.
   */
  public function toCode();

  /**
   * @param FieldMappingInterface $field
   *
   * @return mixed
   */
  public function addField(FieldMappingInterface $field);

  /**
   * @param BundleMappingInterface $bundle
   *
   * @return mixed
   */
  public function setBundle(BundleMappingInterface $bundle);
}
