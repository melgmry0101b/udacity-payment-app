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

// ---------------------------------------------
// getCardHolderName
// 
// Asks the user to for card holder name.
// ---------------------------------------------
EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
    assert(cardData != NULL);

    CONSOLE_RESULT  consoleResult                               = CONSOLE_OK;
    uint8_t         cardHolderName[CARD_HOLDER_NAME_BUF_SIZE]   = { '\0' }; // Temp to perform checks then copy to cardData.
    // NOTE: here we are reading using `c` so we can read whitespaces.
    const char      inputFormat[]                               = " %" STRINGIZE_EXPRESSION(CARD_HOLDER_NAME_MAX_LEN) "c ";

    consoleResult = ReadConsolePrompt(
        "Card holder Name [min. 20, max. 24]: ",
        inputFormat,
        1,
        CARD_HOLDER_NAME_MAX_LEN,
        cardHolderName);
    if (consoleResult != CONSOLE_OK)
    {
        return WRONG_NAME;
    }

    return CardProcessGetCardHolderName(cardData, cardHolderName, CARD_HOLDER_NAME_BUF_SIZE);
}

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
        cardExpiryDate);
    if (consoleResult != CONSOLE_OK)
    {
        return WRONG_EXP_DATE;
    }

    return CardProcessCardExpiryDate(cardData, cardExpiryDate, CARD_EXP_DATE_BUF_SIZE);
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
    return CARD_OK;
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
