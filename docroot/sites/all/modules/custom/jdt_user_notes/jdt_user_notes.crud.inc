<?php
/**
 * Implementation of CRUD FUNCTIONS.
 * @file
 * jdt_user_notes.crud.inc.
 */

/**
 * Function to read notes from the db.
 * @param
 *   The user for who we want to display results.
 * @return
 *   Array.
 */
function _jdt_user_notes_select($user) {
  $query = db_select('jdt_user_notes', 'jun')
    ->fields('u', array('name'))
    ->fields('n', array('title'))
    ->fields('jun', array('note_text'))
    ->join('node', 'n', 'jun.article_nid = n.nid')
    ->join('users', 'u', 'jun.author_uid = u.uid')
    ->condition('n.type', 'article_1', '=')
    ->condition('u.uid', $user, '=');
  $result = $query->execute()->fetchAssoc();

  return $result;
}

/**
 * Function to return the details for a note.
 * @param
 *   The note_id
 * @return
 *   Return the database entry for the note_id in parameters.
 */
function _jdt_user_notes_select($note_id) {
  $query = db_select('jdt_user_notes', 'jun')
    ->fields('u', array('author_uid',''))
    ->fields('jun', array('note_text'))
    ->join('node', 'n', 'jun.article_nid = n.nid')
    ->join('users', 'u', 'jun.author_uid = u.uid')
    ->condition('n.type', 'article_1', '=')
    ->condition('jun.note_id', $note_id, '=');
  $result = $query->execute()->fetchAssoc();

  return $result;
}
/**
 * Function to delete a note.
 * @param
 *   Array of fields.
 * @return
 *   The query or false.
 */
function _jdt_user_notes_del($entry = array()) {
  try {
    $query = db_delete('jdt_user_notes')
      ->condition('note_id', $entry['note_id']);
    $result = $query->execute();

    return $result;
  }
  catch (Exception $e) {
    watchdog(t('Failed to delete record in database. Message = %message, query= %query',
    array('%message' => $e->getMessage(), '%query' => $e->query_string)), 'error');
  }

  return FALSE;
}

/**
 * @param
 *   Array of fields to update.
 * @return
 *   Query.
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
 *   Array of fields to insert on the DB.
 * @return
 *   FALSE.
 * Function to Add Note.
 */
function _jdt_user_notes_create($entry = array()) {
  $return_value = NULL;
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
