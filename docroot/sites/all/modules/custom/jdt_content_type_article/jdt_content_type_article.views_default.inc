<?php
/**
 * @file
 * jdt_content_type_article.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function jdt_content_type_article_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'view_for_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'View for articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Articles';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Field: Content: Slug */
  $handler->display->display_options['fields']['field_slug']['id'] = 'field_slug';
  $handler->display->display_options['fields']['field_slug']['table'] = 'field_data_field_slug';
  $handler->display->display_options['fields']['field_slug']['field'] = 'field_slug';
  /* Field: Content: Article date */
  $handler->display->display_options['fields']['field_article_date']['id'] = 'field_article_date';
  $handler->display->display_options['fields']['field_article_date']['table'] = 'field_data_field_article_date';
  $handler->display->display_options['fields']['field_article_date']['field'] = 'field_article_date';
  $handler->display->display_options['fields']['field_article_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_article_date']['settings'] = array(
    'format_type' => 'custom_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Article image */
  $handler->display->display_options['fields']['field_article_image']['id'] = 'field_article_image';
  $handler->display->display_options['fields']['field_article_image']['table'] = 'field_data_field_article_image';
  $handler->display->display_options['fields']['field_article_image']['field'] = 'field_article_image';
  $handler->display->display_options['fields']['field_article_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_article_image']['settings'] = array(
    'image_style' => 'article_image',
    'image_link' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article_1' => 'article_1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'articles';
  $export['view_for_articles'] = $view;

  return $export;
}
