<?php

/**
 * @file
 * Profile2 entity declaration.
 */

/**
 * Called directly from mirrors.module
 * User hook_entity_type_alter() from other modules
 */
function mirrors_profile2_entity_types_product(&$entity_types) {
  $entity_types['profile2'] = array(
    'views' => array(
      'filter',
      'base_table',
      'sorts',
    ),
    'feeds' => array(
      'processor' => 'FeedsEntityProcessor',
    ),
    'properties' => array(
      'pid' => 'text',
      'uid' => 'text',
    ),
  );
}
