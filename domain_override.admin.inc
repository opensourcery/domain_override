<?php

/**
 * @file
 * Administration page for Domain Override module.
 */

/**
 * Administration form.
 */
function domain_override_settings_form(&$form_state) {
  $form['domain_override_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Overridable content types'),
    '#default_value' => _domain_override_overridable_types(),
    '#description' => t('The content types selected will be overridable on a per-domain basis by users with the matching "override ___ content" permission.'),
  );
  foreach (node_get_types('names') as $type => $name) {
    $form['domain_override_types']['#options'][$type] = check_plain($name);
  }
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  $form['#theme'] = 'system_settings_form';
  return $form;
}

/**
 * Submit callback. Stores settings.
 */
function domain_override_settings_form_submit($form, &$form_state) {
  foreach ($form_state['values']['domain_override_types'] as $type => $value) {
    variable_set('domain_override_type_'. $type, $value !== 0);
  }
}

