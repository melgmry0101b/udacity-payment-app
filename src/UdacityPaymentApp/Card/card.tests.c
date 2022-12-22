/*-----------------------------------------------------------------*\
 *
 * card.tests.c
 *   UdacityPaymentApp
 *     udacity-payment-app
 *
 * see LICENSE at root directory
 *
 * CREATED: 2022-12-21 10:57 PM
 * AUTHORS: Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 *
\*-----------------------------------------------------------------*/

#include "pch.h"

#include "../Application/app.h"
#include "card.tests.h"

// ==========================
// ====== Declarations ======
// ==========================

bool TestCase_GetCardHolderName_ProperName(void);
bool TestCase_GetCardHolderName_NullName(void);
bool TestCase_GetCardHolderName_LessThanMin(void);
bool TestCase_GetCardHolderName_MoreThanMax(void);

// =====================
// ====== Methods ======
// =====================

// ---------------------------------------------
// getCardHolderNameTest
// 
// Tests getCardHolderName
//  through CardProcessGetCardHolderName
// ---------------------------------------------
void getCardHolderNameTest(void)
{
    puts("");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("Tester Name: " _APP_VER_COMPANY);
    puts("Function Name: " STRINGIZE(getCardHolderNameTest));
    puts("");

    puts("~~Test Case 1~~");
    if (TestCase_GetCardHolderName_ProperName())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 2~~");
    if (TestCase_GetCardHolderName_NullName())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 3~~");
    if (TestCase_GetCardHolderName_LessThanMin())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 4~~");
    if (TestCase_GetCardHolderName_MoreThanMax())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("");
}

void getCardExpiryDateTest(void)
{

}

void getCardPANTest(void)
{

}

// =============================
// ====== Private Methods ======
// =============================

void PrintCardError(EN_cardError_t cardError)
{
    switch (cardError)
    {
    case CARD_OK:
        puts(STRINGIZE(CARD_OK));
        break;
    case WRONG_NAME:
        puts(STRINGIZE(WRONG_NAME));
        break;
    case WRONG_EXP_DATE:
        puts(STRINGIZE(WRONG_EXP_DATE));
        break;
    case WRONG_PAN:
        puts(STRINGIZE(WRONG_PAN));
        break;
    default:
        break;
    }
}

bool TestCase_GetCardHolderName_ProperName(void)
{
    const uint8_t inputData[] = "Saleh Ahmed Khalid Ali";
    const EN_cardError_t expectedResult = CARD_OK;

    puts(  "Case:            " STRINGIZE(TestCase_GetCardHolderName_ProperName));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(CARD_OK));
    printf("Actual Result:   ");

    // Perform Test
    ST_cardData_t cardData = { 0 };
    EN_cardError_t actualResult = CARD_OK;

    actualResult = CardProcessGetCardHolderName(&cardData, inputData, countof(inputData, uint8_t));

    PrintCardError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetCardHolderName_NullName(void)
{
    const uint8_t *inputData = NULL;
    const EN_cardError_t expectedResult = WRONG_NAME;

    puts("Case:            " STRINGIZE(TestCase_GetCardHolderName_NullName));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_NAME));
    printf("Actual Result:   ");

    // Perform Test
    ST_cardData_t cardData = { 0 };
    EN_cardError_t actualResult = CARD_OK;

    actualResult = CardProcessGetCardHolderName(&cardData, inputData, 0);

    PrintCardError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetCardHolderName_LessThanMin(void)
{
    const uint8_t inputData[] = "Saleh Ahmed";
    const EN_cardError_t expectedResult = WRONG_NAME;

    puts("Case:            " STRINGIZE(TestCase_GetCardHolderName_LessThanMin));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_NAME));
    printf("Actual Result:   ");

    // Perform Test
    ST_cardData_t cardData = { 0 };
    EN_cardError_t actualResult = CARD_OK;

    actualResult = CardProcessGetCardHolderName(&cardData, inputData, countof(inputData, uint8_t));

    PrintCardError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetCardHolderName_MoreThanMax(void)
{
    const uint8_t inputData[] = "Saleh Ahmed Khalid Ali Mahmoud";
    const EN_cardError_t expectedResult = WRONG_NAME;

    puts("Case:            " STRINGIZE(TestCase_GetCardHolderName_MoreThanMax));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_NAME));
    printf("Actual Result:   ");

    // Perform Test
    ST_cardData_t cardData = { 0 };
    EN_cardError_t actualResult = CARD_OK;

    actualResult = CardProcessGetCardHolderName(&cardData, inputData, countof(inputData, uint8_t));

    PrintCardError(actualResult);

    return actualResult == expectedResult;
}
