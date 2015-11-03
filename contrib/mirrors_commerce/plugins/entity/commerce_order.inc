<?php

/**
 * @file
 * Mirrors entity plugin declaration.
 */

/**
 * Entity Declaration: Commerce Order.
 */
$plugin = array(
  'title' => t('Commerce Order'),
  'category' => 'Entity',
  'views' => array(
    'base_table' => 'commerce_order',
  ),
  'feeds' => array(
    'processor' => 'FeedsEntityProcessorCommerce_order',
  ),
  'properties' => array(
    'order_id' => array(
      'type' => 'integer',
    ),
    'order_number' => array(
      'type' => 'text',
    ),
    'uid' => array(
      'type' => 'uid',
    ),
    'mail' => array(
      'type' => 'text',
    ),
    'status' => array(
      'type' => 'text',
    ),
    'created' => array(
      'type' => 'date',
    ),
    'changed' => array(
      'type' => 'date',
    ),
    'hostname' => array(
      'type' => 'text',
    ),
  ),
);
