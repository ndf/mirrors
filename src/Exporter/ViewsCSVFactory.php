<?php

/**
 * @file
 * Mirrors Views Factory.
 */

namespace Drupal\mirrors\Exporter;

/**
 * Class Mirrors.
 */
class ViewsCSVFactory {

  public function __construct($mirrorsMapping) {

  }

  public function createView($name, $entity_type, $entity_id, $mirrors_entity) {
    $base_table = $mirrors_entity['views']['base_table'];

    /* Display Options */
    $display_options = array();

    /* Filters */
    $display_options['filters'] = mirrors_views_filters_create($mirrors_entity, $entity_id);

    /* Relations and Sorts */
    $display_options['relationships'] = mirrors_views_relationships_create($mirrors_entity);
    $display_options['sorts'] = mirrors_views_sorts_create($mirrors_entity);

    /* Fields */
    $display_options['fields'] = mirrors_views_mapping_create($mirrors_entity, $base_table);

    $view = mirrors_views_default_template($name, $entity_type, $base_table, $display_options);

    return $view;
  }

  private function createMapping($mirrors_entity, $base_table) {
    $fields = array();

    // First Properties.
    foreach ($mirrors_entity['properties'] as $key => $field) {
      $fields[$key] = array(
        'id' => $key,
        'table' => $base_table,
        'field' => $key,
        'label' => $key,
      );
      // Extra Views Settings.
      if (isset($field['views'])) {
        foreach ((array) $field['views'] as $new => $value) {
          $fields[$key][$new] = $value;
        }
      }
    }

    // Second Fields.
    foreach ($mirrors_entity['fields'] as $key => $field) {
      $fields[$key] = array(
        'id' => $key,
        'table' => 'field_data_' . $key,
        'field' => $key,
        'label' => $key,
      );
      // Extra Views Settings.
      if (isset($field['views'])) {
        foreach ((array) $field['views'] as $new => $value) {
          $fields[$key][$new] = $value;
        }
      }
      // Extra Views Settings.
      if (isset($field['list'])) {
        $fields[$key]['separator'] = MIRRORS_DEFAULT_SEPARATOR;
      }
    }

    return $fields;

  }

  private function addField() {

  }

  private function addFilter($mirrors_entity) {
    $relationships = array();

    // Extra Views Settings.
    if (isset($mirrors_entity['views']['relationships'])) {
      foreach ((array) $mirrors_entity['views']['relationships'] as $key => $relation) {
        $relationships[$key]['id'] = $key;
        $relationships[$key]['table'] = $relation;
        $relationships[$key]['field'] = $key;
      }
    }

    return $relationships;

  }

  private function addRelationship($mirrors_entity) {
    $sorts = array();

    // Extra Views Settings.
    if (isset($mirrors_entity['views']['sorts'])) {
      foreach ((array) $mirrors_entity['views']['sorts'] as $key => $relation) {
        $sorts[$key]['id'] = $key;
        $sorts[$key]['table'] = $relation;
        $sorts[$key]['field'] = $key;
      }
    }

    return $sorts;

  }
}
