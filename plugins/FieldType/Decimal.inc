<?php

/**
 * @file
 * Mirrors field declaration: decimal.
 * Used for both decimals and float. To support the latter the scale is
 * maximized up to 10.
 */

/**
 * Field Declaration: decimal.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_field_types_alter() from other modules.
 */
function mirrors_field_types_decimal(&$mirrors_field_types) {
  $mirrors_field_types['decimal'] = array(
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
