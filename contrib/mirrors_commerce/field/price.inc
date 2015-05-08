<?php

/**
 * @file
 * Commerce field declaration.
 */

/**
 * Called directly from mirrors_commerce.module
 * User hook_field_types_alter() from other modules
 */
function mirrors_commerce_field_types_price(&$field_types) {
  $field_types['price'] = array(
    'views' => array(),
    'feeds' => array(
      'target' => 'SELF:amount',
    ),
  );
}
