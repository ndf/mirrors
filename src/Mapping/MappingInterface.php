<?php

/**
 * @file
 * Mirrors Bundle Mapping Interface.
 */

namespace Drupal\mirrors\Mapping;

interface MappingInterface {
  public function get

  public function getProperties();

  public function getFields();

  public function getEntityType();

  public function getBundle();

}
