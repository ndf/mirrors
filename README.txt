/* There is a 'base' configuration. This one contains things like 'CSV', ';', etc.
Per entity-bundle we create a feed importer and a views-exporter.
We use fields and properties attached to an entity-bundle.

Baseline:
 1. a function that returns fields and properties for an entity-bundle, or all entity-bundles
 2. a function that creates a feed-configuration (specificly mapping) from a bundle-field-configuration
 3. a function that creates a view-configuration from a bundle-field-configuration

 4. a function that calls (1) an 'renders' the views and feeds
 5. a config-ui (on a central place) that calls 4 (default all enabled)
 6. a splitted config-ui (on entity settings page) that calls 4

 7. entity 'crud' listeners
 8. call 4 on install

========================
/mirrors.module
  mirrors_bundles() returns a nice array with bundles & field implementations that are supported by both feeds and views
  mirrors_field_types()  returns an array with supported field types. hookable
  mirrors_entity_types()  returns an array with supported entity types with their properties, views & feeds settings. hookable
      question: is a propery a field, should views&feeds settings be part of the field or the entity_type?
/field_types.inc
  hooks mirrors_field_types and returns core field types (feeds and views settings)
/entity_types.inc
  hooks mirrors_field_types and returns core entity_types (feeds and views settings, properties)
/commerce/fields_types.inc
  hooks mirrors_field_types and returns core field types
/commerce/entity_types.inc
  hooks mirrors_field_types and returns core entity_types
/mirrors_example
  core examples
/mirrors_commerce_example
  commerce examples

  ==== OR =====
/field/text.inc
/entity/taxonomy.inc
/entity/node.inc

========= full-featured EXAMPLE ====
different properties & fields (vb: boolean, text ???)
afwijkend 'table' voor field in feeds en views (vb: taxonomy_term_data ??)
