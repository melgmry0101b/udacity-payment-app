/*-----------------------------------------------------------------*\
 *
 * framework.h
 *   UdacityPaymentApp
 *     udacity-payment-app
 *
 * see LICENSE at root directory
 *
 * CREATED: 2022-12-21 05:50 PM
 * AUTHORS: Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 *
\*-----------------------------------------------------------------*/

#ifndef UDACITYPAYAPP_FRAMEWORK_H
#define UDACITYPAYAPP_FRAMEWORK_H

#pragma warning(push)

#pragma warning(disable:5105) // macro expansion producing 'defined' has undefined behavior

// ========================================
// ====== C Standard Library Headers ======
// ========================================

#define __STDC_WANT_LIB_EXT1__ 1
#define __STDC_WANT_SECURE_LIB__ 1

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if !defined(__STDC_LIB_EXT1__) && !defined(__STDC_SECURE_LIB__)
#error "The application requires secure standard C library."
#endif

// =================================
// ====== Windows API Headers ======
// =================================

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <Windows.h>
#include <crtdbg.h>

#pragma warning(pop)

#endif
