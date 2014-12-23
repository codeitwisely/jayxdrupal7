<?php
/**
 * @file
 * jdt_user_notes.crud.inc
 * Implementation of CRUD FUNCTIONS.
 */

/**
 * Function to read notes from the db.
 * @param
 *
 * @return
 *   Array
 */
function _jdt_user_notes_select($user) {
  $query = db_select('jdt_user_notes', 'jun')
    ->fields('jun');
  $result = $query->execute()->fetchAssoc();
  return $result;
}

/**
 * Function to delete a note.
 * @param
 *   Array of fields
 * @return
 *   FALSE
 */
function _jdt_user_notes_del($entry = array()) {
  try {
    $query = db_delete('jdt_user_notes')
      ->condition('note_id', $entry['note_id']);
    $result = $query->execute();

    watchdog('Failed to update database. Message = %message, query= %query');)
  }
  catch (Exception $e) {
    watchdog(t('Failed to delete record in database. Message = %message, query= %query',
    array('%message' => $e->getMessage(), '%query' => $e->query_string)), 'error');
  }

  return FALSE;
}

/**
 * @param
 *   Array of fields
 * @return
 *   Array
 * Function to update a note.
 */
function _jdt_user_notes_updt($entry = array()) {
  try {
    $query = db_update('jdt_user_notes')
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
 * @param
 *   Array of fields
 * @return
 *   Array
 * Function to Add Note.
 */
function _jdt_user_notes_create($entry = array()) {
  $return_value = NULL;
  try{
    $return_value = db_insert('jdt_user_notes')
      ->fields($entry)
      ->execute();
  }
  catch (Exception $e) {
    watchdog(t('db_insert failed. Message = %message, query= %query',
    array('%message' => $e->getMessage(), '%query' => $e->query_string)), 'error');
  }
  return FALSE;
}
