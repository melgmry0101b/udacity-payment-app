/*-----------------------------------------------------------------*\
 *
 * app.h
 *   UdacityPaymentApp
 *     udacity-payment-app
 *
 * see LICENSE at root directory
 *
 * CREATED: 2022-12-21 06:18 PM
 * AUTHORS: Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 *
\*-----------------------------------------------------------------*/

#ifndef UDACITYPAYAPP_APP_H
#define UDACITYPAYAPP_APP_H

#include "console.h"

#include "../Card/card.h"
#include "../Terminal/terminal.h"
#include "../Server/server.h"

#include "../Card/card.tests.h"
#include "../Terminal/terminal.tests.h"
#include "../Server/server.tests.h"

// ====================
// ====== Macros ======
// ====================

#define STRINGIZE(x) #x
#define STRINGIZE_EXPRESSION(x) STRINGIZE(x)

// https://stackoverflow.com/questions/3553296/sizeof-single-struct-member-in-c#comment128887232_42757140
#ifndef sizeof_field
#define sizeof_field(t, f) (sizeof(((t *)0)->f))
#endif // !sizeof_field

#define countof(c, t) (sizeof(c) / sizeof(t))

// =====================
// ====== Methods ======
// =====================

// ---------------------------------------------
// Application's Main Procedure
// ---------------------------------------------
void appStart(void);

#endif
