<?php

// $Id$

/**
 * @file
 * Extra eC4 QuickPay conditions for the rules module.
 */

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

/**
 * Condition callback.
 */
function ec_quickpay_condition_received($txn, $settings = NULL) {
  $res = db_query("SELECT eqrt.erid, er.status, er.type FROM {ec_quickpay_receipt_transaction} eqrt LEFT JOIN {ec_receipt} er USING (erid) WHERE eqrt.type = 'transaction' AND eqrt.etid = %d", $txn->txnid);
  $balance = 0;
  while ($row = db_fetch_object($res)) {
    $receipt = ec_receipt_load($row->erid);
    if ($receipt->type == 'quickpay' and $receipt->status == RECEIPT_STATUS_RECEIVED) {
      $balance += $receipt->balance;
    }
  }
  return $balance >= $txn->balance;
}
