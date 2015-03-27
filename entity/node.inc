<?php

/**
 * @file
 * Mirrors entity declaration: node.
 * Language is supported.
 */

/**
 * Entity Declaration: node.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_entity_types_alter() from other modules.
 *
 * @todo: try to load properties with 'entity_get_property_info()'.
 */
function mirrors_entity_types_node(&$mirrors_entity_types) {
  $mirrors_entity_types['node'] = array(
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
  );

  // Add Properties.
  _mirrors_entity_types_node_extract_properties($mirrors_entity_types);

  // Override some default node properties.
  $mirrors_entity_types['node']['properties']['nid'] = array(
    'type' => 'integer',
    'unique' => TRUE,
  );
  $mirrors_entity_types['node']['properties']['title'] = array(
    'type' => 'text',
    'views' => array(
      'link_to_user' => FALSE,
    ),
  );
  $mirrors_entity_types['node']['properties']['uid'] = array(
    'type' => 'text',
    'views' => array(
      'link_to_user' => FALSE,
    ),
  );
}

/**
 * Tries to load all properties.
 *
 * @todo: handle <list> properties.
 */
function _mirrors_entity_types_node_extract_properties(&$mirrors_entity_types) {
  $entities = entity_get_property_info();
  $mirrors_property_types = mirrors_property_types_defaults();

  // Check if the propperies of nodes can be handled by Mirros. If so, add them.
  foreach ($entities['node']['properties'] as $property => $property_info) {
    if ($mirrors_property_types[$property_info['type']]) {
      // Add settings.
      $mirrors_entity_types['node']['properties'][$property]['type'] = $property_info['type'];
    }
    else {
      if (variable_get('mirror_development_mode', 1)) {
        drupal_set_message("The node property " . $property . " cannot be handled", 'warning');
      }
    }
  }
}
