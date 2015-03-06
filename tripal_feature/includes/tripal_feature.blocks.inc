<?php


function tripal_feature_block_info() {
  
  $blocks['tripal_feature_base'] = array(
    'info'   => t('Tripal Feature Oveview'),
    'cache'  => DRUPAL_NO_CACHE,
    'status' => 1,
    'region' => 'content',
    'weight' => -100,
  );
  $blocks['tripal_feature_alignments'] = array(
    'info'   => t('Tripal Feature Alignments'),
    'cache'  => DRUPAL_NO_CACHE,
    'status' => 1,
    'region' => 'content',
  );
  $blocks['tripal_feature_analyses'] = array(
    'info'   => t('Tripal Feature Analyses'),
    'cache'  => DRUPAL_NO_CACHE,
    'status' => 1,
    'region' => 'content',
  );
  $blocks['tripal_feature_properties'] = array(
    'info'   => t('Tripal Feature Properties'),
    'cache'  => DRUPAL_NO_CACHE,
    'status' => 1,
    'region' => 'content',
  );
  $blocks['tripal_feature_publications'] = array(
    'info'   => t('Tripal Feature Publications'),
    'cache'  => DRUPAL_NO_CACHE,
    'status' => 1,
    'region' => 'content',
  );
  $blocks['tripal_feature_references'] = array(
    'info'   => t('Tripal Feature References'),
    'cache'  => DRUPAL_NO_CACHE,
    'status' => 1,
    'region' => 'content',
  );
  $blocks['tripal_feature_relationships'] = array(
    'info'   => t('Tripal Feature Relationships'),
    'cache'  => DRUPAL_NO_CACHE,
    'status' => 1,
    'region' => 'content',
  );
  $blocks['tripal_feature_sequences'] = array(
    'info'   => t('Tripal Feature Sequences'),
    'cache'  => DRUPAL_NO_CACHE,
    'status' => 1,
    'region' => 'content',
  );
  $blocks['tripal_feature_synonyms'] = array(
    'info'   => t('Tripal Feature Synonyms'),
    'cache'  => DRUPAL_NO_CACHE,
    'status' => 1,
    'region' => 'content',
  );
  $blocks['tripal_feature_terms'] = array(
    'info'   => t('Tripal Feature Terms'),
    'cache'  => DRUPAL_NO_CACHE,
    'status' => 1,
    'region' => 'content',
  );
  
  return $blocks;
}

function tripal_feature_block_view($delta = '') {
  // This example is adapted from node.module.
  $block = array();
  
  // Get the current node. If we do get a node then return the block.
  $node = menu_get_object();

  if (isset($node->nid)) {
    if ($node->type == 'chado_feature') {
      switch ($delta) {
        case 'tripal_feature_base':
          $content = theme('tripal_feature_base', array('node' => $node));
          if ($content) {
            $block['subject'] = t('Overview');
            $block['content'] = $content;
          }
          break;
        case 'tripal_feature_alignments':
          $content = theme('tripal_feature_alignments', array('node' => $node));
          if ($content) {
            $block['subject'] = t('Alignments');
            $block['content'] = $content;
          }
          break;
        case 'tripal_feature_analyses':
          $content = theme('tripal_feature_analyses', array('node' => $node));
          if ($content) {
            $block['subject'] = t('Analyses');
            $block['content'] = $content;
          }
          break;
        case 'tripal_feature_properties':
          $content = theme('tripal_feature_properties', array('node' => $node));
          if ($content) {
            $block['subject'] = t('Properties');
            $block['content'] = $content;
          }
          break;
        case 'tripal_feature_publications':
          $content = theme('tripal_feature_publications', array('node' => $node));
          if ($content) {
            $block['subject'] = t('Publications');
            $block['content'] = $content;
          }
          break;
        case 'tripal_feature_references':
          $content = theme('tripal_feature_references', array('node' => $node));
          if (trim($content)) {
            $block['subject'] = t('Cross References');
            $block['content'] = $content;
          }
          break;
        case 'tripal_feature_relationships':
          $content = theme('tripal_feature_relationships', array('node' => $node));
          if ($content) {
            $block['subject'] = t('Relationships');
            $block['content'] = $content;
          }
          break;
        case 'tripal_feature_seqence':
          $content = theme('tripal_feature_sequence', array('node' => $node));
          if ($content) {
            $block['subject'] = t('Sequences');
            $block['content'] = $content;
          }
          break;
        case 'tripal_feature_synonyms':
          $content = theme('tripal_feature_synonyms', array('node' => $node));
          if ($content) {
            $block['subject'] = t('Synonyms');
            $block['content'] = $content;
          }
          break;
        case 'tripal_feature_terms':
          $content = theme('tripal_feature_terms', array('node' => $node));
          if ($content) {
            $block['subject'] = t('Annotated Terms');
            $block['content'] = $content;
          }
          break;
      }
    }
    if ($node->type == 'chado_organism') {
      
    }
  }
  return $block;
}