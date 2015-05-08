<?php

/**
 * @file
 * Commerce field declaration.
 */

/**
 * Called directly from mirrors_commerce.module
 * User hook_field_types_alter() from other modules
 */
function mirrors_commerce_field_types_commerce_product(&$mirrors_field_types) {
  $mirrors_field_types['commerce_product'] = array(
    'views' => array(
      'type' => 'commerce_product_reference_sku_plain',
      'settings' => array(
        'show_quantity' => '0',
        'default_quantity' => '1',
        'combine' => '1',
        'show_single_product_attributes' => '0',
        'line_item_type' => '0',
      ),
    ),
    // Target should be expanded with ":sku". Not in API yet.
    'feeds' => array(
      'target' => '<target>:sku',
    ),
  );
}
