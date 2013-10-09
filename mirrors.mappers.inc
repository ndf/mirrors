<?php

/**
 * @file
 * Mappers
 */


function mirrors_get_bundle_properties($bundle_type) {
  // Sad thing, we cannot call the feeds functie 'get_properties', because
  // the object doesn't exist yet.
  // So we cannot initialize the object via 'feeds_importer($id)';
  //
  // We copy-paste code from the Processors
  // @2do: find a way to rely on $feeds_importer->processor->get_properties()
  // @2do: add export-handlers for views (now sometimes 'broken handler' message)
  //   maybe split up views and feeds mappers
  // @2do: add split up between field_formatters and type->bundles
  if ($bundle_type == 'node') {
    return mirrors_node_get_properties($bundle_type);
  }
  elseif ($bundle_type == 'user') {
    return mirrors_user_get_properties($bundle_type);
  }
  elseif ($bundle_type == 'taxonomy_term') {
    return mirrors_term_get_properties($bundle_type);
  }
  elseif ($bundle_type == 'commerce_product') {
    return mirrors_commerce_product_get_properties($bundle_type);
  }
  elseif ($bundle_type == 'commerce_customer_profile') {
    return mirrors_commerce_customer_profile_get_properties($bundle_type);
  }
  else {
    //dvm('unsupported bundle type: ' . $entity_type . ' @mirrors.mappers.inc');
    return mirrors_default_get_properties($bundle_type);
  }
}

// @2do: call _hook for other modules to add things
function mirrors_default_get_properties($bundle_type) {
  $fields = array(
    'nid' => array(
      'primary_key' => TRUE,
      'field_type' => 'integer',
      'feeds' => array(
        'guid' => TRUE,
        'tamper' => array(
          'explode' => '/',
        )
      ),
    ),    
    'created' => array(
      'views' => array(
        'mapper' => array(
          'thousand_separator' => '',
          'decimal_separator' => '.',
          'scale' => '2',
          'prefix_suffix' => 1,
        )
      )
     ),
    'uid' => array(
      'data_type' => 'integer',
      'field_type' => 'property',
    ),
    'title' => array(
      'data_type' => 'integer',
      'field_type' => 'property',
    ),
  );

  $properties = array();
  return $properties;
}

function mirrors_node_get_properties() {
    $properties = array();
    $properties['nid'] = array(
      'unique' => TRUE,
      'type' => 'integer',
    );
    $properties['title'] = array(
      'link_to_node' => FALSE,
    );
    $properties['uid'] = array(
      'link_to_user' => FALSE,
    );
    $properties['user_name'] = array(
      'type' => 'text',
    );
    $properties['user_mail'] = array(
      'type' => 'text',
    );
    $properties['status'] = array(
      'type' => 'boolean',
    );
    $properties['created'] = array(
      'type' => 'date',
    );
    $properties['promote'] = array(
      'type' => 'boolean',
    );
    $properties['sticky'] = array(
      'type' => 'boolean',
    );

    // Include language field if Locale module is enabled.
    if (module_exists('locale')) {
      $properties['language'] = array(
     );
    }

    // Include comment field if Comment module is enabled.
    if (module_exists('comment')) {
      $properties['comment'] = array(
     );
    }

    // If menu is enabled expose menu name.
    if (module_exists('menu')) {
      $properties['menu_name'] = array(
     );
      $properties['menu_parent_item'] = array(
     );
    }


    return $properties;
}

function mirrors_user_get_properties() {
  $properties = array();
  $properties += array(
    'name' => array(),
    'mail' => array(),
    'created' => array(
      'date_format' => 'custom',
      'custom_date_format' => 'U',
     ),
    //'pass' => array(),
    'status' => array(),
    'language' => array(),
  );
  if (module_exists('openid')) {
    $properties['openid'] = array();
  }
  return $properties;
}

function mirrors_term_get_properties() {
  $properties = array();
  $properties += array(
    'name' => array(),
    'parent' => array(),
    //'parentguid' => array(),
    'weight' => array(),
    'description' => array(),
  );
  return $properties;
}

function mirrors_commerce_product_get_properties() {
    $properties = array();
    $properties['sku'] = array(
      'type' => 'integer',
      'unique' => TRUE,
    );
    $properties['title'] = array(
      'type' => 'text',
      'link_to_node' => FALSE,
    );
    $properties['status'] = array(
      'type' => 'boolean',
    );

    return $properties;
}

function mirrors_commerce_customer_profile_get_properties() {
    $properties = array();
    $properties['uid'] = array(
      'type' => 'integer',
      'unique' => TRUE,
      'relationship' => 'uid',
      'table' => 'users',
    );
    $properties['status'] = array(
      'type' => 'boolean',
    );
    
    // Hard Coded Addressfield
    // We use patch 'https://drupal.org/node/991834#comment-7857873' for Address component Views support
    // Out-commented field are not supported by Views (as of 16-sep-2013)
    $properties['administrative_area'] = array(
      'type' => 'addressfield',
    );
    $properties['country'] = array(
      'type' => 'addressfield',
    );
    // $properties['data'] = array(
      // 'type' => 'addressfield',
    // );
    // $properties['dependent_locality'] = array(
      // 'type' => 'addressfield',
    // );
    $properties['first_name'] = array(
      'type' => 'addressfield',
    );
    $properties['last_name'] = array(
      'type' => 'addressfield',
    );
    $properties['locality'] = array(
      'type' => 'addressfield',
    );
    $properties['name_line'] = array(
      'type' => 'addressfield',
    );
    $properties['organisation_name'] = array(
      'type' => 'addressfield',
    );
    $properties['postal_code'] = array(
      'type' => 'addressfield',
    );
    $properties['premise'] = array(
      'type' => 'addressfield',
    );
    // $properties['sub_administrative_area'] = array(
      // 'type' => 'addressfield',
    // );
    // $properties['sub_premise'] = array(
      // 'type' => 'addressfield',
    // );
    $properties['thoroughfare'] = array(
      'type' => 'addressfield',
    );
    
    return $properties;
}