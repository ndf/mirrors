<?php

/**
 * @file
 * Mirrors field declaration: taxonomy_term.
 * The term name (not tid) of the field is used as mapper.
 */

/**
 * Field Declaration: taxonomy_term.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_field_types_alter() from other modules.
 */
function mirrors_field_types_taxonomy_term(&$mirrors_field_types) {
  $mirrors_field_types['taxonomy_term'] = array(
    'views' => array(
      'type' => 'taxonomy_term_reference_plain',
    ),
    'feeds' => array(
      'term_search' => '0',
      'autocreate' => '1',
    ),
  );
}
