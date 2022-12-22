/*-----------------------------------------------------------------*\
 *
 * terminal.c
 *   UdacityPaymentApp
 *     udacity-payment-app
 *
 * see LICENSE at root directory
 *
 * CREATED: 2022-12-21 06:19 PM
 * AUTHORS: Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 *
\*-----------------------------------------------------------------*/

#include "pch.h"

#include "../Application/app.h"
#include "terminal.h"

// ---------------------------------------------
// getTransactionDate
// 
// Gets transaction date from the system.
// ---------------------------------------------
EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
    assert(termData != NULL);

    uint8_t transactionDate[TERMINAL_TRANSACTION_DATE_BUF_SIZE] = { '\0' };
    time_t curTime = time(NULL);
    struct tm local_time = { 0 };

    if (!localtime_s(&local_time, &curTime))
    {
        _RPTF0(_CRT_ERROR, "Unexpected error occurred during retrieving time.\n");
        return WRONG_DATE;
    }

    if (strftime(transactionDate, TERMINAL_TRANSACTION_DATE_BUF_SIZE, "%d/%m/%Y", &local_time) == 0)
    {
        _RPTF0(_CRT_ERROR, "Unexpected error occurred during `strftime`.\n");
        return WRONG_DATE;
    }

    return TerminalProcessTransactionDate(termData, transactionDate, TERMINAL_TRANSACTION_DATE_BUF_SIZE);
}

EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData)
{
    return TERMINAL_OK;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    return TERMINAL_OK;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    return TERMINAL_OK;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData, float maxAmount)
{
    return TERMINAL_OK;
}

EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData) // Optional
{
    return TERMINAL_OK;
}

// ---------------------------------------------
// TerminalProcessTransactionDate
// 
// Processes the input date and copy to output
//  if applicable.
// ---------------------------------------------
EN_terminalError_t TerminalProcessTransactionDate(
    ST_terminalData_t *termData,
    const uint8_t *transactionDate,
    size_t transactionDateSize)
{
    assert(termData != NULL);

    int day = 0;
    int month = 0;
    int year = 0;

    if (!transactionDate)
    {
        return WRONG_DATE;
    }

    if (strnlen_s(transactionDate, transactionDateSize) != TERMINAL_TRANSACTION_DATE_LEN)
    {
        return WRONG_DATE;
    }

    // Check the date
    if (sscanf_s(transactionDate, "%d/%d/%d", &day, &month, &year) != 3)
    {
        return WRONG_DATE;
    }

    // NOTE: Here we should check on the day respecting months and leap years,
    //  but omitted for simplicity of the task.
    if (day < 1 || day > 31)
    {
        return WRONG_DATE;
    }

    if (month < 1 || month > 12)
    {
        return WRONG_DATE;
    }

    if (year < 1900 || year > 2100)
    {
        return WRONG_DATE;
    }

    if (strcpy_s(termData->transactionDate, TERMINAL_TRANSACTION_DATE_BUF_SIZE, transactionDate) != 0)
    {
        _RPTF0(_CRT_ERROR, "Unexpected error occurred during `strcpy_s`\n");
        return WRONG_DATE;
    }

    return TERMINAL_OK;
}
