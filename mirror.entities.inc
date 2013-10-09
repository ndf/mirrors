<?php

/**
 * @file
 * Entity Declarations
 */

mirrors_entities_default() {
  $entities = array();
  // Every fields has a display (view) and target(feeds)
  $entities['taxonomy_term'] = array(
    'views' => array(
      'base_table' => 'taxonomy_term_data',
      'sorts' => array(
        'depth' => 'taxonomy_term_lineage',
        'lineage' => 'taxonomy_term_lineage',
      ),
      'filters' => array(
        'machine_name', 'taxonomy_vocabulary',
      ),
    ),
    'feeds' => array(
      'processor' => 'FeedsTermProcessor',
      'guid' => 'tid',
    ),
    'properties' => array(
      'machine_name' => array(
        'type' => 'text',
        'table' => 'taxonomy_vocabulary',
      ),
      'depth' => array(
        'type' => 'integer',
        'table' => 'taxonomy_term_lineage',
      ),
      'lineage' => array(
        'type' => 'integer',
        'table' => 'taxonomy_term_lineage',
      ),
      'tid' => array(
        'type' => 'integer',
      ),
      'status' => array(
        'type' => 'boolean',
      ),
    ),
  );
  
  drupal_alter('mirrors_entities', $entities);
  return $entities

}

mirror_commerce_mirrors_entities_alter(&entities) {
  $entities['commerce_product'] = array(
    'feeds' => array(
      'processor' => 'FeedsCommerceProductProcessor',
      'guid' => 'sku',
    ),
    'properties' => array(
      'sku' => array(
        'views' => array(
          'type' => 'integer',
        ),
        'feeds' => array(
          'guid' => TRUE,
        ),
      ),
      'title' => array(
        'type' => 'text',
      ),
      'status' => array(
        'type' => 'boolean',
      ),
    ),
    
  );
  
  $entities['commerce_customer_profile'] = array(
    'feeds' => array(
      'processor' => 'FeedsCommerceCustomerProfileProcessor',
    ),
    'properties' => array(
      'uid' => array(
        'views' => array(
          'type' => 'integer',
          'unique' => TRUE,
          'relationship' => 'uid',
          'table' => 'users',
        ),
        'feeds' => array(
          'guid' => TRUE,
        ),
      ),
      'status' => array(
        'type' => 'boolean',
      ),
    ),
    
  );
  
  
  return $entities;
}
