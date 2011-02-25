<?php

/**
 * @file
 * Implement default rules.
 */

/**
 * Implementation of hook_rules_defaults().
 */
function ec_quickpay_rules_defaults() {
  $config = array (
    'rules' => 
    array (
      'ec_quickpay_rules_1' => 
      array (
        '#type' => 'rule',
        '#set' => 'event_ec_store_event_transactions_save',
        '#label' => 'Schedule payment capture on QuickPay transactions.',
        '#active' => 1,
        '#weight' => '10',
        '#categories' => 
        array (
          0 => 'ec_quickpay',
        ),
        '#status' => 'custom',
        '#conditions' => 
        array (
          0 => 
          array (
            '#weight' => 0,
            '#type' => 'condition',
            '#settings' => 
            array (
              'workflow' => 
              array (
                11 => '11',
              ),
              '#argument map' => 
              array (
                'txn' => 'txn',
              ),
            ),
            '#name' => 'ec_store_condition_workflow_status',
            '#info' => 
            array (
              'label' => 'Transaction workflow status',
              'arguments' => 
              array (
                'txn' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'Transaction',
            ),
          ),
          1 => 
          array (
            '#weight' => 0,
            '#info' => 
            array (
              'label' => 'Only QuickPay authorised payments remain pending',
              'arguments' => 
              array (
                'txn' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'QuickPay',
            ),
            '#name' => 'ec_quickpay_condition_received',
            '#settings' => 
            array (
              '#argument map' => 
              array (
                'txn' => 'txn',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => 
        array (
          1 => 
          array (
            '#type' => 'action',
            '#settings' => 
            array (
              'task_identifier' => 'ec_transaction_quickpay_shipped_[txn:txn-id]',
              'task_date' => 'now',
              '#argument map' => 
              array (
                'transaction' => 'txn',
              ),
              '#eval input' => 
              array (
                'token_rules_input_evaluator' => 
                array (
                  'task_identifier' => 
                  array (
                    0 => 'txn',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_schedule_set_rules_ec_quickpay_capture',
            '#info' => 
            array (
              'arguments' => 
              array (
                'task_identifier' => 
                array (
                  'type' => 'string',
                  'label' => 'Identifier',
                  'description' => 'User provided string to identify the task. Existing tasks for this rule set with the same identifier will be replaced.',
                ),
                'task_date' => 
                array (
                  'type' => 'date',
                  'label' => 'Scheduled evaluation date',
                ),
                'transaction' => 
                array (
                  'label' => 'Transaction',
                  'type' => 'transaction',
                ),
              ),
              'label' => 'Schedule "Complete QuickPay transactions."',
              'status' => 'custom',
              'categories' => 
              array (
                0 => 'ec_quickpay',
              ),
              'module' => 'Rule Scheduler',
              'base' => 'rules_scheduler_action',
              'set' => 'rules_ec_quickpay_capture',
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'ec_quickpay_rules_3' => 
      array (
        '#type' => 'rule',
        '#set' => 'event_ec_store_event_transactions_bef_save',
        '#label' => 'QuickPay authorized, shippable orders now in picking',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => 
        array (
          0 => 'ec_quickpay',
        ),
        '#status' => 'custom',
        '#conditions' => 
        array (
          0 => 
          array (
            '#weight' => -2,
            '#info' => 
            array (
              'label' => 'Transaction is shippable',
              'arguments' => 
              array (
                'txn' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'Transaction',
            ),
            '#name' => 'ec_store_condition_is_shippable',
            '#settings' => 
            array (
              '#argument map' => 
              array (
                'txn' => 'txn',
              ),
            ),
            '#type' => 'condition',
          ),
          2 => 
          array (
            '#weight' => 0,
            '#type' => 'condition',
            '#settings' => 
            array (
              'workflow' => 
              array (
                1 => '1',
              ),
              '#argument map' => 
              array (
                'txn' => 'txn',
              ),
            ),
            '#name' => 'ec_store_condition_workflow_status',
            '#info' => 
            array (
              'label' => 'Transaction workflow status',
              'arguments' => 
              array (
                'txn' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'Transaction',
            ),
          ),
          3 => 
          array (
            '#weight' => 0,
            '#info' => 
            array (
              'label' => 'Only QuickPay authorised payments remain pending',
              'arguments' => 
              array (
                'txn' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'QuickPay',
            ),
            '#name' => 'ec_quickpay_condition_received',
            '#settings' => 
            array (
              '#argument map' => 
              array (
                'txn' => 'txn',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => 
        array (
          0 => 
          array (
            '#type' => 'action',
            '#settings' => 
            array (
              'workflow' => '10',
              '#argument map' => 
              array (
                'transaction' => 'txn',
              ),
            ),
            '#name' => 'ec_store_rules_action_set_workflow',
            '#info' => 
            array (
              'label' => 'Set transaction workflow',
              'arguments' => 
              array (
                'transaction' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'Transaction',
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'ec_quickpay_rules_6' => 
      array (
        '#type' => 'rule',
        '#set' => 'rules_ec_quickpay_capture',
        '#label' => 'Capture payments on QuickPay transactions.',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => 
        array (
          0 => 'ec_quickpay',
        ),
        '#status' => 'custom',
        '#conditions' => 
        array (
          0 => 
          array (
            '#type' => 'condition',
            '#settings' => 
            array (
              'workflow' => 
              array (
                11 => '11',
              ),
              '#argument map' => 
              array (
                'txn' => 'transaction',
              ),
            ),
            '#name' => 'ec_store_condition_workflow_status',
            '#info' => 
            array (
              'label' => 'Transaction workflow status',
              'arguments' => 
              array (
                'txn' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'Transaction',
            ),
            '#weight' => 0,
          ),
          1 => 
          array (
            '#weight' => 0,
            '#info' => 
            array (
              'label' => 'Only QuickPay authorised payments remain pending',
              'arguments' => 
              array (
                'txn' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'QuickPay',
            ),
            '#name' => 'ec_quickpay_condition_received',
            '#settings' => 
            array (
              '#argument map' => 
              array (
                'txn' => 'transaction',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => 
        array (
          0 => 
          array (
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => 
            array (
              'auto_save' => 0,
              '#argument map' => 
              array (
                'transaction' => 'transaction',
              ),
            ),
            '#name' => 'rules_core_ec_quickpay_action_transaction_capture',
            '#info' => 
            array (
              'module' => 'e-Commerce',
              'arguments' => 
              array (
                'transaction' => 
                array (
                  'label' => 'Transaction',
                  'type' => 'transaction',
                ),
              ),
              'label' => 'Capture QuickPay payments on transaction',
              'base' => 'rules_core_action_execute',
              'action_name' => 'ec_quickpay_action_transaction_capture',
              'configurable' => false,
            ),
          ),
        ),
        '#version' => 6003,
      ),
      'ec_quickpay_rules_2' => 
      array (
        '#type' => 'rule',
        '#set' => 'event_ec_store_event_transactions_bef_save',
        '#label' => 'Set non-shippable QuickPay transaction as awaiting capture',
        '#active' => 1,
        '#weight' => '0',
        '#status' => 'custom',
        '#conditions' => 
        array (
          0 => 
          array (
            '#weight' => -1,
            '#negate' => 1,
            '#info' => 
            array (
              'label' => 'Transaction is shippable',
              'arguments' => 
              array (
                'txn' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'Transaction',
            ),
            '#name' => 'ec_store_condition_is_shippable',
            '#type' => 'condition',
            '#settings' => 
            array (
              '#argument map' => 
              array (
                'txn' => 'txn',
              ),
            ),
          ),
          3 => 
          array (
            '#weight' => 0,
            0 => 
            array (
              '#weight' => 0,
              '#info' => 
              array (
                'label' => 'Transaction workflow status',
                'arguments' => 
                array (
                  'txn' => 
                  array (
                    'type' => 'transaction',
                    'label' => 'Transaction',
                  ),
                ),
                'module' => 'Transaction',
              ),
              '#name' => 'ec_store_condition_workflow_status',
              '#settings' => 
              array (
                'workflow' => 
                array (
                  1 => '1',
                  2 => '2',
                ),
                '#argument map' => 
                array (
                  'txn' => 'txn',
                ),
              ),
              '#type' => 'condition',
            ),
            '#type' => 'OR',
          ),
          4 => 
          array (
            '#type' => 'condition',
            '#settings' => 
            array (
              '#argument map' => 
              array (
                'txn' => 'txn',
              ),
            ),
            '#name' => 'ec_quickpay_condition_received',
            '#info' => 
            array (
              'label' => 'Only QuickPay authorised payments remain pending',
              'arguments' => 
              array (
                'txn' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'QuickPay',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => 
        array (
          1 => 
          array (
            '#info' => 
            array (
              'label' => 'Set transaction workflow',
              'arguments' => 
              array (
                'transaction' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'Transaction',
            ),
            '#name' => 'ec_store_rules_action_set_workflow',
            '#settings' => 
            array (
              'workflow' => '11',
              '#argument map' => 
              array (
                'transaction' => 'txn',
              ),
            ),
            '#type' => 'action',
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
        '#categories' => 
        array (
          0 => 'ec_quickpay',
        ),
      ),
      'ec_quickpay_rules_4' => 
      array (
        '#type' => 'rule',
        '#set' => 'event_ec_store_event_transactions_bef_save',
        '#label' => 'Mark shipped QuickPay orders as awaiting capture',
        '#active' => 1,
        '#weight' => '1',
        '#status' => 'custom',
        '#conditions' => 
        array (
          0 => 
          array (
            '#type' => 'condition',
            '#name' => 'ec_store_condition_workflow_status_changed',
            '#info' => 
            array (
              'label' => 'Transaction workflow status changed',
              'arguments' => 
              array (
                'txn' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
                'orig_txn' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'Transaction',
            ),
            '#weight' => 0,
          ),
          1 => 
          array (
            '#weight' => 0,
            '#info' => 
            array (
              'label' => 'Transaction workflow status',
              'arguments' => 
              array (
                'txn' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'Transaction',
            ),
            '#name' => 'ec_store_condition_workflow_status',
            '#settings' => 
            array (
              'workflow' => 
              array (
                3 => '3',
              ),
            ),
            '#type' => 'condition',
          ),
          3 => 
          array (
            '#weight' => 0,
            '#info' => 
            array (
              'label' => 'Only QuickPay authorised payments remain pending',
              'arguments' => 
              array (
                'txn' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'QuickPay',
            ),
            '#name' => 'ec_quickpay_condition_received',
            '#settings' => 
            array (
              '#argument map' => 
              array (
                'txn' => 'txn',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => 
        array (
          0 => 
          array (
            '#type' => 'action',
            '#settings' => 
            array (
              'workflow' => '11',
              '#argument map' => 
              array (
                'transaction' => 'txn',
              ),
            ),
            '#name' => 'ec_store_rules_action_set_workflow',
            '#info' => 
            array (
              'label' => 'Set transaction workflow',
              'arguments' => 
              array (
                'transaction' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'Transaction',
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
        '#categories' => 
        array (
          0 => 'ec_quickpay',
        ),
      ),
      'ec_quickpay_rules_5' => 
      array (
        '#type' => 'rule',
        '#set' => 'event_ec_store_event_transactions_bef_save',
        '#label' => 'Mark captured QuickPay orders as completed',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => 
        array (
          0 => 'ec_quickpay',
        ),
        '#status' => 'custom',
        '#conditions' => 
        array (
          0 => 
          array (
            '#weight' => -10,
            '#info' => 
            array (
              'label' => 'Transaction workflow status',
              'arguments' => 
              array (
                'txn' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'Transaction',
            ),
            '#name' => 'ec_store_condition_workflow_status',
            '#settings' => 
            array (
              'workflow' => 
              array (
                11 => '11',
              ),
              '#argument map' => 
              array (
                'txn' => 'orig_txn',
              ),
            ),
            '#type' => 'condition',
          ),
          2 => 
          array (
            '#type' => 'condition',
            '#settings' => 
            array (
              'allocation' => 
              array (
                2 => '2',
              ),
              '#argument map' => 
              array (
                'txn' => 'txn',
              ),
            ),
            '#name' => 'ec_store_condition_allocation_status',
            '#info' => 
            array (
              'label' => 'Transaction allocation status',
              'arguments' => 
              array (
                'txn' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'Transaction',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => 
        array (
          0 => 
          array (
            '#info' => 
            array (
              'label' => 'Set transaction workflow',
              'arguments' => 
              array (
                'transaction' => 
                array (
                  'type' => 'transaction',
                  'label' => 'Transaction',
                ),
              ),
              'module' => 'Transaction',
            ),
            '#name' => 'ec_store_rules_action_set_workflow',
            '#settings' => 
            array (
              'workflow' => '6',
              '#argument map' => 
              array (
                'transaction' => 'txn',
              ),
            ),
            '#type' => 'action',
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
    ),
    'rule_sets' => 
    array (
      'rules_ec_quickpay_capture' => 
      array (
        'arguments' => 
        array (
          'transaction' => 
          array (
            'label' => 'Transaction',
            'type' => 'transaction',
          ),
        ),
        'label' => 'Complete QuickPay transactions.',
        'status' => 'custom',
        'categories' => 
        array (
          0 => 'ec_quickpay',
        ),
      ),
    ),
  );
  return $config;
}
