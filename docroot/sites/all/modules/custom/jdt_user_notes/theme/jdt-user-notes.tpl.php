<!-- Tab template -->
<div class="note-container">
  <?php foreach($notes as $note): ?>

  <?php if ($note->note_text): ?>
  <div class="note-text">
    <p>Note text : <span><?php print $note->note_text; ?></span></p>
  </div>
  <?php endif; ?>

  <?php if ($node_title): ?>
  <div class="node-title">
    <p>Title : <span><?php print $node_title; ?></span></p>
  </div>
  <?php endif; ?>

  <?php if ($node_author): ?>
  <div class="node-author">
    <p>Author : <span><?php print $node_author; ?></span></p>
  </div>
  <?php endif; ?>

  <div class="add">
    <p><span><?php print $add; ?></span></p>
  </div>

  <hr />
  <?php endforeach; ?>
</div>
<!-- /Tab template -->
