/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: ___Shies <gukai@bilibili.com>                                |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "main/SAPI.h"
#include "Zend/zend_API.h"
#include "Zend/zend_interfaces.h"

#include "php_buffer.h"
#include "buffer_pool.h"
#include "ext/standard/info.h"
#include "ext/standard/php_string.h"

zend_class_entry *buffer_pool_ce;


PHP_METHOD(buffer_pool, __construct)
{
    php_printf("%s", "Hello Pool!");
}


const zend_function_entry pool_methods[] = {
    PHP_ME(buffer_pool, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	{NULL, NULL, NULL}	/* Must be the last line in buffer_functions[] */
};


BUFFER_MINIT_FUNCTION(pool)
{
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, "Pool", pool_methods);
    buffer_pool_ce = zend_register_internal_class(&ce TSRMLS_CC);

	return SUCCESS;
}
