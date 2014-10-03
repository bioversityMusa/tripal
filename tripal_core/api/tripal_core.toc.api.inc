<?php 

/**
 * Sets the table of content settings for a given template.
 *  
 * @param $node_type
 *   The type of node (e.g. chado_feature, chado_stock, etc.).
 * @param $key
 *   The pane key.
 * @param $settings
 *   A settings array containing the following keys:
 *     - title:  the title of the pane
 *     - weight: an integer indicating the weight for ordering the pane
 *     - hide: set to 0 or 1 indicating if the pane should be hidden
 *     - nid: the node id if these settings should be node specific.
 */
function tripal_set_toc_pane($node_type, $key, $settings) {
  
  // Make sure the title exists
  if(!array_key_exists('title', $settings)) {
    tripal_report_error('tripal_toc', TRIPAL_ERROR, 'tripal_set_toc_pane: $settings array must have a valid title');
    return FALSE;
  }
  // TODO: make sure the key is a valid key
  // TODO: make sure 'hide' is only 0 or 1 and nothing else.
  // TODO: make sure the weight is numeric (positive or negative).
  
  // Perform the setting change in a try/catch block using a transaction.
  $transaction = db_transaction();
  try {
    // First see if this setting already exists for this node_type, key or
    // nid.
    $q = db_select('tripal_toc', 'tc')
      ->fields('tc', 'toc_item_id')
      ->condition('key', $key)
      ->condition('node_type', $node_type);
    if (array_key_exists('nid', $settings)) {
      $q->condition('nid', $settings['nid']);
    }
    $toc_item_id = $q->execute()->fetch_field();
    
    // if the setting exists then delete it so we can reset it
    if ($toc_item_id) {
      $q = db_delete('tripal_toc')
      ->condition('key', $key)
      ->condition('node_type', $node_type);
      if (array_key_exists('nid', $settings)) {
        $q->condition('nid', $settings['nid']);
      }
      $q->execute();
    }
    
    // Now add the setting
    db_insert('tripal_toc')
    ->fields(array(
      'node_type' => $node_type,
      'key' => $key,
      'title' => $settings['title'],
      'weight' => $settings['weight'],
      'nid' => $settings['nid'],
      'hide' => $settings['hide'],
    ))
    ->execute();
  }
  catch (Exception $e) {
    $transaction->rollback();
    watchdog_exception('tripal_toc', $e);
    return 0;
  } 
}