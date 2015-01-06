<!-- Tab template -->
<div class="note-container">
  <?php if ($note_text): ?>
  <div class="note-text">
    <p>Note text : <span><?php print $note_text; ?></span></p>
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
</div>
<!-- /Tab template -->
