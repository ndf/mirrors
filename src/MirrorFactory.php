<?php
/**
 * Created by PhpStorm.
 * User: ndf
 * Date: 19/08/15
 * Time: 10:20
 */

namespace Drupal\mirrors;

/**
 * Class MirrorFactory.
 *
 * @package Drupal\mirrors
 *
 * Use factory pattern, because we can use this to discover if entity-type
 * bundle is supported and such.
 */
class MirrorFactory {

  /**
   * Returns a list of supported entity-types/bundles.
   *
   * aka: node, commerce_order.
   * Can be used as input on admin-forms to create a new mirror.
   */
  public function getSupportedEntityTypes() {

  }

  /**
   * Returns a list of implemented mapping.
   *
   * Should be something like: CSV.
   *
   * @todo: make decision to only support one mapping-type or make it plugable.
   */
  public function getImplementedMappings() {
    return 'csv';
  }

  /**
   * Return a mirrors
   */
  public function createMirror(DrupalEntityBundle $bundle, MirrorMappingType $type) {

  }

}
