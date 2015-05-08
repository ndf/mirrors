<?php

/**
 * @file
 * Entity entity declaration.
 */

/**
 * Called directly from mirrors.module
 * User hook_entity_type_alter() from other modules
 *
 * Generic solution for entities.
 */
function mirrors_entity_entity_types_product(&$entity_types) {

  // Load all entities.
  // Get properties via entity_metadata_wrapper.

//  $entity_types['entity'] = array(
//    'views' => array(
//      'filter',
//      'base_table',
//      'sorts',
//    ),
//    'feeds' => array(
//      'processor' => 'FeedsEntityProcessor',
//    ),
//    'properties' => array(
//      'pid' => 'text',
//      'uid' => 'text',
//    ),
//  );
}
