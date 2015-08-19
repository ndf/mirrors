<?php

/**
 * @file
 * Mirrors field declaration: video_embed_field.
 */

/**
 * Field Declaration: video_embed_field.
 *
 * Called directly from mirrors.module.
 * Use hook_mirrors_field_types_alter() from other modules.
 */
function mirrors_field_types_video_embed_field(&$mirrors_field_types) {
  $mirrors_field_types['video_embed_field'] = array(
    'views' => array(
      'type' => 'video_embed_field_url',
      'settings' => array(
        'video_style' => 'normal',
      )
    ),
    'feeds' => array(),
  );
}
