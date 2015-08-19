<?php

/**
 * @file
 * Administration interface.
 */

use Drupal\mirrors\Test;
use Drupal\mirrors\OnlyHereClass;

/**
 * Admin page callback.
 */
function mirrors_admin_page() {
//  $test = new Drupal\mirrors\Test();

  $test = new Test();
  dpm($test->output());


  $onlyhere = new OnlyHereClass();
  dpm($onlyhere->output());

  return 'test composer auto-loading here';
}
