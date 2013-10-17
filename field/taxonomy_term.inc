<?php

/**
 * @file
 * Field Declarations
 */

/**
 * Field Declaration: taxonomy_term.
 *
 * Called directly from mirrors.module.
 * Use hook_field_types_alter() from other modules.
 */
function mirrors_field_types_taxonomy_term(&$field_types) {
  $field_types['taxonomy_term'] = array(
    'views' => array(
      'type' => 'taxonomy_term_reference_plain',
    ),
    'feeds' => array(
      'term_search' => '0',
      'autocreate' => '1',
    ),
  );
}
