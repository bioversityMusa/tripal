<?php
/**
 * @file
 * 
 */

class ChadoTable {
  // Specifies the table name
  private $table_name;

  // Specifies the table definition Schema API.
  private $table_schema = array();

  // List of Type 1 FK relationships that have not yet been expanded.
  private $expandable_foreign_key = array();
  
  // An array of table names in Type 2 FK relationships that can be expanded.
  private $expandable_tables = array();

  // List of nodes available via FK relationships that can be expanded
  // to get that NIDs of those objects.
  private $expandable_nodes = array();

  // List of fields in the table that have not yet been expanded. These would
  // be field that have been specifically excluded or excluded by default
  // (e.g. Text db fields that are greater than 1000 chars)
  private $expandable_fields = array();

  // If this variable is set then this record requires an insert or update
  // depending if the primary key is present.
  private $has_changed = FALSE;

  // If set to TRUE then the values cannot be changed.
  private $read_only = FALSE;

  // TODO: access controls in the future.

  public function __construct($table_name) {
    // Dynamically add each of the fields, so that the object is
    // backwards compatible with stdClass nested object created by
    // chado_generate_var() and sets proper defaults (come from schema).
    
    // e.g. for feature table 
    //   $this->uniquename = NULL:
    //   $this->is_obsolete = FALSE;
    // Retreive the schema for this table
    
    // Initialize the $table_values array.
  }

  public function insert() {

  }
  public function update() {

  }
  public function select() {

  }
  public function delete() {

  }
  public function getSchema($version) {

  }


  public function setField($field, $value) {

  }
  
  public function setFields($values = array()) {
  }
  
  public function getFields() {
    
  }
  public function getFields($fields = array()) {
  
  }
  
  // This function is used to add both types of FK relationships: 1) those
  // specified by the table itself, 2) those specified by another table but
  // links to the defined table.
  public function expandForeignKey() {
  }
  
  public function expandField() {
  }
  
  public function expandNode() {

  }
}

/**
 * 
 *
 */
class ChadoObject {

  // The contents of what is currently the result from the generate_var
  // function, but in object form: An array of table objects.
  public $values;

  // Instatiates an empty object
  public function __construct($base_table) {
    $chado_var = new ChadoTable($base_table);
  }

  // This function is used to populate the object in the same way the
  // chado_generate_var() would do.
  public function generateVar($values, $options) {
    
    return $values;
  }
  
  // This function is used to expand the object in the same way that the
  // chado_expand_var() would do.
  public function expandVar($type, $to_expand, $options) {

  }

  // This function is used to add both types of FK relationships: 1) those
  // specified by the table itself, 2) those specified by another table but
  // links to the defined table.
  public function addForeignKey(ChadoObject $object) {
  
  }
  
  // Recursively go through tables to insert/update as needed
  public function save($insert_only = TRUE) {
    
  }
  // Recursively go through tables to insert/update as needed
  public function delete($cascade = TRUE) {
    
  }
 

  // TODO: how to integrate with Symfony for MVC
  // TODO: how to integrate with Twig for templating
  
}

/**
 * 
 *
 */
class ChadoCVTerm extends ChadoObject {

  public function associateCvterm(ChadoObject $object, $field = NULL) {
     // If a field is provided then the user wants to associate a primay
     // cvterm, otherwise use the linking table.
  }
}

/**
 * 
 */
class ChadoProperty extends ChadoObject {
  public function associateProperty(ChadoObject $object) {
    
  }
}

/**
 * 
 *
 */
class ChadoRelationship extends ChadoObject {
  public function associateSubject(ChadoObject $object) {

  }
  public function associateObject(ChadoObject $object) {
  
  }
  public function associateType(ChadoCvterm $object) {
  
  }
}

/**
 *
 */
class ChadoDBxref extends  ChadoObject {
  public function associateDbxref(ChadoObject $object, $field = NULL) {
    // If a field is provided then the user wants to associate a primay
    // dbxref, otherwise use the linking table.
  }
}
// Steps:
//  Create ChadoFeature Object
//  Create ChadoCVTerm Object
//  Add Primary CVTerm to the ChadoFeature object
//    $cvterm->associate_cvterm($feature, 'type_id');
//  Add Secondary CVTerm to the ChadoFeature object
//    $cvterm->link_cvterm($feature);


class ChadoFeature extends ChadoObject {
  
  public function setSequence() {
  }
  public function getSequence() {
  }

  // etc....
}
