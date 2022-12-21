/*-----------------------------------------------------------------*\
 *
 * main.c
 *   UdacityPaymentApp
 *     udacity-payment-app
 *
 * see LICENSE at root directory
 *
 * CREATED: 2022-12-21 08:01 PM
 * AUTHORS: Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 *
\*-----------------------------------------------------------------*/

#include "pch.h"

#include "Application/app.h"

// Entry Point
int main()
{
    // NOTE: We refrained from changing the linker's entry point to `appStart`
    //  to avoid shenanigans with CRT and default VC++ linker behavior.

    // Call application's main procedure
    appStart();

    return 0;
}
