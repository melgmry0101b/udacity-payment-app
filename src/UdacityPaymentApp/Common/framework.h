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

#include <stdio.h>
#include <stdint.h>

// =================================
// ====== Windows API Headers ======
// =================================

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <Windows.h>
#include <crtdbg.h>

#pragma warning(pop)

#endif
