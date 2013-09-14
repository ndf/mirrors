<?php

/**
 * @file
 * Views Related
 */

 
/**
 * Implementation of hook_views_api().
 */
function mirrors_views_api() {
  return array(
    'api' => 3,
  );
}

/**
 * Implementation of hook_views_default_views().
 */
function mirrors_views_default_views() {
  $export = array();
  
  $bundles = mirrors_get_entity_field_mappers();
  foreach ($bundles as $entity_type => $bundle) {
    foreach ($bundle as $entity_id => $entity_field_mappers) {
    
      $importer_name = "mirrors_" . $entity_type . "__" . $entity_id;
      $try = mirrors_views_get_view_config($importer_name, $entity_type, $entity_id, $entity_field_mappers);
      if ($try !== FALSE) {
        $export[$importer_name] = $try;
      }
    }
  }

  return $export;
}


/**
 * Default definition of 'myimporter'
 */ 
function mirrors_views_get_view_config($importer_name, $entity_type, $entity_id, $entity_field_mappers) {
  if ($entity_type == 'node') {
    $base_table  = 'node';
  }
  elseif ($entity_type == 'taxonomy_term') {
    $base_table  = 'taxonomy_term_data';
  }
  elseif ($entity_type == 'user') {
    $base_table  = 'users';
  }
  else {
    return FALSE;
  }
  
  // Build up the View
  $view = new view();
  $view->name = $importer_name;
  $view->description = 'Export ' . $entity_type . 's to CSV file.';
  $view->tag = 'Mirrors';
  $view->base_table = $base_table;
  $view->human_name = $importer_name;
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';

  /* Relations and Sorts */
  
  if ($entity_type == 'taxonomy_term') {
    $relationships = array();
    $sorts = array();

    // Sort only if Lineage module is enabled.
    if (module_exists('lineage')) {
      $sorts['depth'] = array(
        'id' => 'depth',
        'table' => 'taxonomy_term_lineage',
        'field' => 'depth',
      );
      $sorts['lineage'] = array(
        'id' => 'lineage',
        'table' => 'taxonomy_term_lineage',
        'field' => 'lineage',
      );
    }
    else {
      /* Relationship: Taxonomy term: Parent term */
      $relationships['parent'] = array(
        'id' => 'parent',
        'table' => 'taxonomy_term_hierarchy',
        'field' => 'parent',
      );

      /* Sort criterion: Taxonomy term: Term ID */
      $sorts['tid'] = array(
        'id' => 'tid',
        'table' => 'taxonomy_term_data',
        'field' => 'tid',
        'relationship' => 'parent',
      );
    }
    
    $handler->display->display_options['sorts'] = $sorts;
    $handler->display->display_options['relationships'] = $relationships;
  }
  
  /* Filter criterion */
  if ($entity_type == 'node') {
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
      $entity_id => $entity_id,
    );
  }
  elseif ($entity_type == 'taxonomy_term') {
    $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
    $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
    $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
    $handler->display->display_options['filters']['machine_name']['value'] = array(
      $entity_id => $entity_id,
    );
  }
  
  //** GUID Field **//
  if ($entity_type == 'node') {
    $handler->display->display_options['fields']['guid']['id'] = 'guid';
    $handler->display->display_options['fields']['guid']['table'] = 'node';
    $handler->display->display_options['fields']['guid']['field'] = 'nid';
    $handler->display->display_options['fields']['guid']['label'] = 'guid';
  }
  elseif ($entity_type == 'taxonomy_term') {
    $handler->display->display_options['fields']['guid']['id'] = 'guid';
    $handler->display->display_options['fields']['guid']['table'] = 'taxonomy_term_data';
    $handler->display->display_options['fields']['guid']['field'] = 'tid';
    $handler->display->display_options['fields']['guid']['label'] = 'guid';
  }
  elseif ($entity_type == 'user') {
    $handler->display->display_options['fields']['guid']['id'] = 'guid';
    $handler->display->display_options['fields']['guid']['table'] = 'users';
    $handler->display->display_options['fields']['guid']['field'] = 'uid';
    $handler->display->display_options['fields']['guid']['label'] = 'guid';
  }
  
  if (module_exists('menu_node_views')) {
    /* Relationship: Menu: Parent menu link id */
    $handler->display->display_options['relationships']['plid']['id'] = 'plid';
    $handler->display->display_options['relationships']['plid']['table'] = 'menu_links';
    $handler->display->display_options['relationships']['plid']['field'] = 'plid';

    /* Field: Menu: Menu name */
    $handler->display->display_options['fields']['menu_name']['id'] = 'menu_name';
    $handler->display->display_options['fields']['menu_name']['table'] = 'menu_links';
    $handler->display->display_options['fields']['menu_name']['field'] = 'menu_name';
    $handler->display->display_options['fields']['menu_name']['label'] = 'menu_name';
    /* Field: Menu: Link title */
    $handler->display->display_options['fields']['link_title_1']['id'] = 'link_title_1';
    $handler->display->display_options['fields']['link_title_1']['table'] = 'menu_links';
    $handler->display->display_options['fields']['link_title_1']['field'] = 'link_title';
    $handler->display->display_options['fields']['link_title_1']['relationship'] = 'plid';
    $handler->display->display_options['fields']['link_title_1']['label'] = 'menu_parent_item';
    $handler->display->display_options['fields']['link_title_1']['link_to_item'] = 0;
    
    /* Sort criterion: Menu: Depth */
    $handler->display->display_options['sorts']['depth']['id'] = 'depth';
    $handler->display->display_options['sorts']['depth']['table'] = 'menu_links';
    $handler->display->display_options['sorts']['depth']['field'] = 'depth';
    /* Sort criterion: Menu: Weight */
    $handler->display->display_options['sorts']['weight']['id'] = 'weight';
    $handler->display->display_options['sorts']['weight']['table'] = 'menu_links';
    $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  }
  
  //** Field Mappers **//
  foreach ($entity_field_mappers as $key => $field_mapper) {
    $mapper = array();
    
    
    // Check if Field
    if (isset($field_mapper['field']) && $field_mapper['field'] === TRUE) {
      $mapper['id'] = $key;
      $mapper['table'] = 'field_data_' . $key;
      $mapper['field'] = $key;
      $mapper['label'] = $key;
      
      $mapper = mirrors_views_set_field_formatter($mapper, $field_mapper['type']);
      
    }
    else {
      // Filter out 'relations' fields
      $arr = explode("_", $key, 2);
      $first = $arr[0];
      
      switch ($first) {
        case 'user':
        case 'menu':
          $mapper = FALSE;
          break;
        default:
          $mapper['id'] = $key;
          $mapper['table'] = $base_table;
          $mapper['field'] = $key;
          $mapper['label'] = $key;
          if (isset($field_mapper['type'])) {
            $mapper = mirrors_views_set_field_formatter($mapper, $field_mapper['type']);
            $mapper['type'] = $field_mapper['type'];
          };
          if (isset($field_mapper['link_to_user'])) {
            $mapper['link_to_user'] = $field_mapper['link_to_user'];
          };
          if (isset($field_mapper['link_to_node'])) {
            $mapper['link_to_node'] = $field_mapper['link_to_node'];
          };
      }
    }
    
    // Extras for Taxonomy Hierarchy
    if ($base_table == 'taxonomy_term_data') {
      if ($key == 'parent') {
        $mapper['field'] = 'name';
        $mapper['relationship'] = 'parent';
      }
      elseif ($key == 'parentguid') {
        $mapper['field'] = 'tid';
        $mapper['relationship'] = 'parent';
        $mapper['separator'] = '';
        $mapper['empty_zero'] = TRUE;
      }
    }
    
    if ($mapper !== FALSE) {
      $handler->display->display_options['fields'][$key] = $mapper;
    }
  }

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['separator'] = ';';
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 1;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['newline_replacement'] = '<br/>';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['style_options']['encoding'] = 'UTF-8';
  $handler->display->display_options['path'] = 'views_data_export/' . $entity_type . '/' . $importer_name . '.csv';
  $handler->display->display_options['use_batch'] = 'batch';

  return $view;
}

function mirrors_views_set_field_formatter($mapper, $field_type) {
  $mapper['type'] = $field_type;
  if ($field_type == 'boolean') {
    $mapper['type'] = 'boolean_yes_no';
    $mapper['settings'] = array(
      'format' => 'boolean',
      'custom_on' => '',
      'custom_off' => '',
      'reverse' => 0,
    );
  }
  elseif ($field_type == 'date') {
    $mapper['date_format'] = 'custom';
    $mapper['custom_date_format'] = 'U';
  }
  elseif ($field_type == 'list') {
  }
  elseif ($field_type == 'decimal') {
    $mapper['settings'] = array(
      'thousand_separator' => '',
      'decimal_separator' => '.',
      'scale' => '2',
      'prefix_suffix' => 1,
    );
  }
  elseif ($field_type == 'integer') {
    $mapper['type'] = 'number_unformatted';
  }
  elseif ($field_type == 'text_formatted') {
  }
  elseif ($field_type == 'text') {
  }
  elseif ($field_type == 'taxonomy_term') {
  }
  else {
   dvm($field_type);
  }
  
  return $mapper;
}