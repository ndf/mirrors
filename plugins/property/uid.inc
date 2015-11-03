<?php

/**
 * @file
 * Mirrors property plugin declaration.
 *
 * When using this plugin, you must ensure exporting View has a relationship
 * to the users table defined.
 *
 * @todo: make it possible to set global Views and Feeds things, instead of
 * only things on field-level.
 */

/**
 * Property Declaration: user.
 */
$plugin = array(
  'title' => t('User'),
  'category' => 'Property',
  'views' => array(
    'field' => 'name',
    'relationship' => 'uid',
    'table' => 'users',
    'id' => 'name',
    'link_to_user' => FALSE,
  ),
  'feeds' => array(
    'target' => 'SELF:username_mapper',
  ),
);
