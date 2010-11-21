$Id$

IMPORTANT INFORMATION
=====================

The payment capture is done through a scheduled ruleset, and should
not be done in a triggered rule. 

The reason is that the "Capture payments on QuickPay transactions."
action loads and saves the transactions related to the individual
payments, to trigger allocation of the payments.

As the transaction that triggered the capture is one of those saved,
and the rules engine saves the modified transaction after rule
evaluation, this means that the transaction that was marked
"completed" by the "Mark captured QuickPay orders as completed" rule,
after capture, is overwritten by the original transaction still
"awaiting capture".

The "Capture payments on QuickPay transactions." is set to not saving
the transaction for exactly that reason, and no other transaction
modifying rules should be added to the scheduled ruleset.

ADDITIONAL SETUP
================

Before using the QuickPay module for E-Commerce 4, some adjustments
needs to be made:

1. Enable the Rules Administration UI module, if not already active.

2. At Home » Administration » Rules (admin/rules/trigger), edit the
   "Mark shipped product as completed" rule.

3. Add a condition: "Transaction allocation status".

4. Under "Arguments configuration" select "Updated transaction", and
   set "Allocation status" to "Full".

5. Save the rule.

This ensures that only transactions that have been paid in full is
automatically set to completed. Without it, transactions paid through
QuickPay would be marked completed before the payment is captured.

