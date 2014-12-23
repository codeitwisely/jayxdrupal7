<?php
/**
 * @file
 * jdt_content_type_article.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function jdt_content_type_article_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'stats_informations';
  $context->description = 'Context use for the stat block';
  $context->tag = 'stats';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'jdt_user_notes-articles_info' => array(
          'module' => 'jdt_user_notes',
          'delta' => 'articles_info',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context use for the stat block');
  t('stats');
  $export['stats_informations'] = $context;

  return $export;
}
