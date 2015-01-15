<?php
/**
 * @file
 * jdt_user_notes.crud.inc.
 * Implementation of CRUD FUNCTIONS.
 */

/**
 * Select a note for a given note_id or all notes for a given node id.
 *
 * The note author_uid must be equal to the uid of the logged user.
 *
 * @param int $note_id
 *   The note_id to load.
 * @param int $nid
 *   The note id if its given to the function parameter.
 * @param int $uid
 *   The user id if its given to the function parameter.
 *
 * @return bool
 *   Result as array of objects.
 */
function _jdt_user_notes_select_note($note_id, $nid, $uid) {
  try {
    $query = db_select('jdt_user_notes', 'jun');
    $query->fields('jun');
    if ($nid != NULL && $uid != NULL) {
      $query->condition('jun.article_nid', $nid, "=");
      $query->condition('jun.author_uid', $uid, "=");
    }
    else {
      $query->condition('jun.note_id', $note_id, "=");
    }
    $result = $query->execute()->fetchAll();
    return $result;
  }
  catch (Exception $e) {
    watchdog(t('Failed to select record in table. Message = %message, query= %query',
    array('%message' => $e->getMessage(), '%query' => $e->query_string)), 'error');
  }

  return FALSE;
}

/**
 * Delete a note.
 *
 * @param int $note_id
 *   The note_id to delete.
 *
 * @return bool
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
 * Update a note.
 *
 * @param array $entry
 *   Array of fields to be updated on the DB.
 *
 * @return bool
 *   The number of updated rows or false.
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
 * Add a note to an existing article.
 *
 * @param array $entry
 *   Array of fields to insert on the DB.
 *
 * @return bool
 *   The last id inserted on the table or false.
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
 * Return the number of articles on the website.
 *
 * @param string $content_type
 *   The content type to filter on.
 *
 * @return int
 *   The Number of Articles on the site.
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
 * Return the number of notes on the website.
 *
 * @return int
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
 * Return the number of active users on the website.
 *
 * @param int $active
 *   Filter on the active users.
 *
 * @return int
 *   The number of active users on the site.
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
