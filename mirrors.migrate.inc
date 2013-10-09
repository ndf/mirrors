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
      //dpm($importer_name);
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
    'wizard classes' => array('MirrorsMigrateWizard'),
    //'migrations' => $migrations,
  );
  return $api;

}

/* our new class */
class MirrorsMigrateWizard extends MigrateUIWizard {
  protected $filename;
  public function getSourceName(){
    return t('Mirrors');
  }
  public function __construct() {
    parent::__construct();
    $this->addStep(t('Upload CSV'), 'sourceDataForm');
    $this->addStep(t('Select content to import'), 'contentSelectForm');
    $this->addStep(t('Review'), 'reviewForm');
  }
/**
   * First step - find out how to get the source data.
   */
  public function sourceDataForm(&$form_state) {
  

  $importer = feeds_importer('tester');
  dpm($importer);
  $processor = $importer->processor;

  $feeds_importer = new stdClass;
  $feeds_importer->id = 'gigi';
  $config = array(
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
    ),
  );
  $feeds_importer->config = $config;
  dvm($feeds_importer);
  
  $processor->addConfig(array('plugin_key' => 'FeedsNodeProcessor'));
  dpm($processor);
  $mappings = $importer->processor->getMappings();
  dpm($mappings);
  $targets = $importer->processor->getMappingTargets();
  dpm($targets);
  
  $disabled = unserialize(variable_get('migrate_disabled_handlers',
                                       serialize(array())));
  $class_list = mirrors_migrate_class_list('MigrateFieldHandler');
  $rows = array();
  $field_types = array();
  $default_values = array();
  foreach ($class_list as $class_name => $handler) {
    $row = array();
    $row['class'] = $class_name;
    $row['types'] = implode(', ', $handler->getTypesHandled());
    $type = implode(', ', $handler->getTypesHandled());
    
    

    $field_types[$class_name] = $type;
    
    $default_values[$class_name] = !in_array($class_name, $disabled);
    $rows[$class_name] = $row;
  }
  
  dvm($field_types);
  dpm(mirrors_bundles() );
  
  dpm($class_list);
  dpm($rows);
  
    // Make sure we have a private directory configured
    if (!variable_get('wordpress_migrate_private_path', '') &&
        !variable_get('file_private_path', '')) {
      $message = t('A private file system path must be <a href="@config">configured</a>
        to securely store your uploaded WordPress file.',
        array('@config' => url('admin/config/media/file-system')));
      $form['unconfigured'] = array(
        '#prefix' => '<div>',
        '#markup' => $message,
        '#suffix' => '</div>',
      );
      return $form;
    }
    $form['overview'] = array(
      '#prefix' => '<p>',
      '#markup' => t('This wizard supports importing into your Drupal site from ' .
        'a WordPress blog. To be able to use this wizard, you must have the ' .
        'address and credentials of the WordPress blog, or an XML file exported ' .
        'from the blog.'),
      '#suffix' => '</p>',
    );
    $form['description'] = array(
      '#prefix' => '<p>',
      '#markup' => t('You will be led through a series of steps, allowing you to ' .
        'customize what will be imported into Drupal and how it will be mapped. ' .
        'At the end of this process, a migration job will be '.
        'generated and you will be left at the Migrate dashboard, from which ' .
        'you can perform the import, monitor its progress, roll it back, etc.'),
      '#suffix' => '</p>',
    );

    return $form;
  }
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

/**
 * For a given parent class, identify and instantiate objects for any non-abstract
 * classes derived from the parent, returning an array of the objects indexed by
 * class name. The array will be ordered such that any classes with dependencies
 * are listed after the classes they are dependent on.
 *
 * @param $parent_class
 *  Name of a class from which results will be derived.
 * @return
 *  Array of objects, keyed by the class name.
 */
function mirrors_migrate_class_list($parent_class) {
  // Get info on modules implementing Migrate API
  static $module_info;
  if (!isset($module_info)) {
    $module_info = migrate_get_module_apis();
  }

  static $class_lists = array();
  if (!isset($class_lists[$parent_class])) {
    $class_lists[$parent_class] = array();
    if ($parent_class == 'MigrateDestinationHandler') {
      $handler_key = 'destination handlers';
    }
    else {
      $handler_key = 'field handlers';
    }
    // Add explicitly-registered handler classes
    foreach ($module_info as $info) {
      if (isset($info[$handler_key]) && is_array($info[$handler_key])) {
        foreach ($info[$handler_key] as $handler_class) {
          $class_lists[$parent_class][$handler_class] = new $handler_class();
        }
      }
    }
  }
  return $class_lists[$parent_class];
}
