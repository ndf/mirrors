<?php

/**
 * @file
 * Commerce entity declaration.
 */

/**
 * Called directly from mirrors.module
 * User hook_entity_type_alter() from other modules
 */
function mirrors_commerce_entity_types_product(&$entity_types) {
  $entity_types['commerce_product'] = array(
    'views' => array(
      'filter',
      'base_table',
      'sorts',
    ),
    'feeds' => array(
      'processor' => 'FeedsCommerceProductProcessor',
    ),
    'properties' => array(
      'nid' => 'text',
      'uid' => 'text',
    ),
  );
}
