<?php

/**
 * @file
 * Declaration of Mirrors Exporter class.
 */

namespace Drupal\mirrors_classy\Exporter;

use Drupal\mirrors_classy\Controller\Mirror;


class Exporter extends Mirror {
  function __construct() {
    $this->label = "Exporter Label";
  }
}
