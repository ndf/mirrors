<?php

/**
 * @file
 * Discoverable plugin for Mirrors.
 */

/**
 * Discoverable plugin.
 */
$plugin = array(
  'entity_type' => 'node',
  'entity_properties' => array(
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
      'type' => 'uuid',
      'views' => array(
        'link_to_user' => FALSE,
      ),
    ),
  ),
  'views' => array(
    'handler' => array(
      'base_table' => 'node',
    ),
    'filters' => array(
      'type' => 'node',
    ),
    'sorts' => array(
      'nid' => 'node',
    ),
    'fields' => array(),
  ),
  'feeds' => array(
    'processor' => 'FeedsNodeProcessor',
    'fields' => array(),
  ),
);
