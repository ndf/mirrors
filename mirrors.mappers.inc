<?php

/**
 * @file
 * Mappers
 */


function mirrors_getMappingTargets($type) {
  // Sad thing, we cannot call the feeds functie 'getMappingTargets', because
  // the object doesn't exist yet.
  // So we cannot initialize the object via 'feeds_importer($id)';
  //
  // We copy-paste code from the Processors
  // @2do: find a way to rely on $feeds_importer->processor->getMappingTargets()
  // @2do: add export-handlers for views (now sometimes 'broken handler' message)
  //   maybe split up views and feeds mappers
  // @2do: add split up between field_formatters and type->bundles
  if ($type == 'node') {
    return mirrors_node_getMappingTargets($type);
  }
  elseif ($type == 'user') {
    return mirrors_user_getMappingTargets($type);
  }
  elseif ($type == 'taxonomy_term') {
    return mirrors_term_getMappingTargets($type);
  }
  else {
    return mirrors_default_getMappingTargets($type);
  }
}

// @2do: call _hook for other modules to add things
function mirrors_default_getMappingTargets($type) {
  $targets = array();
  return $targets;
}

function mirrors_node_getMappingTargets() {
    $targets = array();
    $targets['nid'] = array(
      'unique' => TRUE,
    );
    $targets['title'] = array(
      'link_to_node' => FALSE,
    );
    $targets['uid'] = array(
      'link_to_user' => FALSE,
    );
    $targets['user_name'] = array(
      'type' => 'text',
    );
    $targets['user_mail'] = array(
      'type' => 'text',
    );
    $targets['status'] = array(
      'type' => 'boolean',
    );
    $targets['created'] = array(
      'type' => 'date',
    );
    $targets['promote'] = array(
      'type' => 'boolean',
    );
    $targets['sticky'] = array(
      'type' => 'boolean',
    );

    // Include language field if Locale module is enabled.
    if (module_exists('locale')) {
      $targets['language'] = array(
     );
    }

    // Include comment field if Comment module is enabled.
    if (module_exists('comment')) {
      $targets['comment'] = array(
     );
    }

    // If menu is enabled expose menu name.
    if (module_exists('menu')) {
      $targets['menu_name'] = array(
     );
      $targets['menu_parent_item'] = array(
     );
    }


    return $targets;
}

function mirrors_user_getMappingTargets() {
  $targets = array();
  $targets += array(
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
    $targets['openid'] = array();
  }
  return $targets;
}

function mirrors_term_getMappingTargets() {
  $targets = array();
  $targets += array(
    'name' => array(),
    'parent' => array(),
    //'parentguid' => array(),
    'weight' => array(),
    'description' => array(),
  );
  return $targets;
}
