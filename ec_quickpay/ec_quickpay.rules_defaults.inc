<?php
// $Id$

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
      'rules_1' => 
      array (
        '#type' => 'rule',
        '#set' => 'event_ec_store_event_transactions_bef_save',
        '#label' => 'Authorised QuickPay orders now in picking',
        '#active' => 1,
        '#weight' => '0',
        '#status' => 'custom',
        '#conditions' => 
        array (
          0 => 
          array (
            '#type' => 'condition',
            '#settings' => 
            array (
              '#argument map' => 
              array (
                'txn' => 'txn',
              ),
            ),
            '#name' => 'ec_store_condition_is_shippable',
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
                1 => '1',
              ),
              '#argument map' => 
              array (
                'txn' => 'txn',
              ),
            ),
            '#type' => 'condition',
          ),
          2 => 
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
              'label' => 'Only QuickPay authorised payments remain',
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
          0 => 
          array (
            '#weight' => 0,
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
          ),
        ),
        '#version' => 6003,
        '#categories' => 
        array (
          0 => 'ec_quickpay',
        ),
      ),
      'rules_2' => 
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
            '#settings' => 
            array (
              '#argument map' => 
              array (
                'txn' => 'txn',
              ),
            ),
            '#type' => 'condition',
            '#name' => 'ec_store_condition_is_shippable',
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
            '#weight' => -1,
            '#negate' => 1,
          ),
          3 => 
          array (
            '#weight' => 0,
            '#type' => 'condition',
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
          4 => 
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
            '#weight' => 0,
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
          ),
        ),
        '#version' => 6003,
        '#categories' => 
        array (
          0 => 'ec_quickpay',
        ),
      ),
      'rules_4' => 
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
      'rules_5' => 
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
  );

  return $config;
  }
