<?php

/**
 * @file
 * Entity Declarations
 */

/**
 * Called directly from mirrors.module
 * User hook_entity_type_alter() from other modules
 */
function mirrors_entity_types_taxonomy_term(&$entity_types) {
  $entity_types['taxonomy_term'] = array(
    'views' => array(
      'base_table' => 'taxonomy_term_data',
      'filters' => array(
        'machine_name' => 'taxonomy_vocabulary',
      ),
      'relationships' => array(
        'parent' => 'taxonomy_term_hierarchy',
      ),
      'sorts' => array(
        'tid' => 'taxonomy_term_data',
      ),
    ),
    'feeds' => array(
      'processor' => 'FeedsTermProcessor',
    ),
    'properties' => array(
      // TermID not supported by Feeds
      'name' => array(
        'type' => 'text',
        'unique' => TRUE,
      ),
      'parent' => array(
        'type' => 'integer',
        'views' => array(
          'field' => 'name',
          'relationship' => 'parent',
        )
      ),
      'weight' => array(
        'type' => 'integer',
      ),
      'description' => array(
        'type' => 'text',
      ),
    ),
  );
  if (module_exists('lineage')) {
    $entity_types['taxonomy_term']['views']['sorts'] = array(
      'depth' => 'taxonomy_term_lineage',
      'lineage' => 'taxonomy_term_lineage',
    );
  }
}
