/*-----------------------------------------------------------------*\
 *
 * console.h
 *   UdacityPaymentApp
 *     udacity-payment-app
 *
 * see LICENSE at root directory
 *
 * CREATED: 2022-12-22 12:50 AM
 * AUTHORS: Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 *
\*-----------------------------------------------------------------*/

#ifndef UDACITYPAYAPP_CONSOLE_H
#define UDACITYPAYAPP_CONSOLE_H

// ===================
// ====== Types ======
// ===================

typedef enum _CONSOLE_RESULT
{
    CONSOLE_OK,
    CONSOLE_UNKNOWN_ERROR,
    CONSOLE_OUT_OF_MEMORY,
    CONSOLE_CANCELED,
    CONSOLE_EMPTY,
    CONSOLE_INVALID_INPUT
}CONSOLE_RESULT;

// =====================
// ====== Methods ======
// =====================

// ---------------------------------------------
// Console helper function the puts prompt and
//  reads user input.
//
// prompt: prompt to be shown to the user.
// inputFormat: expected input format from the
//  user, accepts scanf_s format.
// argsCount: count for format switches in
//  inputFormat.
// maxInputLength: expected maximum input length
//  of the user that satisfies all the arguments
//  not including the null terminator and
//  line feed.
// ---------------------------------------------
CONSOLE_RESULT ReadConsolePrompt(const char *prompt, const char *inputFormat, int argsCount, int maxInputLength, ...);

#endif
