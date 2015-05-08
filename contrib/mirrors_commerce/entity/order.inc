<?php

/**
 * @file
 * Commerce entity declaration.
 */

/**
 * Called directly from mirrors.module
 * User hook_entity_type_alter() from other modules
 */
function mirrors_commerce_entity_types_order(&$entity_types) {
  $entity_types['order'] = array(
    'views' => array(
      'filter',
      'base_table',
      'sorts',
    ),
    'feeds' => array(
      'processor' => 'FeedsTermProcessor',
    ),
    'properties' => array(
      'nid' => 'text',
      'uid' => 'text',
    ),
  );
}
