<?php

/**
 * @file
 * Field Declarations
 */

mirrors_fields_default() {
  $fields = array();
  
  $fields['default'] = array(
    'views' => array(
      'type' => '[key]',
    ),
    'feeds' => array(
      'target' = '[value]',
    ),  
  );
  
  
  // Every fields has a display (view) and target(feeds)
  $fields['boolean'] = array(
    'views' => array(
      'type' => 'boolean_yes_no',
      'settings' => array(
        'format' => 'boolean',
        'custom_on' => '',
        'custom_off' => '',
        'reverse' => 0,
      ),
    ),
  );
  
  drupal_alter('mirrors_fields', $fields);
  return $fields
}

mirror_commerce_mirrors_fields_alter(&fields) {
  $fields['commerce_price'] = array(
    'views' => array(
      'type' => 'commerce_price_raw_amount',
      'settings' => array(
        'thousand_separator' => '',
        'decimal_separator' => '.',
        'scale' => '2',
        'prefix_suffix' => 1,
      ),
    ),
    'feeds' => array(
      'target' = '[key]:amount',
    ),
  );

  $fields['addressfield'] = array(
    'views' => array(
      'id' => 'commerce_customer_address_[key]',
      'table' => 'field_data_commerce_customer_address',
      'field' => 'commerce_customer_address_[key]',
    ),
  );
  
  $fields['commerce_product'] = array(
    'views' => array(
      'type' => 'commerce_product_reference_sku_plain',
      'settings' => array(
        'view_mode' => 'full',
        'page' => 1,
      ),
    ),
  );
  
  return $fields;
}