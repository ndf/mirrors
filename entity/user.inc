<?php

/**
 * @file
 * Entity Declarations
 */

/**
 * Entity Declaration: user.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_entity_types_alter() from other modules.
 */
function mirrors_mirrors_entity_types_user(&$entity_types) {
  $entity_types['user'] = array(
    'views' => array(
      'base_table' => 'users',
      'filters' => array(),
      'sorts' => array(
        'uid' => 'users',
      ),
    ),
    'feeds' => array(
      'processor' => 'FeedsUserProcessor',
    ),
    'properties' => array(
      'name' => array(
        'type' => 'text',
        'unique' => TRUE,
        'views' => array(
          'link_to_user' => FALSE,
        ),
      ),
      'mail' => array(
        'type' => 'text',
        'views' => array(
          'link_to_user' => '0',
        ),
      ),
      'created' => array(
        'type' => 'date',
      ),
      'status' => array(
        'type' => 'boolean',
      ),
      'language' => array(
        'type' => 'text',
        'views' => array(
          'link_to_user' => FALSE,
        ),
      ),
    ),
  );
}
