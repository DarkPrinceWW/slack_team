<?php

/**
 * @file
 * Module administration pages.
 */

/**
 * Returns with the general configuration form.
 */
function slack_team_admin_settings($form, &$form_state) {
  $form['slack_team_token'] = array(
    '#title' => t('Authentication token'),
    '#type' => 'textfield',
    '#default_value' => variable_get('slack_team_token', 'xoxp-'),
    '#required' => TRUE,
    '#maxlength' => 51,
  );

  $form['slack_team_token_status'] = array(
    '#type' => 'item',
    '#title' => t('Status'),
    '#markup' => theme('slack_team_status', array(
      'status' => slack_team_auth_test(),
    )),
  );

  // Todo: Create a select list of existing channels.
  $form['slack_team_channel'] = array(
    '#title' => t('Channel'),
    '#type' => 'textfield',
    '#description' => 'Channel of slack team.',
    '#default_value' => variable_get('slack_team_channel', ''),
    '#maxlength' => 11,
  );

  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Show History Settings'),
  );

  $form['settings']['slack_team_days'] = array(
    '#title' => t('The range of days'),
    '#type' => 'select',
    '#options' => drupal_map_assoc(range(0, 10)),
    '#default_value' => variable_get('slack_team_days', 0),
    '#description' => 'Show message in the range of days ago. Select 0 to display all messages.',
  );

  $form['settings']['slack_team_inclusive'] = array(
    '#title' => t('Include messages with latest or oldest timestamp in results?'),
    '#type' => 'select',
    '#options' => array(
      0 => t('No'),
      1 => t('Yes'),
    ),
    '#default_value' => variable_get('slack_team_inclusive', 0),
  );

  $form['settings']['slack_team_count'] = array(
    '#title' => t('Number of messages'),
    '#type' => 'textfield',
    '#default_value' => variable_get('slack_team_count', 100),
    '#description' => 'Number of messages to return, between 1 and 1000. Default: 100',
    '#maxlength' => 4,
    '#size' => 4,
    '#element_validate' => array('_slack_team_messages_count_validate'),
  );

  $form['settings']['slack_team_unreads'] = array(
    '#title' => t('Include unread messages in the output?'),
    '#type' => 'select',
    '#options' => array(
      0 => t('No'),
      1 => t('Yes'),
    ),
    '#default_value' => variable_get('slack_team_unreads', 0),
  );

  return system_settings_form($form);
}
