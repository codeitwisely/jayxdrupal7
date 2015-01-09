<?php

/**
 * @file
 * Default theme implementation to display all notes for an article.
 *
 * Available variables:
 * - $notes: the note object for which we want to get the note_text field.
 * - $node_tile: The node title.
 * - $node_author: The node author.
 *
 * @see template_preprocess_jdt_user_notes()
 *
 * @ingroup themeable
 */
?>

<div class="note-container">
  <?php foreach($notes as $note): ?>

    <?php if ($note->note_text): ?>
      <div class="note-text">
        <p><?php t('Note text') ?> : <span><?php print $note->note_text; ?></span></p>
      </div>
      <?php endif; ?>

      <?php if ($node_title): ?>
      <div class="node-title">
        <p><?php t('Title') ?> : <span><?php print $node_title; ?></span></p>
      </div>
      <?php endif; ?>

      <?php if ($node_author): ?>
      <div class="node-author">
        <p><?php t('Author') ?> : <span><?php print $node_author; ?></span></p>
      </div>
      <?php endif; ?>

      <hr />
  <?php endforeach; ?>
</div>
