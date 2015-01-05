<!-- Tab template -->
<div class="note-container">
  <?php if ($NOTE_TEXT): ?>
  <div class="note-text">
    <p>Note text : <span><?php print $NOTE_TEXT; ?></span></p>
  </div>
  <?php endif; ?>
  <?php if ($NODE_TITLE): ?>
  <div class="node-title">
    <p>Title : <span><?php print $NODE_TITLE; ?></span></p>
  </div>
  <?php endif; ?>
  <?php if ($NODE_AUTHOR): ?>
  <div class="node-author">
    <p>Author : <span><?php print $NODE_AUTHOR; ?></span></p>
  </div>
  <?php endif; ?>
</div>
<!-- /Tab template -->
