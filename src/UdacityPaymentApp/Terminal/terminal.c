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

// ---------------------------------------------
// isCardExpired
// 
// Check card expiry date.
// ---------------------------------------------
EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData)
{
    assert(cardData != NULL);
    assert(termData != NULL);

    int cardExpiryMonth = 0;
    int cardExpiryYear = 0;

    int transactionMonth = 0;
    int transactionYear = 0;

    if (sscanf_s(cardData->cardExpirationDate, "%d/%d", &cardExpiryMonth, &cardExpiryYear) != 2)
    {
        _RPTF0(_CRT_ERROR, "Unexpected error occurred during `sscanf_s`.\n");
        return EXPIRED_CARD;
    }

    // Add `2000` to the card year to normalize the date
    cardExpiryYear += 2000;

    if (sscanf_s(termData->transactionDate, "%*d/%d/%d", &transactionMonth, &transactionYear) != 2)
    {
        _RPTF0(_CRT_ERROR, "Unexpected error occurred during `sscanf_s`.\n");
        return EXPIRED_CARD;
    }

    if ((transactionYear < cardExpiryYear)
        || (transactionYear == cardExpiryYear && transactionMonth < cardExpiryMonth))
    {
        return TERMINAL_OK;
    }

    return EXPIRED_CARD;
}

// ---------------------------------------------
// getTransactionAmount
// 
// Asks user for transaction amount.
// ---------------------------------------------
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    assert(termData != NULL);

    CONSOLE_RESULT  consoleResult = CONSOLE_OK;
    float amount = 0;
    const char inputFormat[] = " %f ";

    consoleResult = ReadConsolePrompt(
        "Transaction Amount [ > 0 ]: ",
        inputFormat,
        1,
        TERMINAL_AMOUNTS_MAX_INPUT_LEN,
        &amount);
    if (consoleResult != CONSOLE_OK)
    {
        return INVALID_AMOUNT;
    }

    return TerminalProcessTransactionAmount(termData, amount);
}

// ---------------------------------------------
// isBelowMaxAmount
// 
// Check if transaction amount exceeds max.
// ---------------------------------------------
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    assert(termData != NULL);

    return termData->transAmount > termData->maxTransAmount ? EXCEED_MAX_AMOUNT : TERMINAL_OK;
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

// ---------------------------------------------
// TerminalProcessTransactionAmount
// 
// Processes the input amount and copy to output
//  if applicable.
// ---------------------------------------------
EN_terminalError_t TerminalProcessTransactionAmount(ST_terminalData_t *termData, float amount)
{
    assert(termData != NULL);

    if (amount <= 0)
    {
        return INVALID_AMOUNT;
    }

    termData->transAmount = amount;

    return TERMINAL_OK;
}
