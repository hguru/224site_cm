<?php
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php flexslider_add('flexslider'); ?>
<?php drupal_add_js("jQuery(document).ready(function () { jQuery('.flexslider').flexslider(); });", 'inline'); ?>

<div class="flexslider">
<ul class="slides">
<?php foreach ($rows as $id => $row): ?>
  <li>
    <?php print $row; ?>
  </li>
<?php endforeach; ?>
</ul>
</div>

