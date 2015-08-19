<?php
/**
 * @file
 * Contains: TaxonomyTerm.
 */

/**
 * Class TaxonomyTerm.
 */
class TaxonomyTerm extends EntityType implements EntityTypeInterface {


  /**
   * Return properties.
   *
   * @return PropertyType[]
   *   Array object that implements PropertyTypeInterface and extends PropertyType.
   */
  public function getProperties() {

  }

  /**
   * Return Feeds settings that must be used for generating feeds exporter.
   */
  public function getImporterSettings() {
  }

  /**
   * Return Views settings that must be used for generating feeds exporter.
   */
  public function getExporterSettings() {
  }

  /**
   * Entity Declaration: taxonomy_term.
   *
   * Called directly from mirrors.module.
   * Use hook_mirrors_entity_types_alter() from other modules.
   */
  function mirrors_entity_types_taxonomy_term(&$mirrors_entity_types) {
    $mirrors_entity_types['taxonomy_term'] = array(
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
        // TermID not supported by Feeds.
        'name' => array(
          'type' => 'text',
          'unique' => TRUE,
        ),
        'parent' => array(
          'type' => 'integer',
          'views' => array(
            'field' => 'name',
            'relationship' => 'parent',
          ),
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
      $mirrors_entity_types['taxonomy_term']['views']['sorts'] = array(
        'depth' => 'taxonomy_term_lineage',
        'lineage' => 'taxonomy_term_lineage',
      );
    }
  }

}
