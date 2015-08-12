<?php

/**
 * @file
 * Mirrors property declaration: text.
 */

/**
 * Property Declaration: text.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_property_types_alter() from other modules.
 */
class TextProperty extends PropertyType implements PropertyTypeInterface {

  /**
   * Constructor.
   */
  public function __contruct($name, PropertyViewsSettings $viewsSettings = NULL, PropertyFeedsSettings $feedsSettings = NULL) {

  }

  /**
   * Return PropertyViewsSettings
   *
   * @return PropertyViewsSettings.
   */
  public function getPropertyViewsSettings() {
    return $this->viewsSettings;
  }

  /**
   * @param $mirrors_property_types
   */
  function mirrors_property_types_text(&$mirrors_property_types) {
    $mirrors_property_types['text'] = array(
      'views' => array(),
      'feeds' => array(),
    );
  }
}
