<!-- Tab template -->
<div class="note-container">
  <?php if ($NOTE_TEXT): ?>
  <div class="note-text">
    <?php print $NOTE_TEXT; ?>
  </div>
  <?php endif; ?>
  <?php if ($NODE_TITLE): ?>
  <div class="node-title">
    <?php print $NODE_TITLE; ?>
  </div>
  <?php endif; ?>
  <?php if ($NODE_AUTHOR): ?>
  <div class="node-author">
    <?php print $NODE_AUTHOR; ?>
  </div>
  <?php endif; ?>
</div>
<!-- /Tab template -->
