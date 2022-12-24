/*-----------------------------------------------------------------*\
 *
 * card.c
 *   UdacityPaymentApp
 *     udacity-payment-app
 *
 * see LICENSE at root directory
 *
 * CREATED: 2022-12-21 06:18 PM
 * AUTHORS: Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 *
\*-----------------------------------------------------------------*/

#include "pch.h"

#include "../Application/app.h"
#include "card.h"

// =====================
// ====== Methods ======
// =====================

// ---------------------------------------------
// getCardHolderName
// 
// Asks the user for card holder name.
// ---------------------------------------------
EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
    assert(cardData != NULL);

    CONSOLE_RESULT  consoleResult                               = CONSOLE_OK;
    uint8_t         cardHolderName[CARD_HOLDER_NAME_BUF_SIZE]   = { '\0' }; // Temp to perform checks then copy to cardData.
    // NOTE: here we are reading using `c` so we can read whitespaces.
    const char      inputFormat[] = " %" STRINGIZE_EXPRESSION(CARD_HOLDER_NAME_MAX_LEN) "[^\n] ";

    consoleResult = ReadConsolePrompt(
        "Card holder Name [min. 20, max. 24]: ",
        inputFormat,
        1,
        CARD_HOLDER_NAME_MAX_LEN,
        cardHolderName,
        CARD_HOLDER_NAME_BUF_SIZE);
    if (consoleResult != CONSOLE_OK)
    {
        return WRONG_NAME;
    }

    return CardProcessGetCardHolderName(cardData, cardHolderName, CARD_HOLDER_NAME_BUF_SIZE);
}

// ---------------------------------------------
// getCardExpiryDate
// 
// Asks the user for card expiry date.
// ---------------------------------------------
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
    assert(cardData != NULL);

    // NOTE: we could use our `ReadConsolePrompt` directly to parse our date,
    //  but for integration with unit testing, we should use our processor
    //  and get a string

    CONSOLE_RESULT  consoleResult                           = CONSOLE_OK;
    uint8_t         cardExpiryDate[CARD_EXP_DATE_BUF_SIZE]  = { '\0' };
    const char      inputFormat[]                           = " %" STRINGIZE_EXPRESSION(CARD_EXP_DATE_LEN) "s ";

    consoleResult = ReadConsolePrompt(
        "Card Expiry Data [MM/YY]: ",
        inputFormat,
        1,
        CARD_EXP_DATE_LEN,
        cardExpiryDate,
        CARD_EXP_DATE_BUF_SIZE);
    if (consoleResult != CONSOLE_OK)
    {
        return WRONG_EXP_DATE;
    }

    return CardProcessCardExpiryDate(cardData, cardExpiryDate, CARD_EXP_DATE_BUF_SIZE);
}

// ---------------------------------------------
// getCardExpiryDate
// 
// Asks the user for card PAN.
// ---------------------------------------------
EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
    assert(cardData != NULL);

    // NOTE: we could use our `ReadConsolePrompt` directly to parse our date,
    //  but for integration with unit testing, we should use our processor
    //  and get a string

    CONSOLE_RESULT  consoleResult               = CONSOLE_OK;
    uint8_t         cardPAN[CARD_PAN_BUF_SIZE]  = { '\0' };
    const char      inputFormat[]               = " %" STRINGIZE_EXPRESSION(CARD_PAN_MAX_LEN) "s ";

    consoleResult = ReadConsolePrompt(
        "Card PAN [min. 16, max. 19]: ",
        inputFormat,
        1,
        CARD_PAN_MAX_LEN,
        cardPAN,
        CARD_PAN_BUF_SIZE);
    if (consoleResult != CONSOLE_OK)
    {
        return WRONG_PAN;
    }

    return CardProcessCardPAN(cardData, cardPAN, CARD_PAN_BUF_SIZE);
}

// ====================================
// ====== Implementation Methods ======
// ====================================

// NOTE: we use these implementation methods to
//  facilitate our unit testing.

// ---------------------------------------------
// CardProcessGetCardHolderName
// 
// Processes the input data and copy to output
//  if applicable.
// ---------------------------------------------
EN_cardError_t CardProcessGetCardHolderName(ST_cardData_t *cardData, const uint8_t *cardHolderName, size_t cardHolderNameSize)
{
    assert(cardData != NULL);

    size_t strLen = 0;

    if (!cardHolderName)
    {
        return WRONG_NAME;
    }

    strLen = strnlen_s(cardHolderName, cardHolderNameSize);
    if (strLen < CARD_HOLDER_NAME_MIN_LEN || strLen > CARD_HOLDER_NAME_MAX_LEN)
    {
        return WRONG_NAME;
    }

    if (strcpy_s(cardData->cardHolderName, CARD_HOLDER_NAME_BUF_SIZE, cardHolderName) != 0)
    {
        _RPTF0(_CRT_ERROR, "Unexpected error occurred during `strcpy_s`\n");
        return WRONG_NAME;
    }

    return CARD_OK;
}

// ---------------------------------------------
// CardProcessCardExpiryDate
// 
// Processes the input date and copy to output
//  if applicable.
// ---------------------------------------------
EN_cardError_t CardProcessCardExpiryDate(ST_cardData_t *cardData, const uint8_t *cardExpiryDate, size_t cardExpiryDateSize)
{
    assert(cardData != NULL);

    int month = 0;
    int year = 0;

    if (!cardExpiryDate)
    {
        return WRONG_EXP_DATE;
    }

    if (strnlen_s(cardExpiryDate, cardExpiryDateSize) != CARD_EXP_DATE_LEN)
    {
        return WRONG_EXP_DATE;
    }

    // Check the date
    if (sscanf_s(cardExpiryDate, "%d/%d", &month, &year) != 2)
    {
        return WRONG_EXP_DATE;
    }

    if (month < 1 || month > 12)
    {
        return WRONG_EXP_DATE;
    }

    if (year < 0 || year > 99)
    {
        return WRONG_EXP_DATE;
    }

    if (strcpy_s(cardData->cardExpirationDate, CARD_EXP_DATE_BUF_SIZE, cardExpiryDate) != 0)
    {
        _RPTF0(_CRT_ERROR, "Unexpected error occurred during `strcpy_s`\n");
        return WRONG_EXP_DATE;
    }

    return CARD_OK;
}

// ---------------------------------------------
// CardProcessCardPAN
// 
// Processes the input PAN and copy to output
//  if applicable.
// ---------------------------------------------
EN_cardError_t CardProcessCardPAN(ST_cardData_t *cardData, const uint8_t *cardPAN, size_t cardPANSize)
{
    assert(cardData != NULL);

    size_t strLen = 0;

    // As we are depending on the return value of `sscanf_s` to check if a check has been successful,
    //  we have to provide a dummy buffer to assign the `sscanf_s` result to, as the return value
    //  is for how many arguments has been set, and that is why we can't just use `assignment-suppressing character *`.
    char dummyPAN[CARD_PAN_BUF_SIZE] = { '\0' };

    if (!cardPAN)
    {
        return WRONG_PAN;
    }

    strLen = strnlen_s(cardPAN, cardPANSize);
    if (strLen < CARD_PAN_MIN_LEN || strLen > CARD_PAN_MAX_LEN)
    {
        return WRONG_PAN;
    }

    // Check the value is numeric
    if (sscanf_s(cardPAN, "%" STRINGIZE_EXPRESSION(CARD_PAN_MAX_LEN) "[0123456789]", dummyPAN, CARD_PAN_BUF_SIZE) != 1)
    {
        return WRONG_PAN;
    }

    if (strcpy_s(cardData->primaryAccountNumber, CARD_PAN_BUF_SIZE, cardPAN) != 0)
    {
        _RPTF0(_CRT_ERROR, "Unexpected error occurred during `strcpy_s`\n");
        return WRONG_PAN;
    }

    return CARD_OK;
}
