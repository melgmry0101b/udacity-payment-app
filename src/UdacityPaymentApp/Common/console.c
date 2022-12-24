/*-----------------------------------------------------------------*\
 *
 * console.c
 *   UdacityPaymentApp
 *     udacity-payment-app
 *
 * see LICENSE at root directory
 *
 * CREATED: 2022-12-22 12:50 AM
 * AUTHORS: Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 *
\*-----------------------------------------------------------------*/

#include "pch.h"

#include "console.h"

// ==========================
// ====== Declarations ======
// ==========================

static void ClearStdin(void);

// =====================
// ====== Methods ======
// =====================

// ---------------------------------------------
// ReadConsolePrompt
// 
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
CONSOLE_RESULT ReadConsolePrompt(const char *prompt, const char *inputFormat, int argsCount, int maxInputLength, ...)
{
    CONSOLE_RESULT  result          = CONSOLE_OK;
    size_t          inputLength     = 0;
    char            *lastLineFeed   = NULL;
    va_list         vaArgs          = NULL;

    printf(prompt);

    int effectiveInputLength = maxInputLength + 2; // Count for '\n' and '\0'
    char *pBuffer = calloc(effectiveInputLength, sizeof(char));
    if (!pBuffer)
    {
        result = CONSOLE_OUT_OF_MEMORY;
        goto done;
    }

    // Get input and check for errors or cancellation using EOF
    // NOTE: on `fgets` success, the buffer is always null terminated,
    //  we use `fgets` as it doesn't issue a constraint error if there
    //  is still more characters in stdin, which we can handle gracefully.
    if (!fgets(pBuffer, effectiveInputLength, stdin))
    {
        // Check if the user canceled the input
        if (feof(stdin))
        {
            result = CONSOLE_CANCELED;
        }
        else
        {
            result = CONSOLE_UNKNOWN_ERROR;
        }

        clearerr_s(stdin);
        goto done;
    }

    // `fgets` won't return null if EOF has been encountered after reading characters,
    //  so check on this too!
    // We are checking for '\n' as our indicator of proper user input.
    if (feof(stdin))
    {
        result = CONSOLE_CANCELED;
        clearerr_s(stdin);
        goto done;
    }

    // Check if we got empty input
    //  We have empty input if no characters are present, or only a linefeed
    inputLength = strnlen_s(pBuffer, effectiveInputLength);
    if ((inputLength == 0) || (inputLength == 1 && pBuffer[0] == '\n'))
    {
        result = CONSOLE_EMPTY;
        goto done;
    }

    // Check if the user input is longer than expected
    //  We check for this if we don't have a linefeed followed by null.
    lastLineFeed = strrchr(pBuffer, '\n');
    if (lastLineFeed == NULL || *(lastLineFeed + 1) != '\0')
    {
        // In this case, stdin still has characters, we have to clear it
        ClearStdin();

        result = CONSOLE_INVALID_INPUT;
        goto done;
    }

    // Set the last linefeed character to null
    *(lastLineFeed) = '\0';

    // Parse the input
    va_start(vaArgs, maxInputLength);
    if (vsscanf_s(pBuffer, inputFormat, vaArgs) != argsCount)
    {
        result = CONSOLE_INVALID_INPUT;
        goto done;
    }

done:
    if (pBuffer)
    {
        free(pBuffer);
    }

    if (vaArgs)
    {
        va_end(vaArgs);
    }

    return result;
}

// =============================
// ====== Private Methods ======
// =============================

static void ClearStdin(void)
{
    // Loop reading stdin to clear it
    int ch = 0;
    do
    {
        ch = getchar();
    } while (ch != EOF && ch != '\n' && ch != 0);
    clearerr_s(stdin);
}
