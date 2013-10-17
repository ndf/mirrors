<?php

/**
 * @file
 * Field Declarations
 * This field is used for both decimals as float. To support the latter
 * the scale is pushed up to 10.
 */

/**
 * Field Declaration: decimal.
 *
 * Called directly from mirrors.module.
 * Use hook_field_types_alter() from other modules.
 */
function mirrors_field_types_decimal(&$field_types) {
  $field_types['decimal'] = array(
    'views' => array(
      'settings' => array(
        'thousand_separator' => '',
        'decimal_separator' => '.',
        'scale' => '10',
        'prefix_suffix' => 1,
      ),
    ),
    'feeds' => array(),
  );
}
