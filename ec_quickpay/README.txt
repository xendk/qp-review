$Id$

IMPORTANT INFORMATION
=====================

In order to use the supplied automatic capture rule, E-Commerce
(4.0-RC15) needs to be patched to avoid transactions being overwritten
with previous state. The patch can be obtained at
http://drupal.org/node/697832 .

Rules that might trigger allocation of receipts (like the capture
rule) must be triggered "After transaction saved" and not before.

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

