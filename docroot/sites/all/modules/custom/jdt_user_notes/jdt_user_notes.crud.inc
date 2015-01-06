<?php
/**
 * @file
 * jdt_user_notes.crud.inc.
 * Implementation of CRUD FUNCTIONS.
 */

/**
 * Function to delete a note.
 *
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
 *
 * @param $entry
 *   Array of fields to be updated on the DB.
 * @return
 *   Return the number of updated rows or false.
 */
function _jdt_user_notes_updt_note($entry = array()) {
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
 * Function to add a note to an existing Article.
 *
 * @param $entry
 *   Array of fields to insert on the DB.
 * @return
 *   Return the last id inserted on the table or false.
 */
function _jdt_user_notes_create_note($entry = array()) {
  try {
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

/**
 * Grab Notes from the Database for an article.
 *
 * @param $nid
 *   The article_id.
 * @return
 *   The note_text or an empty string.
 */
function _jdt_user_notes_note($nid) {
  // Grab values from the database.
  $result = db_select('jdt_user_notes', 'jun')
    ->fields('jun')
    ->condition('article_nid', $nid, "=")
    ->execute()
    ->fetchAssoc();
  // If a note exists, return it, else return empty.
  if(isset($result['note_text'])) {
    return $result['note_text'];
  }
  return '';
}

/**
 * Grab author name for an article.
 *
 * @param $nid
 *   The article_id.
 * @return
 *   The author name or an empty string.
 */
function _jdt_user_notes_get_article_author($nid) {
  $query = db_select('node', 'n');
  $query->join('users', 'u', 'n.uid = u.uid');
  $query->fields('u', array('name'))
    ->condition('n.nid', $nid, "=");
  $result = $query->execute()->fetchAssoc();
  if(isset($result['name'])) {
    return $result['name'];
  }
  return '';
}

/**
 * This function will return the number of articles on the website.
 *
 * @param $content_type
 *   The content type that we want to filter on.
 * @return
 *   Return the Number of Articles on the site.
 */
function _jdt_user_notes_number_articles($content_type = 'article_1') {
  $query = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('n.type', $content_type, '=');
  $number_of_articles = $query
    ->countQuery()
    ->execute()
    ->fetchField();

  return $number_of_articles;
}

/**
 * This function will return the number of notes on the website.
 *
 * @return
 *   Return the number of Notes on the site.
 */
function _jdt_user_notes_number_notes() {
  $query = db_select('jdt_user_notes', 'jun')
    ->fields('jun', array('note_id'));
  $number_of_notes = $query
    ->countQuery()
    ->execute()
    ->fetchField();

  return $number_of_notes;
}

/**
 * This function will return the number of active users on the website.
 *
 * @param $active
 *   We want to filter on the active users.
 * @return
 *   Return the number of active users on the site.
 */
function _jdt_user_notes_number_users($active = 1) {
  $query = db_select('users', 'u')
    ->fields('u', array('uid'))
    ->condition('u.status', $active, '=');
  $number_of_users = $query
    ->countQuery()
    ->execute()
    ->fetchField();

  return $number_of_users;
}
