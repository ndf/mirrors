<?php

/**
 * @file
 * Mirrors entity plugin declaration.
 */

/**
 * Entity Declaration: Commerce Store.
 */
$plugin = array(
  'title' => t('Commerce Store'),
  'category' => 'Entity',
  'views' => array(
    'base_table' => 'commerce_store',
    'relationships' => array(
      'uid' => 'commerce_store',
    ),
  ),
  'feeds' => array(
    'processor' => 'FeedsEntityProcessorCommerce_store',
  ),
  'properties' => array(
    'store_id' => array(
      'type' => 'integer',
    ),
    'title' => array(
      'type' => 'text',
      'feeds' => array(
        'unique' => TRUE,
      ),
    ),
    'language' => array(
      'type' => 'text',
    ),
    'status' => array(
      'type' => 'boolean',
    ),
    'created' => array(
      'type' => 'date',
    ),
    'changed' => array(
      'type' => 'date',
    ),
    'uid' => array(
      'type' => 'uid',
    ),
  ),
);
