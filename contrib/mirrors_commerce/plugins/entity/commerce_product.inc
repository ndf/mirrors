<?php

/**
 * @file
 * Mirrors entity plugin declaration.
 */

/**
 * Entity Declaration: Commerce Product.
 */
$plugin = array(
  'title' => t('Commerce Product'),
  'category' => 'Entity',
  'views' => array(
    'base_table' => 'commerce_product',
  ),
  'feeds' => array(
    'processor' => 'FeedsEntityProcessorCommerce_product',
  ),
  'properties' => array(
//    'product_id' => array(
//      'type' => 'integer',
//      'feeds' => array(
//        'unique' => TRUE,
//      ),
//    ),
    'sku' => array(
      'type' => 'text',
    ),
    'title' => array(
      'type' => 'text',
    ),
    'language' => array(
      'type' => 'text',
    ),
    'uid' => array(
      'type' => 'uid',
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
  ),
);
