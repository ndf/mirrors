<?php

/**
 * @file
 * Declaration of Mirror class.
 */

namespace Drupal\mirrors_classy;

class Mirror {

  protected $label;

  function __construct() {
    $this->label = "A Label";
  }

  public function getLabel() {
    return $this->label;
  }

  public function setLabel($label) {
    $this->label = (string) $label;
  }
}
