End-2-end CSV exporter/importer for all entities.

Discoverable plugins (YAML):
- entity_type (node, commerce_order)
- property_type (text, uuid)
- field_type (entity_reference, text_formatted)
# contains Views & Feeds settings


Creating a bundle export/import
1 load bundle with entityapi
2 discover plugins in this order: entity_type, property_type, field_type
  > print errors/missing plugins
3 map discovers plugins op de bundle met alle metadata en velden
  > print errors/missing plugings
4 validate importer and exporter (feeds and views)
  > print errors/missing plugins
5 add exporter and importer to system, so they can be used and put to version
  control (features)
  > print admin.ui naar betreffende view/feed

Case studies
1 Chained imports (entityreference integrity)
2 Prime demo-site with users and content
3 Excel content management
4 Total content import scenario
5 Total content migration from d7 to d8
