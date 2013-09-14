<?php

/**
 * @file
 * Feeds Related
 */

/*
 * You must implement hook_migrate_api(), setting the API level to 2, for
 * your migration classes to be recognized by the Migrate module.
 */
function mirrors_migrate_api() {
  $bundles = mirrors_get_entity_field_mappers();
  foreach ($bundles as $entity_type => $bundle) {
    foreach ($bundle as $entity_id => $entity_field_mappers) {
    
      $importer_name = "mirrors_" . $entity_type . "__" . $entity_id;
      dpm($importer_name);
      $try = mirrors_views_get_view_config($importer_name, $entity_type, $entity_id, $entity_field_mappers);
      if ($try !== FALSE) {
        $export[$importer_name] = $try;
      }
    }
  }
  $migrations = array(
    'ExampleUser' => array(
      'class_name' => 'ExampleMigration',
      'group_name' => 'example',
    ),
  );
  
  $api = array(
    'api' => 2,
    'migrations' => $migrations,
  );
  return $api;
  
}



/**
 * A dynamic migration that is reused for each source CSV file.
 */
class ExampleMigration extends Migration {
  public function __construct() {
    parent::__construct();
    
    $this->description = t('Import EXAMPLE from CSV file.');
    //The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns = array(
      0 => array('guid', 'GUID'),
      1 => array('title', 'Title'),
      2 => array('body', 'Body'),
      3 => array('uid', 'uid'),
    );
    $this->source = new MigrateSourceCSV('sites\all\modules\custom\mirrors\example.csv', $columns);
    $this->destination = new MigrateDestinationNode('page');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
        array(
        'guid' => array('type' => 'varchar',
           'length' => 8,
           'not null' => TRUE,
           'description' => 'GUID',
          ),
        ),
        MigrateDestinationNode::getKeySchema()
      );



    //$this->addFieldMapping('nid', 'guid');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('uid', 'uid');

  }


  /**
   * Construct the machine name from the source file name.
   */
  protected function generateMachineName($class_name = NULL) {
    return 'example_niels';
    
  }

}
// Define Migrators

// Get MappingTargets
