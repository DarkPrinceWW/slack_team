<?php

/**
 * @file
 * A class used for slack.
 */

class Slack {

  /**
   * The Authentication token.
   *
   * @var string
   */
  public $token = '';

  /**
   * The Unix timestamp when the slack was created.
   *
   * @var integer
   */
  public $timestamp = 0;

  /**
   * Constructs a new slack.
   */
  public function __construct($values = array()) {
    if (!empty($values['token'])) {
      $this->token = $values['token'];
    }

    if (empty($this->timestamp)) {
      $this->timestamp = REQUEST_TIME;
    }
  }

  /**
   * Checks authentication and tells you who you are.
   */
  public function authTest() {
    $url = 'https://slack.com/api/auth.test';
    $settings = array(
      'token' => $this->token,
    );

    $results = $this->sendRequest($url, $settings);
    $data = slack_team_request_handler($results);
    return !empty($data);
  }

  /**
   * Performs an HTTP request.
   */
  protected function sendRequest($url, $query = array()) {
    $full_url = url($url, array('query' => $query));
    return drupal_http_request($full_url, array(
      'method' => 'POST',
      'timeout' => 30.0,
    ));
  }
}
