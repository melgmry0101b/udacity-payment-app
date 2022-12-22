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

bool TestCase_GetCardExpiryDate_ProperDate(void);
bool TestCase_GetCardExpiryDate_NullDate(void);
bool TestCase_GetCardExpiryDate_LessThanLength(void);
bool TestCase_GetCardExpiryDate_MoreThanLength(void);
bool TestCase_GetCardExpiryDate_InvalidMonth(void);
bool TestCase_GetCardExpiryDate_InvalidYear(void);
bool TestCase_GetCardExpiryDate_InvalidSeparator(void);

bool TestCase_GetCardPAN_ProperPAN(void);
bool TestCase_GetCardPAN_NullPAN(void);
bool TestCase_GetCardPAN_LessThanMin(void);
bool TestCase_GetCardPAN_MoreThanMax(void);
bool TestCase_GetCardPAN_NotNumeric(void);

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

// ---------------------------------------------
// getCardExpiryDateTest
// 
// Tests getCardExpiryDate
//  through CardProcessCardExpiryDate
// ---------------------------------------------
void getCardExpiryDateTest(void)
{
    puts("");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("Tester Name: " _APP_VER_COMPANY);
    puts("Function Name: " STRINGIZE(getCardExpiryDateTest));
    puts("");

    puts("~~Test Case 1~~");
    if (TestCase_GetCardExpiryDate_ProperDate())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 2~~");
    if (TestCase_GetCardExpiryDate_NullDate())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 3~~");
    if (TestCase_GetCardExpiryDate_LessThanLength())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 4~~");
    if (TestCase_GetCardExpiryDate_MoreThanLength())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 5~~");
    if (TestCase_GetCardExpiryDate_InvalidMonth())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 6~~");
    if (TestCase_GetCardExpiryDate_InvalidYear())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 7~~");
    if (TestCase_GetCardExpiryDate_InvalidSeparator())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("");
}

// ---------------------------------------------
// getCardPANTest
// 
// Tests getCardPAN
//  through CardProcessCardPAN
// ---------------------------------------------
void getCardPANTest(void)
{
    puts("");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("Tester Name: " _APP_VER_COMPANY);
    puts("Function Name: " STRINGIZE(getCardPANTest));
    puts("");

    puts("~~Test Case 1~~");
    if (TestCase_GetCardPAN_ProperPAN())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 2~~");
    if (TestCase_GetCardPAN_NullPAN())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 3~~");
    if (TestCase_GetCardPAN_LessThanMin())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 4~~");
    if (TestCase_GetCardPAN_MoreThanMax())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 5~~");
    if (TestCase_GetCardPAN_NotNumeric())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("");
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
        puts("(unknown)");
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

bool TestCase_GetCardExpiryDate_ProperDate(void)
{
    const uint8_t inputData[] = "12/22";
    const EN_cardError_t expectedResult = CARD_OK;

    puts("Case:            " STRINGIZE(TestCase_GetCardExpiryDate_ProperDate));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(CARD_OK));
    printf("Actual Result:   ");

    // Perform Test
    ST_cardData_t cardData = { 0 };
    EN_cardError_t actualResult = CARD_OK;

    actualResult = CardProcessCardExpiryDate(&cardData, inputData, countof(inputData, uint8_t));

    PrintCardError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetCardExpiryDate_NullDate(void)
{
    const uint8_t *inputData = NULL;
    const EN_cardError_t expectedResult = WRONG_EXP_DATE;

    puts("Case:            " STRINGIZE(TestCase_GetCardExpiryDate_NullDate));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_EXP_DATE));
    printf("Actual Result:   ");

    // Perform Test
    ST_cardData_t cardData = { 0 };
    EN_cardError_t actualResult = CARD_OK;

    actualResult = CardProcessCardExpiryDate(&cardData, inputData, 0);

    PrintCardError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetCardExpiryDate_LessThanLength(void)
{
    const uint8_t inputData[] = "12/2";
    const EN_cardError_t expectedResult = WRONG_EXP_DATE;

    puts("Case:            " STRINGIZE(TestCase_GetCardExpiryDate_LessThanLength));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_EXP_DATE));
    printf("Actual Result:   ");

    // Perform Test
    ST_cardData_t cardData = { 0 };
    EN_cardError_t actualResult = CARD_OK;

    actualResult = CardProcessCardExpiryDate(&cardData, inputData, countof(inputData, uint8_t));

    PrintCardError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetCardExpiryDate_MoreThanLength(void)
{
    const uint8_t inputData[] = "12/222";
    const EN_cardError_t expectedResult = WRONG_EXP_DATE;

    puts("Case:            " STRINGIZE(TestCase_GetCardExpiryDate_MoreThanLength));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_EXP_DATE));
    printf("Actual Result:   ");

    // Perform Test
    ST_cardData_t cardData = { 0 };
    EN_cardError_t actualResult = CARD_OK;

    actualResult = CardProcessCardExpiryDate(&cardData, inputData, countof(inputData, uint8_t));

    PrintCardError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetCardExpiryDate_InvalidMonth(void)
{
    const uint8_t inputData[] = "99/22";
    const EN_cardError_t expectedResult = WRONG_EXP_DATE;

    puts("Case:            " STRINGIZE(TestCase_GetCardExpiryDate_InvalidMonth));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_EXP_DATE));
    printf("Actual Result:   ");

    // Perform Test
    ST_cardData_t cardData = { 0 };
    EN_cardError_t actualResult = CARD_OK;

    actualResult = CardProcessCardExpiryDate(&cardData, inputData, countof(inputData, uint8_t));

    PrintCardError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetCardExpiryDate_InvalidYear(void)
{
    const uint8_t inputData[] = "12/-2";
    const EN_cardError_t expectedResult = WRONG_EXP_DATE;

    puts("Case:            " STRINGIZE(TestCase_GetCardExpiryDate_InvalidYear));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_EXP_DATE));
    printf("Actual Result:   ");

    // Perform Test
    ST_cardData_t cardData = { 0 };
    EN_cardError_t actualResult = CARD_OK;

    actualResult = CardProcessCardExpiryDate(&cardData, inputData, countof(inputData, uint8_t));

    PrintCardError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetCardExpiryDate_InvalidSeparator(void)
{
    const uint8_t inputData[] = "12-22";
    const EN_cardError_t expectedResult = WRONG_EXP_DATE;

    puts("Case:            " STRINGIZE(TestCase_GetCardExpiryDate_InvalidSeparator));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_EXP_DATE));
    printf("Actual Result:   ");

    // Perform Test
    ST_cardData_t cardData = { 0 };
    EN_cardError_t actualResult = CARD_OK;

    actualResult = CardProcessCardExpiryDate(&cardData, inputData, countof(inputData, uint8_t));

    PrintCardError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetCardPAN_ProperPAN(void)
{
    const uint8_t inputData[] = "5105105105105100";
    const EN_cardError_t expectedResult = CARD_OK;

    puts("Case:            " STRINGIZE(TestCase_GetCardPAN_ProperPAN));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(CARD_OK));
    printf("Actual Result:   ");

    // Perform Test
    ST_cardData_t cardData = { 0 };
    EN_cardError_t actualResult = CARD_OK;

    actualResult = CardProcessCardPAN(&cardData, inputData, countof(inputData, uint8_t));

    PrintCardError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetCardPAN_NullPAN(void)
{
    const uint8_t *inputData = NULL;
    const EN_cardError_t expectedResult = WRONG_PAN;

    puts("Case:            " STRINGIZE(TestCase_GetCardPAN_NullPAN));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_PAN));
    printf("Actual Result:   ");

    // Perform Test
    ST_cardData_t cardData = { 0 };
    EN_cardError_t actualResult = CARD_OK;

    actualResult = CardProcessCardPAN(&cardData, inputData, 0);

    PrintCardError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetCardPAN_LessThanMin(void)
{
    const uint8_t inputData[] = "510510510510";
    const EN_cardError_t expectedResult = WRONG_PAN;

    puts("Case:            " STRINGIZE(TestCase_GetCardPAN_LessThanMin));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_PAN));
    printf("Actual Result:   ");

    // Perform Test
    ST_cardData_t cardData = { 0 };
    EN_cardError_t actualResult = CARD_OK;

    actualResult = CardProcessCardPAN(&cardData, inputData, countof(inputData, uint8_t));

    PrintCardError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetCardPAN_MoreThanMax(void)
{
    const uint8_t inputData[] = "5105105105100000000000000000000";
    const EN_cardError_t expectedResult = WRONG_PAN;

    puts("Case:            " STRINGIZE(TestCase_GetCardPAN_MoreThanMax));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_PAN));
    printf("Actual Result:   ");

    // Perform Test
    ST_cardData_t cardData = { 0 };
    EN_cardError_t actualResult = CARD_OK;

    actualResult = CardProcessCardPAN(&cardData, inputData, countof(inputData, uint8_t));

    PrintCardError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetCardPAN_NotNumeric(void)
{
    const uint8_t inputData[] = "510510510ABC";
    const EN_cardError_t expectedResult = WRONG_PAN;

    puts("Case:            " STRINGIZE(TestCase_GetCardPAN_NotNumeric));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_PAN));
    printf("Actual Result:   ");

    // Perform Test
    ST_cardData_t cardData = { 0 };
    EN_cardError_t actualResult = CARD_OK;

    actualResult = CardProcessCardPAN(&cardData, inputData, countof(inputData, uint8_t));

    PrintCardError(actualResult);

    return actualResult == expectedResult;
}
