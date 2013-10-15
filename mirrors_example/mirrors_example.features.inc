<?php
/**
 * @file
 * mirrors_example.features.inc
 */

/**
 * Implements hook_node_info().
 */
function mirrors_example_node_info() {
  $items = array(
    'no_fields' => array(
      'name' => t('Content no Fields'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'with_fields' => array(
      'name' => t('Content with Fields'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
