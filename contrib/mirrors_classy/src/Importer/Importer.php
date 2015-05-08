<?php

/**
 * @file
 * Declaration of Mirrors Importer class.
 */

namespace Drupal\mirrors_classy\Importer;

use Drupal\mirrors_classy\Controller\Mirror;


class Importer extends Mirror {
  function __construct() {
    $this->label = "Importer Label";
  }
}
