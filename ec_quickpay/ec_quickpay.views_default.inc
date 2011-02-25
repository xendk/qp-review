<?php

/**
 * @file
 * Default views for ec_quickpay module.
 */

/**
 * Implementation of hook_views_default_views().
 */
function ec_quickpay_views_default_views() {
  $view = new view;
  $view->name = 'ec_transaction_awaiting_capture';
  $view->description = 'List of transactions with QuickPay payments ready to be captured.';
  $view->tag = 'ec_quickpay';
  $view->view_php = '';
  $view->base_table = 'ec_transaction';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
                              'uid' => array(
                                'label' => 'User',
                                'required' => 0,
                                'id' => 'uid',
                                'table' => 'ec_customer',
                                'field' => 'uid',
                                'relationship' => 'none',
                              ),
                            ));
  $handler->override_option('fields', array(
                              'txnid' => array(
                                'label' => 'Id',
                                'exclude' => 0,
                                'id' => 'txnid',
                                'table' => 'ec_transaction',
                                'field' => 'txnid',
                                'relationship' => 'none',
                              ),
                              'fullname' => array(
                                'label' => 'Customer',
                                'alter' => array(
                                  'alter_text' => 0,
                                  'text' => '',
                                  'make_link' => 0,
                                  'path' => 'user/[uid]',
                                  'alt' => '',
                                  'prefix' => '',
                                  'suffix' => '',
                                  'help' => '',
                                  'trim' => 0,
                                  'max_length' => '',
                                  'word_boundary' => 1,
                                  'ellipsis' => 1,
                                  'html' => 0,
                                ),
                                'exclude' => 0,
                                'include_multiline_address' => 1,
                                'id' => 'fullname',
                                'table' => 'ec_transaction_address',
                                'field' => 'fullname',
                                'relationship' => 'none',
                              ),
                              'formatted_address' => array(
                                'label' => 'Address',
                                'alter' => array(
                                  'alter_text' => 0,
                                  'text' => '',
                                  'make_link' => 0,
                                  'path' => '',
                                  'alt' => '',
                                  'prefix' => '',
                                  'suffix' => '',
                                  'help' => '',
                                  'trim' => 0,
                                  'max_length' => '',
                                  'word_boundary' => 1,
                                  'ellipsis' => 1,
                                  'html' => 0,
                                ),
                                'exclude' => 0,
                                'id' => 'formatted_address',
                                'table' => 'ec_transaction_address',
                                'field' => 'formatted_address',
                                'relationship' => 'none',
                              ),
                              'name' => array(
                                'label' => 'Name',
                                'alter' => array(
                                  'alter_text' => 1,
                                  'text' => '<strong>User:</strong> [name]',
                                  'make_link' => 0,
                                  'path' => '',
                                  'alt' => '',
                                  'prefix' => '',
                                  'suffix' => '',
                                  'help' => '',
                                  'trim' => 0,
                                  'max_length' => '',
                                  'word_boundary' => 1,
                                  'ellipsis' => 1,
                                  'html' => 0,
                                ),
                                'link_to_user' => 1,
                                'overwrite_anonymous' => 0,
                                'anonymous_text' => '',
                                'exclude' => 0,
                                'id' => 'name',
                                'table' => 'users',
                                'field' => 'name',
                                'relationship' => 'uid',
                              ),
                              'description' => array(
                                'label' => 'Workflow',
                                'alter' => array(
                                  'alter_text' => 1,
                                  'text' => '<strong>Workflow:</strong> [description]',
                                  'make_link' => 0,
                                  'path' => '',
                                  'alt' => '',
                                  'prefix' => '',
                                  'suffix' => '',
                                  'help' => '',
                                  'trim' => 0,
                                  'max_length' => '',
                                  'word_boundary' => 1,
                                  'ellipsis' => 1,
                                  'html' => 0,
                                ),
                                'exclude' => 0,
                                'id' => 'description',
                                'table' => 'ec_workflow_statuses',
                                'field' => 'description',
                                'relationship' => 'none',
                              ),
                              'allocation' => array(
                                'label' => 'Allocation Status',
                                'alter' => array(
                                  'alter_text' => 1,
                                  'text' => '<strong>Allocation:</strong> [allocation]',
                                  'make_link' => 0,
                                  'path' => '',
                                  'alt' => '',
                                  'prefix' => '',
                                  'suffix' => '',
                                  'help' => '',
                                  'trim' => 0,
                                  'max_length' => '',
                                  'word_boundary' => 1,
                                  'ellipsis' => 1,
                                  'html' => 0,
                                ),
                                'exclude' => 0,
                                'id' => 'allocation',
                                'table' => 'ec_transaction',
                                'field' => 'allocation',
                                'relationship' => 'none',
                              ),
                              'created' => array(
                                'label' => 'Created',
                                'date_format' => 'custom',
                                'custom_date_format' => 'd M y',
                                'exclude' => 0,
                                'id' => 'created',
                                'table' => 'ec_transaction',
                                'field' => 'created',
                                'relationship' => 'none',
                              ),
                              'changed' => array(
                                'label' => 'Changed',
                                'date_format' => 'custom',
                                'custom_date_format' => 'd M y',
                                'exclude' => 0,
                                'id' => 'changed',
                                'table' => 'ec_transaction',
                                'field' => 'changed',
                                'relationship' => 'none',
                              ),
                              'balance' => array(
                                'label' => 'Balance',
                                'alter' => array(
                                  'alter_text' => 0,
                                  'text' => '',
                                  'make_link' => 0,
                                  'path' => '',
                                  'alt' => '',
                                  'prefix' => '',
                                  'suffix' => '',
                                  'help' => '',
                                  'trim' => 0,
                                  'max_length' => '',
                                  'word_boundary' => 1,
                                  'ellipsis' => 1,
                                  'strip_tags' => 0,
                                  'html' => 0,
                                ),
                                'exclude' => 0,
                                'id' => 'balance',
                                'table' => 'ec_transaction',
                                'field' => 'balance',
                                'override' => array(
                                  'button' => 'Override',
                                ),
                                'relationship' => 'none',
                              ),
                              'gross' => array(
                                'label' => 'Total',
                                'exclude' => 0,
                                'id' => 'gross',
                                'table' => 'ec_transaction',
                                'field' => 'gross',
                                'relationship' => 'none',
                              ),
                              'operations' => array(
                                'label' => 'Operations',
                                'exclude' => 0,
                                'id' => 'operations',
                                'table' => 'ec_transaction',
                                'field' => 'operations',
                                'override' => array(
                                  'button' => 'Override',
                                ),
                                'relationship' => 'none',
                              ),
                            ));
  $handler->override_option('filters', array(
                              'keys' => array(
                                'operator' => 'optional',
                                'value' => '',
                                'group' => '0',
                                'exposed' => TRUE,
                                'expose' => array(
                                  'use_operator' => 0,
                                  'operator' => 'keys_op',
                                  'identifier' => 'keys',
                                  'label' => 'Search',
                                  'optional' => 1,
                                  'remember' => 0,
                                ),
                                'id' => 'keys',
                                'table' => 'search_index',
                                'field' => 'keys',
                                'relationship' => 'none',
                              ),
                              'txnid' => array(
                                'operator' => '=',
                                'value' => array(
                                  'value' => '',
                                  'min' => '',
                                  'max' => '',
                                ),
                                'group' => '0',
                                'exposed' => TRUE,
                                'expose' => array(
                                  'use_operator' => 1,
                                  'operator' => 'txnid_op',
                                  'identifier' => 'txnid',
                                  'label' => 'Transaction id',
                                  'optional' => 1,
                                  'remember' => 0,
                                ),
                                'id' => 'txnid',
                                'table' => 'ec_transaction',
                                'field' => 'txnid',
                                'relationship' => 'none',
                              ),
                              'type' => array(
                                'operator' => 'or',
                                'value' => array(
                                  'billing' => 'billing',
                                ),
                                'group' => '0',
                                'exposed' => FALSE,
                                'expose' => array(
                                  'operator' => FALSE,
                                  'label' => '',
                                ),
                                'id' => 'type',
                                'table' => 'ec_transaction_address',
                                'field' => 'type',
                                'relationship' => 'none',
                                'reduce_duplicates' => 0,
                              ),
                              'workflow' => array(
                                'operator' => 'in',
                                'value' => array(
                                  '11' => '11',
                                ),
                                'group' => '0',
                                'exposed' => FALSE,
                                'expose' => array(
                                  'operator' => 'workflow_op',
                                  'label' => 'Workflow',
                                  'use_operator' => 0,
                                  'identifier' => 'workflow',
                                  'optional' => 1,
                                  'single' => 0,
                                  'remember' => 0,
                                  'reduce' => 0,
                                ),
                                'id' => 'workflow',
                                'table' => 'ec_workflow_statuses',
                                'field' => 'workflow',
                                'relationship' => 'none',
                              ),
                              'ec_exposed_fieldset' => array(
                                'operator' => '=',
                                'value' => '',
                                'group' => '0',
                                'exposed' => FALSE,
                                'expose' => array(
                                  'operator' => FALSE,
                                  'label' => '',
                                ),
                                'id' => 'ec_exposed_fieldset',
                                'table' => 'ec_transaction',
                                'field' => 'ec_exposed_fieldset',
                                'fields' => array(
                                  'txnid' => 'txnid',
                                  'workflow' => 'workflow',
                                  'erid' => 'erid',
                                  'keys' => 0,
                                ),
                                'relationship' => 'none',
                                'fieldset_title' => 'Advanced Search',
                                'fieldset_collapsible' => 1,
                                'fieldset_collapsed' => 1,
                              ),
                              'erid' => array(
                                'operator' => '=',
                                'value' => array(
                                  'value' => '',
                                  'min' => '',
                                  'max' => '',
                                ),
                                'group' => '0',
                                'exposed' => TRUE,
                                'expose' => array(
                                  'use_operator' => 0,
                                  'operator' => 'erid_op',
                                  'identifier' => 'erid',
                                  'label' => 'Receipt Id',
                                  'optional' => 1,
                                  'remember' => 0,
                                ),
                                'id' => 'erid',
                                'table' => 'ec_receipt_allocation',
                                'field' => 'erid',
                                'relationship' => 'none',
                                'override' => array(
                                  'button' => 'Override',
                                ),
                              ),
                              'allocation' => array(
                                'operator' => 'not in',
                                'value' => array(
                                  '2' => '2',
                                ),
                                'group' => '0',
                                'exposed' => FALSE,
                                'expose' => array(
                                  'operator' => FALSE,
                                  'label' => '',
                                ),
                                'id' => 'allocation',
                                'table' => 'ec_transaction',
                                'field' => 'allocation',
                                'relationship' => 'none',
                              ),
                            ));
  $handler->override_option('access', array(
                              'type' => 'perm',
                              'perm' => 'store admin manage',
                            ));
  $handler->override_option('cache', array(
                              'type' => 'none',
                            ));
  $handler->override_option('title', 'Transactions awaiting capture');
  $handler->override_option('items_per_page', 50);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'bulk');
  $handler->override_option('style_options', array(
                              'grouping' => '',
                              'override' => 1,
                              'sticky' => 1,
                              'order' => 'desc',
                              'columns' => array(
                                'txnid' => 'txnid',
                                'fullname' => 'fullname',
                                'formatted_address' => 'fullname',
                                'name' => 'fullname',
                                'description' => 'description',
                                'allocation' => 'description',
                                'created' => 'created',
                                'changed' => 'changed',
                                'balance' => 'balance',
                                'gross' => 'gross',
                                'operations' => 'operations',
                              ),
                              'info' => array(
                                'txnid' => array(
                                  'sortable' => 1,
                                  'separator' => '',
                                ),
                                'fullname' => array(
                                  'separator' => '<br />',
                                ),
                                'formatted_address' => array(
                                  'separator' => '',
                                ),
                                'name' => array(
                                  'sortable' => 0,
                                  'separator' => '',
                                ),
                                'description' => array(
                                  'sortable' => 1,
                                  'separator' => '<br />',
                                ),
                                'allocation' => array(
                                  'sortable' => 0,
                                  'separator' => '',
                                ),
                                'created' => array(
                                  'sortable' => 1,
                                  'separator' => '',
                                ),
                                'changed' => array(
                                  'sortable' => 1,
                                  'separator' => '',
                                ),
                                'balance' => array(
                                  'sortable' => 0,
                                  'separator' => '',
                                ),
                                'gross' => array(
                                  'sortable' => 1,
                                  'separator' => '',
                                ),
                                'operations' => array(
                                  'separator' => '',
                                ),
                              ),
                              'default' => 'txnid',
                              'execution_type' => '1',
                              'display_type' => '0',
                              'skip_confirmation' => 0,
                              'display_result' => 1,
                              'merge_single_action' => 1,
                              'selected_operations' => array(
                                'ddf4517bf3eca92d5a82e2446c71e9ac' => 'ddf4517bf3eca92d5a82e2446c71e9ac',
                                '574bdf895c047b27ff1cb6207100d85a' => 0,
                                '132fddcb3f367a243bee632db31985c1' => 0,
                                '334d20af1ae7ac4b770b7ec3210b2638' => 0,
                                '52aec7fee2070ce530da1304653ae1ec' => 0,
                                'daa75f478e3093ab107e657da6620a91' => 0,
                                '0e478c1b62c1e558097ef864004b3649' => 0,
                                'c52825de28f82dfbce15265b09505c55' => 0,
                                'eccbc87e4b5ce2fe28308fd9f2a7baf3' => 0,
                                'c4ca4238a0b923820dcc509a6f75849b' => 0,
                              ),
                            ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'admin/store/awaiting_capture');
  $handler->override_option('menu', array(
                              'type' => 'normal',
                              'title' => 'Awaiting Capture',
                              'description' => 'List/search transactions awaiting QuickPay payment capture.',
                              'weight' => '0',
                              'name' => 'navigation',
                            ));
  $handler->override_option('tab_options', array(
                              'type' => 'none',
                              'title' => '',
                              'description' => '',
                              'weight' => 0,
                            ));
  $views[$view->name] = $view;

  return $views;
}