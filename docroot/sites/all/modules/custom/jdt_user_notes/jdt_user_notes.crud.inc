<?php
/**
 * @file
 * jdt_user_notes.crud.inc
 * Implementation of CRUD FUNCTIONS.
 */

/**
 * Implements jdt_user_notes_update().
 * Function to update a note.
 */
function jdt_user_notes_update() {
  try {
    $count = db_update('jdt_user_notes')
      ->fields($entry)
      ->condition('note_id', $entry['note_id'])
      ->execute();
  }
  catch (Exception $e) {
    drupal_set_message(t('Failed to update database. Message = %message, query= %query',
    array('%message' => $e->getMessage(), '%query' => $e->query_string)), 'error');
  }
  return $count;
}

/**
 * Implements jdt_user_notes_delete($entry = array()).
 * Function to delete a note.
 */
function jdt_user_notes_delete($entry = array()) {
  db_delete('jdt_user_notes')
    ->condition('note_id', $entry['note_id'])
    ->execute();
}

/**
 * Implements jdt_user_notes_insert($entry = array()).
 * Function to Add Note.
 */
function jdt_user_notes_insert($entry = array()) {
  $return_value = NULL;
  try{
    $return_value = db_insert('jdt_user_notes')
      ->fields($entry)
      ->execute();
  }
  catch (Exception $e) {
    drupal_set_message(t('db_insert failed. Message = %message, query= %query',
    array('%message' => $e->getMessage(), '%query' => $e->query_string)), 'error');
  }
  return $return_value;
}

/**
 * Implements jdt_user_notes_entry_load($entry = array()).
 * Function to read notes from the db.
 */
function jdt_user_notes_entry_load($entry = array()) {
  $select = db_select('jdt_user_notes', 'jayxdrupal7_development');
  $select->fields('jayxdrupal7_development');
  // Here we add each field and value to this query.
  foreach ($entry as $field => $value) {
    $select->condition($field, $value);
  }

  return $select->execute()->fetchAll();
}
