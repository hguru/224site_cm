<?php
/**
 * @file
 * cm_default_content.features.content.inc
 */

/**
 * Implements hook_content_defaults().
 */
function cm_default_content_content_defaults() {
  $content = array();

  $content['cm-footer'] = (object) array(
    'exported_path' => 'footer',
    'title' => 'Footer',
    'status' => 1,
    'promote' => 0,
    'sticky' => 0,
    'type' => 'cm_block',
    'language' => 'und',
    'created' => 1330634308,
    'comment' => 1,
    'translate' => 0,
    'machine_name' => 'cm-footer',
    'body' => array(
      'und' => array(
        0 => array(
          'value' => '<div class="footer"><div class="cell"><h3>About Cm</h3><p><img alt="" src="/profiles/cm/themes/cm_theme/logo.png" style="width: 70px; height: 81px; " /></p><p><a href="http://minimalmedia.com/products/cm" title="Cm is a web content management system based on Drupal">Cm</a>&nbsp;is a web content management system for businesses and institutions of all shapes and sizes.</p></div><div class="cell"><h3>About Minimal Media</h3><p><a href="http://minimalmedia.com" title="Minimal Media">Minimal Media</a> offers <a href="http://minimalmedia.com/website-implementation">website implementation</a>, <a href="http://minimalmedia.com/consulting">consulting</a>, <a href="http://minimalmedia.com/seo">search engine optimization</a>, <a href="http://minimalmedia.com/managed-hosting">managed hosting</a> and <a href="http://minimalmedia.com/support">support</a> services, specializing in Drupal. Over 10 years of experience in open source software development and web content management. <strong>We use powerful open source tools to implement fast, functional, beautiful websites.</strong></p><address>Minimal Media<br />1034 Fifth Ave.<br />1st Floor<br />Pittsburgh, PA 15219<br /><br />877-664-0221<br />hello@minimalmedia.com</address></div></div>',
          'summary' => '',
          'format' => 'full_html',
          'safe_value' => '<div class="footer">
<div class="cell">
<h3>About Cm</h3>
<p><img alt="" src="/profiles/cm/themes/cm_theme/logo.png" style="width: 70px; height: 81px; " /></p>
<p><a href="http://minimalmedia.com/products/cm" title="Cm is a web content management system based on Drupal">Cm</a> is a web content management system for businesses and institutions of all shapes and sizes.</p>
</div>
<div class="cell">
<h3>About Minimal Media</h3>
<p><a href="http://minimalmedia.com" title="Minimal Media">Minimal Media</a> offers <a href="http://minimalmedia.com/website-implementation">website implementation</a>, <a href="http://minimalmedia.com/consulting">consulting</a>, <a href="http://minimalmedia.com/seo">search engine optimization</a>, <a href="http://minimalmedia.com/managed-hosting">managed hosting</a> and <a href="http://minimalmedia.com/support">support</a> services, specializing in Drupal. Over 10 years of experience in open source software development and web content management. <strong>We use powerful open source tools to implement fast, functional, beautiful websites.</strong></p>
<address>Minimal Media<br />1034 Fifth Ave.<br />1st Floor<br />Pittsburgh, PA 15219
<p>877-664-0221<br /><a href="mailto:hello@minimalmedia.com">hello@minimalmedia.com</a></p></address>
</div>
</div>
',
          'safe_summary' => '',
        ),
      ),
    ),
  );

  $content['welcome-to-cm'] = (object) array(
    'exported_path' => 'welcome-cm',
    'title' => 'Welcome to Cm',
    'status' => 1,
    'promote' => 1,
    'sticky' => 0,
    'type' => 'cm_page',
    'language' => 'und',
    'created' => 1330481683,
    'comment' => 1,
    'translate' => 0,
    'machine_name' => 'welcome-to-cm',
    'body' => array(
      'und' => array(
        0 => array(
          'value' => '<h2>What is Cm?</h2><p>Cm is a Web content management platform that can be used to build a variety of websites, for institutions of all shapes and sizes.</p><h2>What can I do with Cm?</h2><p>Anything <a href="http://drupal.org">Drupal</a> can do. And some additional things Drupal can&#39;t do without installing and configuring some extra modules. Things like:</p><ul><li>Image Rotator</li><li>Rich text editor</li><li>Custom CSS and Javascript per-page</li><li>Flexible, scalable workflow: Manage a whole team of editors</li><li>Highly customizable section front layouts</li><li>Easily optimize your on-page SEO</li></ul><h2>How do I find out more?</h2><p>You are looking at a self-documenting demo site. Register and log in for editor access, and you can edit any page on this site, <a href="/node/1/edit">including this one</a>. The site is restored to it&#39;s original state every few hours. To request a dedicated demo site for your project, <a href="http://minimalmedia.com/contact">contact us</a>.</p><h2>Can you build a site for me, based on Cm?</h2><p>Yes. <a href="http://minimalmedia.com/quote">Tell us more</a> about what you need, and we&#39;ll provide you with a quote for implementation and hosting services.</p><h2>I&#39;m a Drupal rockstar. Can I build a site myself, based on Cm?</h2><p>Yes. Cm is open source software. You can get started <a href="https://github.com/minimalmedia/Cm">here</a>.</p>',
          'summary' => '',
          'format' => 'full_html',
          'safe_value' => '<h2>What is Cm?</h2>
<p>Cm is a Web content management platform that can be used to build a variety of websites, for institutions of all shapes and sizes.</p>
<h2>What can I do with Cm?</h2>
<p>Anything <a href="http://drupal.org">Drupal</a> can do. And some additional things Drupal can\'t do without installing and configuring some extra modules. Things like:</p>
<ul><li>Image Rotator</li>
<li>Rich text editor</li>
<li>Custom CSS and Javascript per-page</li>
<li>Flexible, scalable workflow: Manage a whole team of editors</li>
<li>Highly customizable section front layouts</li>
<li>Easily optimize your on-page SEO</li>
</ul><h2>How do I find out more?</h2>
<p>You are looking at a self-documenting demo site. Register and log in for editor access, and you can edit any page on this site, <a href="/node/1/edit">including this one</a>. The site is restored to it\'s original state every few hours. To request a dedicated demo site for your project, <a href="http://minimalmedia.com/contact">contact us</a>.</p>
<h2>Can you build a site for me, based on Cm?</h2>
<p>Yes. <a href="http://minimalmedia.com/quote">Tell us more</a> about what you need, and we\'ll provide you with a quote for implementation and hosting services.</p>
<h2>I\'m a Drupal rockstar. Can I build a site myself, based on Cm?</h2>
<p>Yes. Cm is open source software. You can get started <a href="https://github.com/minimalmedia/Cm">here</a>.</p>
',
          'safe_summary' => '',
        ),
      ),
    ),
  );

return $content;
}
