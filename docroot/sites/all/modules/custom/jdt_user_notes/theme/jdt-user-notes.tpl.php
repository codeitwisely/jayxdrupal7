<?php

/**
 * @file
 * Default theme implementation to display all notes for an article.
 *
 * Available variables:
 * - $notes: the note object for which we want to get the note_text field.
 * - $node_tile: The node title.
 * - $node_author: The node author.
 * - $edit : The edit link for the note.
 *
 * @see template_preprocess_jdt_user_notes()
 *
 * @ingroup themeable
 */
?>

<?php foreach($notes as $note): ?>
  <div class="note-container">
    <?php if ($note->note_text): ?>
      <div class="note-text">
        <?php print $note->note_text; ?>
      </div>
    <?php endif; ?>

    <?php if ($node_title): ?>
      <div class="node-title">
        <?php print $node_title; ?>
      </div>
    <?php endif; ?>

    <?php if ($node_author): ?>
      <div class="node-author">
        <?php print $node_author; ?>
      </div>
    <?php endif; ?>

    <?php if ($edit): ?>
      <div class="edit-link">
        <?php print $edit; ?>
      </div>
    <?php endif; ?>

    <hr />
  </div>
<?php endforeach; ?>

