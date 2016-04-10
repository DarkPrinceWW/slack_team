<?php

/**
 * @file
 * A class used for slack channels.
 */

class SlackChannels extends Slack {

  /**
   * Channel to fetch history for.
   *
   * @var string
   */
  public $channel = '';

  /**
   * End of time range of messages to include in results.
   *
   * @var integer
   */
  public $latest = 0;

  /**
   * Start of time range of messages to include in results.
   *
   * @var integer
   */
  public $oldest = 0;

  /**
   * Include messages with latest or oldest timestamp in results.
   *
   * @var integer
   */
  public $inclusive = 0;

  /**
   * Number of messages to return.
   *
   * @var integer
   */
  public $count = 0;

  /**
   * Include unread_count_display in the output?
   *
   * @var integer
   */
  public $unreads = 0;

  /**
   * Include unread_count_display in the output?
   *
   * @var integer
   */
  public $excludeArchived = 0;

  /**
   * Constructs a new slack channels.
   */
  public function __construct($values = array()) {
    parent::__construct($values);

    // Set initial values.
    foreach ($values as $key => $value) {
      $this->$key = $value;
    }
  }

  /**
   * Return history of messages and events from a channel.
   */
  public function getHistory() {
    $url = 'https://slack.com/api/channels.history';
    $settings = array(
      'token' => $this->token,
      'channel' => $this->channel,
      'latest' => $this->latest,
      'oldest' => $this->oldest,
      'inclusive' => $this->inclusive,
      'count' => $this->count,
      'unreads' => $this->unreads,
    );
    return $this->sendRequest($url, $settings);
  }

  /**
   * Return lists all channels in a Slack team.
   */
  public function getList() {
    $url = 'https://slack.com/api/channels.list';
    $settings = array(
      'token' => $this->token,
    );
    return $this->sendRequest($url, $settings);
  }
}
