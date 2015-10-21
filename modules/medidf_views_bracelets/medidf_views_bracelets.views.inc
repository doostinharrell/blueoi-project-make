<?php
/**
 * @file site_views_bracelets.views.inc
 * TODO: Enter file description here.
 */

/**
 * Implements hook_views_query_alter().
 */
function medidf_views_bracelets_views_query_alter(&$view, &$query) {
  if ( !isset($view->name) || !isset($view->current_display) ) {
    return;
  }
  if ( ($view->name != 'associated_bracelets') || ($view->current_display != 'block_1') ) {
    return;
  }
  if (isset($view->args[0]) && empty($view->args[0])) {
    return;
  }
  $query->tags[] = 'medidf_views_bracelets';
}
