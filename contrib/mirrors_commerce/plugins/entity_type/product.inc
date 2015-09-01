<?php

/**
 * @file
 * Ctools plugin style.
 *
 * @see MirrorsEntityType plugins
 */

/**
 * Discoverable plugin.
 */
$plugin = array(
  'entity_type' => 'commerce_product',
  'entity_properties' => array(
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
  'views' => array(
    'handler' => array(
      'base_table' => 'users',
    ),
    'filters' => array(),
    'sorts' => array(
      'uid' => 'users',
    ),
    'fields' => array(),
  ),
  'feeds' => array(
    'processor' => 'FeedsCommerceProductProcessor',
    'fields' => array(),
  ),
);
