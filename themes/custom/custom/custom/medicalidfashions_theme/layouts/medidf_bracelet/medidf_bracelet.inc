<?php

/**
 * Implements hook_panels_layouts()
 */
function medicalidfashions_theme_medidf_bracelet_panels_layouts() {
  $items['medidf_bracelet'] = array(
    'title' => t('medidf_bracelet: 1 column row'),
    'category' => t('medidf_bracelet: 1'),
    // 'icon' => 'medidf_bracelet.png',
    'theme' => 'medidf_bracelet',
    'admin css' => '../../css/app.css',
    'regions' => array(
      'm_top' => t('Top'),
      'm_mid_left' => t('Middle Left'),
      'm_mid_right' => t('Middle Right'),
      'm_btm' => t('Bottom'),
    ),
  );
  return $items;
}
