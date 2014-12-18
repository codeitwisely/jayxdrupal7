<?php
/**
 * @file
 * jdt_content_type_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function jdt_content_type_article_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function jdt_content_type_article_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function jdt_content_type_article_image_default_styles() {
  $styles = array();

  // Exported image style: article_image.
  $styles['article_image'] = array(
    'name' => 'article_image',
    'label' => 'Article image',
    'effects' => array(
      1 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 200,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function jdt_content_type_article_node_info() {
  $items = array(
    'article_1' => array(
      'name' => t('Article 1'),
      'base' => 'node_content',
      'description' => t('Type de contenu permettant de créer un article'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
