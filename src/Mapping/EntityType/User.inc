<?php
/**
 * @file
 * Contains: TaxonomyTerm.
 *
 * @todo: move this to YAML, EntityType class should discover this configuration.
 */

/**
 * Class TaxonomyTerm.
 */
class User extends EntityType implements EntityTypeInterface {

  private $properties;


  /**
   * Construct.
   */
  function __construct() {
    $this->setProperties();
  }

  /**
   * Set properties
   */
  private function setProperties() {

    $properties = array();

    // Username.
    $viewsSettings = new PropertyViewsSettings(
      array(
        'link_to_user' => FALSE,
      )
    );
    $feedsSettings = new PropertyFeedsSettings(
      array(
        'unique' => TRUE,
      )
    );
    $properties[] = new TextProperty('name', $viewsSettings, $feedsSettings);



    // Mail.
    $viewsSettings = new PropertyViewsSettings(
      array(
        'link_to_user' => FALSE,
      )
    );
    $properties[] = new TextProperty('mail', $viewsSettings, null);

    // Created.
    $properties[] = new DateProperty('created');

    // Status.
    $properties[] = new BooleanProperty('created');

    // Language.
    $viewsSettings = new PropertyViewsSettings(
      array(
        'link_to_user' => FALSE,
      )
    );
    $properties[] = new TextProperty('created', $viewsSettings, null);
  }

  /**
   * Return properties.
   *
   * @return PropertyType[]
   *   array with properties.
   */
  public function getProperties() {
    return $this->properties;
  }

  /**
   * Return Feeds settings that must be used for generating feeds exporter.
   */
  public function getImporterSettings() {
  }

  /**
   * Return Views settings that must be used for generating feeds exporter.
   */
  public function getExporterSettings() {
  }


  /**
   * Entity Declaration: user.
   *
   * Called directly from mirrors.module.
   * Use hook_mirrors_entity_types_alter() from other modules.
   */
  function mirrors_entity_types_user(&$mirrors_entity_types) {
    $mirrors_entity_types['user'] = array(
      'views' => array(
        'base_table' => 'users',
        'filters' => array(),
        'sorts' => array(
          'uid' => 'users',
        ),
      ),
      'feeds' => array(
        'processor' => 'FeedsUserProcessor',
      ),
      'properties' => array(
        'name' => array(
          'type' => 'text',
          'unique' => TRUE,
          'views' => array(
            'link_to_user' => FALSE,
          ),
        ),
        'mail' => array(
          'type' => 'text',
          'views' => array(
            'link_to_user' => '0',
          ),
        ),
        'created' => array(
          'type' => 'date',
        ),
        'status' => array(
          'type' => 'boolean',
        ),
        'language' => array(
          'type' => 'text',
          'views' => array(
            'link_to_user' => FALSE,
          ),
        ),
      ),
    );
  }

}
