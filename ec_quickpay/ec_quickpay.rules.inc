<?php

// $Id$

/**
 * Implementation of hook_rules_condition_info().
 */
function ec_quickpay_rules_condition_info() {
  return array(
    'ec_quickpay_condition_received' => array(
      'label' => t('Only QuickPay authorised payments remain pending'),
      'arguments' => array(
        'txn' => array('type' => 'transaction', 'label' => t('Transaction')),
      ),
      'module' => 'QuickPay',
    ),
  );
}

function ec_quickpay_condition_received($txn, $settings = NULL) {
  watchdog('debug', 'condition triggered', NULL, WATCHDOG_DEBUG);
  $res = db_query("SELECT eqrt.erid, er.status, er.type FROM {ec_quickpay_receipt_transaction} eqrt LEFT JOIN {ec_receipt} er USING (erid) WHERE eqrt.type = 'transaction' AND eqrt.etid = %d", $txn->txnid);
  $balance = 0;
  watchdog('debug', 'transaction balance ' . $txn->balance, NULL, WATCHDOG_DEBUG);
  while ($row = db_fetch_object($res)) {
    watchdog('debug', 'row ' . print_r($res, TRUE), NULL, WATCHDOG_DEBUG);    
    $receipt = ec_receipt_load($row->erid);
    watchdog('debug', 'receipt ' . print_r($receipt, TRUE), NULL, WATCHDOG_DEBUG);    
    if ($receipt->type == 'quickpay' and $receipt->status == RECEIPT_STATUS_RECEIVED) {
      $balance += $receipt->balance;
    }
  }
  watchdog('debug', 'quickpay balance ' . $balance, NULL, WATCHDOG_DEBUG);
  return $balance >= $txn->balance;
}
