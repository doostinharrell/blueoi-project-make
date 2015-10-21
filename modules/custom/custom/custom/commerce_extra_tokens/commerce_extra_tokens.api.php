<?php
/**
 * Allows modules to declare their own commerce email extras table styles
 * The values returned by this hook will be used for in-line table styles.
 * Each of the styles defined by this hook should be valid in-line css.
 *
 * @return
 *  An associative array describing the in-line styles being defined. 
 *  The array contains a string for each css type with the following keys: 
 *  - "table_style": required string to set css on <table>
 *  - "th_style": required string to set css on <th>
 *  - "td_style": required string to set css on <td>
 *
 */
function hook_commerce_email_extras_table_styles_alter(&$styles) {
  $table_style = 'width: 100%; border: 1px solid #ddd; border-spacing: 0; font-family: Verdana,Geneva;';
  $th_style = 'padding: 10px 14px; background-color: #333333;border: medium none;color: #FCFCF8;';
  $td_style = 'padding: 10px 14px;	vertical-align: middle;';
  $styles = array('table_style' => $table_style, 'th_style' => $th_style, 'td_style' => $td_style);
}