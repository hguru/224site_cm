<?php

/**
 * Implement hook_install().
 *
 * Perform actions to set up the site for this profile.
 */
function cm_install() {
  include_once DRUPAL_ROOT . '/profiles/standard/standard.install';
  standard_install();
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function cm_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}

function cm_install_tasks() {
  return array(
    'cm_initialize_content_types' => array(
      'display_name' => st('Initialize Content Types'),
      'type' => 'normal',
    ),
    'cm_initialize_taxonomy_terms' => array(
      'display_name' => st('Initialize Taxonomy Terms'),
      'type' => 'normal',
    ),
    'cm_initialize_themes' => array(
      'display_name' => st('Initialize Themes'),
      'type' => 'normal',
    ),
    'cm_initialize_front_page' => array(
      'display_name' => st('Initialize Front Page'),
      'type' => 'normal',
    ),
    'cm_initialize_configuration' => array(
      'display_name' => st('Initialize Configuration'),
      'type' => 'normal',
    ),
  );
}

/**
 * Initialize default content types.
 */
function cm_initialize_content_types() {
  cm_log('Initializing content types');
  node_type_delete('page');
}

/**
 * Initialize default taxonomy terms.
 */
function cm_initialize_taxonomy_terms() {
  cm_log('Initializing taxonomy terms');
  // _cm_create_taxonomy_term($vid, $name, $tid)

  _cm_create_taxonomy_term(1, 'Sample Content', 1);
  _cm_create_taxonomy_term(1, 'Documentation', 2);
  _cm_create_taxonomy_term(1, 'Getting Started', 3);
  _cm_create_taxonomy_term(1, 'Customization', 4);
}

/**
 * Initialize default theme and admin theme.
 */
function cm_initialize_themes() {
  cm_log('Initializing themes');
  // Set the default and admin themes
  variable_set("theme_default", "cm_theme");
  //variable_set("admin_theme", "rubik");
  variable_set("node_admin_theme", '1');
  theme_enable(array("cm_theme"));
}

/**
 * Initialize the front page.
 */
function cm_initialize_front_page() {
  // Force cron to run here or else EntityFieldQuery won't find any nodes
  cm_cron_run();

  cm_log('Initializing front page');
 
  // Find the front page by Title
  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'cm_page')
    ->propertyCondition('title', 'Welcome to Cm', '=')
    ->execute();
  if ($result['node']) {
    $result = array_shift($result['node']);
    variable_set('site_frontpage', 'node/' . $result->nid); // Set the front page
  }
}

/**
 * Other configuration steps.
 */
function cm_initialize_configuration() {
  cm_log('Initializing configuration');

  variable_set('pathauto_node_pattern', '[node:title]');
  variable_set('error_level', '0');
  variable_set('jquery_update_jquery_admin_version','1.8');
}

function _cm_create_taxonomy_term($vid, $name, $tid) {
  $term = new stdClass();
  $term->name = $name;
  $term->vid = $vid;
  taxonomy_term_save($term);
  return $term->tid;
}

/**
 * Log a message, environment agnostic.
 *
 * @param $message
 *   The message to log.
 * @param $severity
 *   The severity of the message: status, warning or error.
 */
function cm_log($message, $severity = 'status') {
  if (function_exists('drush_verify_cli')) {
    $message = strip_tags($message);
    if ($severity == 'status') {
      $severity = 'ok';
    }
    elseif ($severity == 'error') {
      drush_set_error($message);
      return;
    }
    drush_log($message, $severity);
    return;
  }
  drupal_set_message($message, $severity, FALSE);
}

/**
 * Executes a cron run.
 *
 * @return
 *   TRUE if cron ran successfully.
 */
function cm_cron_run() {
  // Allow execution to continue even if the request gets canceled.
  @ignore_user_abort(TRUE);

  // Prevent session information from being saved while cron is running.
  $original_session_saving = drupal_save_session();
  drupal_save_session(FALSE);

  // Force the current user to anonymous to ensure consistent permissions on
  // cron runs.
  $original_user = $GLOBALS['user'];
  $GLOBALS['user'] = drupal_anonymous_user();

  // Try to allocate enough time to run all the hook_cron implementations.
  drupal_set_time_limit(1800);

  $return = FALSE;
  // Grab the defined cron queues.
  $queues = module_invoke_all('cron_queue_info');
  drupal_alter('cron_queue_info', $queues);

  // Try to acquire cron lock.
  if (!lock_acquire('cron', 240.0)) {
    // Cron is still running normally.
    watchdog('cron', 'Attempting to re-run cron while it is already running.', array(), WATCHDOG_WARNING);
  }
  else {
    // Make sure every queue exists. There is no harm in trying to recreate an
    // existing queue.
    foreach ($queues as $queue_name => $info) {
      DrupalQueue::get($queue_name)->createQueue();
    }
    // Register shutdown callback.
    drupal_register_shutdown_function('drupal_cron_cleanup');

    // Iterate through the modules calling their cron handlers (if any):
    foreach (module_implements('cron') as $module) {
      // Do not let an exception thrown by one module disturb another.
      try {
        module_invoke($module, 'cron');
      }
      catch (Exception $e) {
        watchdog_exception('cron', $e);
      }
    }

    // Record cron time.
    variable_set('cron_last', REQUEST_TIME);
    watchdog('cron', 'Cron run completed.', array(), WATCHDOG_NOTICE);

    // Release cron lock.
    lock_release('cron');

    // Return TRUE so other functions can check if it did run successfully
    $return = TRUE;
  }

  foreach ($queues as $queue_name => $info) {
    $function = $info['worker callback'];
    $end = time() + (isset($info['time']) ? $info['time'] : 15);
    $queue = DrupalQueue::get($queue_name);
    while (time() < $end && ($item = $queue->claimItem())) {
      $function($item->data);
      $queue->deleteItem($item);
    }
  }
  // Restore the user.
  $GLOBALS['user'] = $original_user;
  drupal_save_session($original_session_saving);

  return $return;
}

