/*-----------------------------------------------------------------*\
 *
 * terminal.tests.c
 *   UdacityPaymentApp
 *     udacity-payment-app
 *
 * see LICENSE at root directory
 *
 * CREATED: 2022-12-21 11:04 PM
 * AUTHORS: Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 *
\*-----------------------------------------------------------------*/

#include "pch.h"

#include "../Application/app.h"
#include "terminal.tests.h"

// ==========================
// ====== Declarations ======
// ==========================

bool TestCase_GetTransactionDate_ProperDate(void);
bool TestCase_GetTransactionDate_NullDate(void);
bool TestCase_GetTransactionDate_LessThanLength(void);
bool TestCase_GetTransactionDate_MoreThanLength(void);
bool TestCase_GetTransactionDate_InvalidDay(void);
bool TestCase_GetTransactionDate_InvalidMonth(void);
bool TestCase_GetTransactionDate_InvalidYear(void);
bool TestCase_GetTransactionDate_InvalidSeparator(void);

bool TestCase_IsCardExpried_ValidNotSameYear(void);
bool TestCase_IsCardExpried_ValidSameYear(void);
bool TestCase_IsCardExpried_InvalidSameMonthYear(void);
bool TestCase_IsCardExpried_InvalidFutureMonth(void);
bool TestCase_IsCardExpried_InvalidFutureMonthYear(void);

bool TestCase_GetTransactionAmount_ProperAmount(void);
bool TestCase_GetTransactionAmount_ZeroAmount(void);
bool TestCase_GetTransactionAmount_NegativeAmount(void);

bool TestCase_IsBelowMaxAmount_ProperAmount(void);
bool TestCase_IsBelowMaxAmount_SameAsMaxAmount(void);
bool TestCase_IsBelowMaxAmount_LargeAmount(void);

// =====================
// ====== Methods ======
// =====================

// ---------------------------------------------
// getTransactionDateTest
// 
// Tests getTransactionDate
//  through TerminalProcessTransactionDate
// ---------------------------------------------
void getTransactionDateTest(void)
{
    puts("");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("Tester Name: " _APP_VER_COMPANY);
    puts("Function Name: " STRINGIZE(getTransactionDateTest));
    puts("");

    puts("~~Test Case 1~~");
    if (TestCase_GetTransactionDate_ProperDate())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 2~~");
    if (TestCase_GetTransactionDate_NullDate())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 3~~");
    if (TestCase_GetTransactionDate_LessThanLength())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 4~~");
    if (TestCase_GetTransactionDate_MoreThanLength())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 5~~");
    if (TestCase_GetTransactionDate_InvalidDay())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 6~~");
    if (TestCase_GetTransactionDate_InvalidMonth())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 7~~");
    if (TestCase_GetTransactionDate_InvalidYear())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 8~~");
    if (TestCase_GetTransactionDate_InvalidSeparator())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("");
}

// ---------------------------------------------
// isCardExpriedTest
// 
// Tests isCardExpriedTest
// ---------------------------------------------
void isCardExpriedTest(void)
{
    puts("");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("Tester Name: " _APP_VER_COMPANY);
    puts("Function Name: " STRINGIZE(isCardExpriedTest));
    puts("");

    puts("~~Test Case 1~~");
    if (TestCase_IsCardExpried_ValidNotSameYear())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 2~~");
    if (TestCase_IsCardExpried_ValidSameYear())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 3~~");
    if (TestCase_IsCardExpried_InvalidSameMonthYear())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 4~~");
    if (TestCase_IsCardExpried_InvalidFutureMonth())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 5~~");
    if (TestCase_IsCardExpried_InvalidFutureMonthYear())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("");
}

// ---------------------------------------------
// getTransactionAmountTest
// 
// Tests getTransactionAmountTest
//  through TerminalProcessTransactionAmount
// ---------------------------------------------
void getTransactionAmountTest(void)
{
    puts("");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("Tester Name: " _APP_VER_COMPANY);
    puts("Function Name: " STRINGIZE(getTransactionAmountTest));
    puts("");

    puts("~~Test Case 1~~");
    if (TestCase_GetTransactionAmount_ProperAmount())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 2~~");
    if (TestCase_GetTransactionAmount_ZeroAmount())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 3~~");
    if (TestCase_GetTransactionAmount_NegativeAmount())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("");
}

// ---------------------------------------------
// isBelowMaxAmountTest
// 
// Tests isBelowMaxAmountTest
// ---------------------------------------------
void isBelowMaxAmountTest(void)
{
    puts("");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("Tester Name: " _APP_VER_COMPANY);
    puts("Function Name: " STRINGIZE(isBelowMaxAmountTest));
    puts("");

    puts("~~Test Case 1~~");
    if (TestCase_IsBelowMaxAmount_ProperAmount())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 2~~");
    if (TestCase_IsBelowMaxAmount_SameAsMaxAmount())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 3~~");
    if (TestCase_IsBelowMaxAmount_LargeAmount())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("");
}

void setMaxAmountTest(void)
{

}

void isValidCardPANTest(void)
{

}

// =============================
// ====== Private Methods ======
// =============================

void PrintTerminalError(EN_terminalError_t termError)
{
    switch (termError)
    {
    case TERMINAL_OK:
        puts(STRINGIZE(TERMINAL_OK));
        break;
    case WRONG_DATE:
        puts(STRINGIZE(WRONG_DATE));
        break;
    case EXPIRED_CARD:
        puts(STRINGIZE(EXPIRED_CARD));
        break;
    case INVALID_CARD:
        puts(STRINGIZE(INVALID_CARD));
        break;
    case INVALID_AMOUNT:
        puts(STRINGIZE(INVALID_AMOUNT));
        break;
    case EXCEED_MAX_AMOUNT:
        puts(STRINGIZE(EXCEED_MAX_AMOUNT));
        break;
    case INVALID_MAX_AMOUNT:
        puts(STRINGIZE(INVALID_MAX_AMOUNT));
        break;
    default:
        puts("(unknown)");
        break;
    }
}

bool TestCase_GetTransactionDate_ProperDate(void)
{
    const uint8_t inputData[] = "22/12/2022";
    const EN_terminalError_t expectedResult = TERMINAL_OK;

    puts("Case:            " STRINGIZE(TestCase_GetTransactionDate_ProperDate));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(TERMINAL_OK));
    printf("Actual Result:   ");

    // Perform Test
    ST_terminalData_t termData = { 0 };
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = TerminalProcessTransactionDate(&termData, inputData, countof(inputData, uint8_t));

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetTransactionDate_NullDate(void)
{
    const uint8_t *inputData = NULL;
    const EN_terminalError_t expectedResult = WRONG_DATE;

    puts("Case:            " STRINGIZE(TestCase_GetTransactionDate_NullDate));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_DATE));
    printf("Actual Result:   ");

    // Perform Test
    ST_terminalData_t termData = { 0 };
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = TerminalProcessTransactionDate(&termData, inputData, 0);

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetTransactionDate_LessThanLength(void)
{
    const uint8_t inputData[] = "22/12/22";
    const EN_terminalError_t expectedResult = WRONG_DATE;

    puts("Case:            " STRINGIZE(TestCase_GetTransactionDate_LessThanLength));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_DATE));
    printf("Actual Result:   ");

    // Perform Test
    ST_terminalData_t termData = { 0 };
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = TerminalProcessTransactionDate(&termData, inputData, countof(inputData, uint8_t));

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetTransactionDate_MoreThanLength(void)
{
    const uint8_t inputData[] = "22/12/20222";
    const EN_terminalError_t expectedResult = WRONG_DATE;

    puts("Case:            " STRINGIZE(TestCase_GetTransactionDate_MoreThanLength));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_DATE));
    printf("Actual Result:   ");

    // Perform Test
    ST_terminalData_t termData = { 0 };
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = TerminalProcessTransactionDate(&termData, inputData, countof(inputData, uint8_t));

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetTransactionDate_InvalidDay(void)
{
    const uint8_t inputData[] = "50/12/2022";
    const EN_terminalError_t expectedResult = WRONG_DATE;

    puts("Case:            " STRINGIZE(TestCase_GetTransactionDate_InvalidDay));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_DATE));
    printf("Actual Result:   ");

    // Perform Test
    ST_terminalData_t termData = { 0 };
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = TerminalProcessTransactionDate(&termData, inputData, countof(inputData, uint8_t));

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetTransactionDate_InvalidMonth(void)
{
    const uint8_t inputData[] = "22/20/2022";
    const EN_terminalError_t expectedResult = WRONG_DATE;

    puts("Case:            " STRINGIZE(TestCase_GetTransactionDate_InvalidMonth));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_DATE));
    printf("Actual Result:   ");

    // Perform Test
    ST_terminalData_t termData = { 0 };
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = TerminalProcessTransactionDate(&termData, inputData, countof(inputData, uint8_t));

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetTransactionDate_InvalidYear(void)
{
    const uint8_t inputData[] = "22/12/9999";
    const EN_terminalError_t expectedResult = WRONG_DATE;

    puts("Case:            " STRINGIZE(TestCase_GetTransactionDate_InvalidYear));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_DATE));
    printf("Actual Result:   ");

    // Perform Test
    ST_terminalData_t termData = { 0 };
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = TerminalProcessTransactionDate(&termData, inputData, countof(inputData, uint8_t));

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetTransactionDate_InvalidSeparator(void)
{
    const uint8_t inputData[] = "22-12-2022";
    const EN_terminalError_t expectedResult = WRONG_DATE;

    puts("Case:            " STRINGIZE(TestCase_GetTransactionDate_InvalidSeparator));
    printf("Input Data:      %s\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(WRONG_DATE));
    printf("Actual Result:   ");

    // Perform Test
    ST_terminalData_t termData = { 0 };
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = TerminalProcessTransactionDate(&termData, inputData, countof(inputData, uint8_t));

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_IsCardExpried_ValidNotSameYear(void)
{
    ST_cardData_t       cardData = { .cardExpirationDate    = "12/25" };
    ST_terminalData_t   termData = { .transactionDate       = "22/12/2022" };
    const EN_terminalError_t expectedResult = TERMINAL_OK;

    puts("Case:            " STRINGIZE(TestCase_IsCardExpried_ValidNotSameYear));
    printf("Input Data:      Card %s, Transaction %s\n", cardData.cardExpirationDate, termData.transactionDate);
    printf("Expected Result: %s\n", STRINGIZE(TERMINAL_OK));
    printf("Actual Result:   ");

    // Perform Test
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = isCardExpired(&cardData, &termData);

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_IsCardExpried_ValidSameYear(void)
{
    ST_cardData_t       cardData = { .cardExpirationDate    = "12/22" };
    ST_terminalData_t   termData = { .transactionDate       = "22/11/2022" };
    const EN_terminalError_t expectedResult = TERMINAL_OK;

    puts("Case:            " STRINGIZE(TestCase_IsCardExpried_ValidSameYear));
    printf("Input Data:      Card %s, Transaction %s\n", cardData.cardExpirationDate, termData.transactionDate);
    printf("Expected Result: %s\n", STRINGIZE(TERMINAL_OK));
    printf("Actual Result:   ");

    // Perform Test
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = isCardExpired(&cardData, &termData);

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_IsCardExpried_InvalidSameMonthYear(void)
{
    ST_cardData_t       cardData = { .cardExpirationDate    = "12/22" };
    ST_terminalData_t   termData = { .transactionDate       = "22/12/2022" };
    const EN_terminalError_t expectedResult = EXPIRED_CARD;

    puts("Case:            " STRINGIZE(TestCase_IsCardExpried_InvalidSameMonthYear));
    printf("Input Data:      Card %s, Transaction %s\n", cardData.cardExpirationDate, termData.transactionDate);
    printf("Expected Result: %s\n", STRINGIZE(EXPIRED_CARD));
    printf("Actual Result:   ");

    // Perform Test
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = isCardExpired(&cardData, &termData);

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_IsCardExpried_InvalidFutureMonth(void)
{
    ST_cardData_t       cardData = { .cardExpirationDate    = "01/23" };
    ST_terminalData_t   termData = { .transactionDate       = "22/02/2023" };
    const EN_terminalError_t expectedResult = EXPIRED_CARD;

    puts("Case:            " STRINGIZE(TestCase_IsCardExpried_InvalidFutureMonth));
    printf("Input Data:      Card %s, Transaction %s\n", cardData.cardExpirationDate, termData.transactionDate);
    printf("Expected Result: %s\n", STRINGIZE(EXPIRED_CARD));
    printf("Actual Result:   ");

    // Perform Test
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = isCardExpired(&cardData, &termData);

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_IsCardExpried_InvalidFutureMonthYear(void)
{
    ST_cardData_t       cardData = { .cardExpirationDate    = "12/22" };
    ST_terminalData_t   termData = { .transactionDate       = "22/02/2023" };
    const EN_terminalError_t expectedResult = EXPIRED_CARD;

    puts("Case:            " STRINGIZE(TestCase_IsCardExpried_InvalidFutureMonthYear));
    printf("Input Data:      Card %s, Transaction %s\n", cardData.cardExpirationDate, termData.transactionDate);
    printf("Expected Result: %s\n", STRINGIZE(EXPIRED_CARD));
    printf("Actual Result:   ");

    // Perform Test
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = isCardExpired(&cardData, &termData);

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetTransactionAmount_ProperAmount(void)
{
    const float inputData = 100;
    const EN_terminalError_t expectedResult = TERMINAL_OK;

    puts("Case:            " STRINGIZE(TestCase_GetTransactionAmount_ProperAmount));
    printf("Input Data:      %f\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(TERMINAL_OK));
    printf("Actual Result:   ");

    // Perform Test
    ST_terminalData_t termData = { 0 };
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = TerminalProcessTransactionAmount(&termData, inputData);

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetTransactionAmount_ZeroAmount(void)
{
    const float inputData = 0;
    const EN_terminalError_t expectedResult = INVALID_AMOUNT;

    puts("Case:            " STRINGIZE(TestCase_GetTransactionAmount_ZeroAmount));
    printf("Input Data:      %f\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(INVALID_AMOUNT));
    printf("Actual Result:   ");

    // Perform Test
    ST_terminalData_t termData = { 0 };
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = TerminalProcessTransactionAmount(&termData, inputData);

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_GetTransactionAmount_NegativeAmount(void)
{
    const float inputData = -200;
    const EN_terminalError_t expectedResult = INVALID_AMOUNT;

    puts("Case:            " STRINGIZE(TestCase_GetTransactionAmount_NegativeAmount));
    printf("Input Data:      %f\n", inputData);
    printf("Expected Result: %s\n", STRINGIZE(INVALID_AMOUNT));
    printf("Actual Result:   ");

    // Perform Test
    ST_terminalData_t termData = { 0 };
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = TerminalProcessTransactionAmount(&termData, inputData);

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_IsBelowMaxAmount_ProperAmount(void)
{
    ST_terminalData_t inputData = { .transAmount = 200, .maxTransAmount = 500 };
    const EN_terminalError_t expectedResult = TERMINAL_OK;

    puts("Case:            " STRINGIZE(TestCase_IsBelowMaxAmount_ProperAmount));
    printf("Input Data:      Amount %f, Max %f\n", inputData.transAmount, inputData.maxTransAmount);
    printf("Expected Result: %s\n", STRINGIZE(TERMINAL_OK));
    printf("Actual Result:   ");

    // Perform Test
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = isBelowMaxAmount(&inputData);

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_IsBelowMaxAmount_SameAsMaxAmount(void)
{
    ST_terminalData_t inputData = { .transAmount = 500, .maxTransAmount = 500 };
    const EN_terminalError_t expectedResult = TERMINAL_OK;

    puts("Case:            " STRINGIZE(TestCase_IsBelowMaxAmount_SameAsMaxAmount));
    printf("Input Data:      Amount %f, Max %f\n", inputData.transAmount, inputData.maxTransAmount);
    printf("Expected Result: %s\n", STRINGIZE(TERMINAL_OK));
    printf("Actual Result:   ");

    // Perform Test
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = isBelowMaxAmount(&inputData);

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_IsBelowMaxAmount_LargeAmount(void)
{
    ST_terminalData_t inputData = { .transAmount = 501, .maxTransAmount = 500 };
    const EN_terminalError_t expectedResult = EXCEED_MAX_AMOUNT;

    puts("Case:            " STRINGIZE(TestCase_IsBelowMaxAmount_LargeAmount));
    printf("Input Data:      Amount %f, Max %f\n", inputData.transAmount, inputData.maxTransAmount);
    printf("Expected Result: %s\n", STRINGIZE(EXCEED_MAX_AMOUNT));
    printf("Actual Result:   ");

    // Perform Test
    EN_terminalError_t actualResult = TERMINAL_OK;

    actualResult = isBelowMaxAmount(&inputData);

    PrintTerminalError(actualResult);

    return actualResult == expectedResult;
}
