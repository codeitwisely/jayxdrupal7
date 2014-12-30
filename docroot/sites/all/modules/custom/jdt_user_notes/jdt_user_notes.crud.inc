<?php
/**
 * @file
 * jdt_user_notes.crud.inc.
 * Implementation of CRUD FUNCTIONS.
 */

/**
 * Function to return a table entry for the jdt_user_notes table.
 * According to the note_id.
 * @param $note_id
 *   The note_id for which we want to see the db entry.
 * @return
 *   An array with the fields of the table entry according to the note_id.
 */
function _jdt_user_notes_note_select($note_id) {
  $query = db_select('jdt_user_notes', 'jun')
    ->fields('jun', array('article_nid', 'author_uid', 'note_text'))
    ->condition('jun.note_id', $note_id, '=');
  $result = $query->execute()->fetchAssoc();

  return $result;
}

/**
 * Function to load entries from the DB.
 * @param $entry
 *   Array of fields to be selected on the jdt_user_notes table.
 * @return
 *   Return results in object format.
 */
function _jdt_user_notes_entry_load($entry = array()){
  $select = db_select('jdt_user_notes', 'jun');
  $select->fields('jun', array('article_nid', 'author_uid', 'note_text'));
  // Add each field and value as a condition to this query.
  foreach ($entry as $field => $value) {
    $select->condition($field, $value);
  }

  return $select->execute()->fetchAll();
}

/**
 * Function to delete a note.
 * @param $note_id
 *   The note_id to delete.
 * @return
 *   Return the number of deleted rows or false.
 */
function _jdt_user_notes_del_note($note_id) {
  try {
    $query = db_delete('jdt_user_notes')
      ->condition('note_id', $note_id, '=');
    $result = $query->execute();

    return $result;
  }
  catch (Exception $e) {
    watchdog(t('Failed to delete record in table. Message = %message, query= %query',
    array('%message' => $e->getMessage(), '%query' => $e->query_string)), 'error');
  }

  return FALSE;
}

/**
 * Function to update a note.
 * @param $entry
 *   Array of fields to be updated on the DB.
 * @return
 *   Return the number of updated rows or false.
 */
function _jdt_user_notes_updt_note($entry = array()) {
  try {
    $query = db_update('jdt_user_notes', 'jun')
      ->fields($entry)
      ->condition('note_id', $entry['note_id']);
    $result = $query->execute();

    return $result;
  }
  catch (Exception $e) {
    watchdog(t('Failed to update database. Message = %message, query= %query',
    array('%message' => $e->getMessage(), '%query' => $e->query_string)), 'error');
  }

  return FALSE;
}

/**
 * Function to add a note to an existing Article.
 * @param $entry
 *   Array of fields to insert on the DB.
 * @return
 *   Return the last id inserted on the table or false.
 */
function _jdt_user_notes_create_note($entry = array()) {
  try{
    $return_value = db_insert('jdt_user_notes')
      ->fields($entry)
      ->execute();

    return $return_value;
  }
  catch (Exception $e) {
    watchdog(t('db_insert failed. Message = %message, query= %query',
    array('%message' => $e->getMessage(), '%query' => $e->query_string)), 'error');
  }

  return FALSE;
}
