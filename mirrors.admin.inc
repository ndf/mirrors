<?php

/**
 * @file
 * Administration interface.
 */

use Drupal\mirrors\Test;
use Drupal\mirrors\OnlyHereClass;

/**
 * Admin page callback.
 */
function mirrors_admin_page() {
//  $test = new Drupal\mirrors\Test();


  ctools_include('plugins');
  $discover_plugins['entity_type'] = ctools_get_plugins('mirrors', 'entity_type');
  $discover_plugins['field_type'] = ctools_get_plugins('mirrors', 'field_type');
  $discover_plugins['property_type'] = ctools_get_plugins('mirrors', 'property_type');
  dpm($discover_plugins);

  $test = new Test();
  dpm($test->output());


  $onlyhere = new OnlyHereClass();
  dpm($onlyhere->output());

  $property_types = [];
  $bundles = field_info_bundles();
  foreach ($bundles as $entity_type => $bundles) {
    $entity_type_wrapper = entity_metadata_wrapper($entity_type);
    $entity_type_properties = $entity_type_wrapper->getPropertyInfo();
    foreach ($entity_type_properties as $property => $type) {
//      dpm($p['type']);

      if (isset($type['type'])) {
        $property_types[$property] = $type['type'];
      }
    }
//    dpm($entity_type_wrapper->getPropertyInfo());
//    foreach ($bundles as $bundle => $bundle_metadata) {
//      $wrapper = entity_metadata_wrapper($entity_type, $bundle);
//      dpm($wrapper->getPropertyInfo());
//    }
  }
//  sort($property_types);
  dpm($property_types);


  dpm(field_info_bundles());
  dpm(field_info_fields());
  dpm(field_info_instances());
  dpm(field_info_field_map());
  dpm(entity_get_info());


  $field_types = [];
  $fields = field_info_fields();
  foreach ($fields as $field_machine_name => $field_settings) {
    $field_types[$field_machine_name] = $field_settings['type'];
  }
  dpm($field_types);

  return 'test composer auto-loading here';
}
