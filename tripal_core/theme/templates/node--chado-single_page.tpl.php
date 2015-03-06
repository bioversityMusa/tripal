<?php

drupal_add_css(drupal_get_path('module', 'tripal_core') . '/theme/css/tripal.single_page.css');

if($teaser) {
  print render($content);
}
else {
  $node_type = $node->type;  ?>
  
  <script type="text/javascript">
    // We do not use Drupal Behaviors because we do not want this
    // code to be executed on AJAX callbacks. This code only needs to
    // be executed once the page is ready.
    jQuery(document).ready(function($){
      
    }
  });
  </script> <?php 
  // print the table of contents. It's found in the content array 
  if (array_key_exists('tripal_toc', $content)) { ?>
    <div> <?php
      // print $content['tripal_toc']['#markup'];
      // remove the table of contents and links so thye doent show up in the
      // data section when the rest of the $content array is rendered
      unset($content['tripal_toc']);
      // we may want to add the links portion of the contents to the sidebar
      //print render($content['links']);
      unset($content['links']); ?>
    </div> <?php 
     
  } 
dpm($blocks);
  // Order the content elements by weight (should already be that way)
  // and then by title if the weights are the same.  Then print each one  
  uasort($content, 'content_sort');
  foreach ($content as $item) {
//     print theme('ctools_collapsible', array(
//       'handle' => $item['#tripal_toc_title'],
//       'content' => $item['#markup'],
//       'collapsed' => FALSE, 
//     ));
    print render($item);
  }
}

/**
 * A helper function for ordering how the content items are presented.
 * 
 * Content items are sorted first by weight and then alphabetically if the 
 * weights are the same.
 *  
 * @param $item1
 * @param $item2
 */
function content_sort($item1, $item2) {
  if ($item1['#weight'] == $item2['#weight']) {
    return strcmp($item1['#tripal_toc_title'], $item2['#tripal_toc_title']);
  }
  else {
    return ($item1['#weight'] > $item2['#weight']) ? 1 : -1; 
  }
}

