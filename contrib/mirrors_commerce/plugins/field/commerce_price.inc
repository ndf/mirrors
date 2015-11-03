<?php

/**
 * @file
 * Mirrors field plugin declaration.
 */

/**
 * Field Declaration: commerce price.
 *
 * @todo feeds_tamper currency and amount
 */
$plugin = array(
  'title' => t('Commerce Price'),
  'category' => 'Field',
  'views' => array(
    'type' => 'commerce_price_raw_amount',
    'settings' => array(
      'calculation' => '0',
    ),
  ),
  'feeds' => array(
    'target' => 'SELF:amount',
  ),
);
