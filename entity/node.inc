<?php

/**
 * @file
 * Entity Declarations
 */

/**
 * Entity Declaration: node.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_entity_types_alter() from other modules.
 */
function mirrors_mirrors_entity_types_node(&$entity_types) {
  $entity_types['node'] = array(
    'views' => array(
      'base_table' => 'node',
      'filters' => array(
        'type' => 'node',
      ),
      'sorts' => array(
        'nid' => 'node',
      ),
    ),
    'feeds' => array(
      'processor' => 'FeedsNodeProcessor',
    ),
    'properties' => array(
      'nid' => array(
        'type' => 'integer',
        'unique' => TRUE,
      ),
      'title' => array(
        'type' => 'text',
        'views' => array(
          'link_to_node' => FALSE,
        ),
      ),
      'uid' => array(
        'type' => 'text',
        'views' => array(
          'link_to_user' => FALSE,
        ),
      ),
      'status' => array(
        'type' => 'boolean',
      ),
      'created' => array(
        'type' => 'date',
      ),
      'promote' => array(
        'type' => 'boolean',
      ),
      'sticky' => array(
        'type' => 'boolean',
      ),
    ),
  );
  if (module_exists('locale')) {
    $entity_types['node']['properties']['language'] = array(
      'type' => 'text',
    );
  }
}
