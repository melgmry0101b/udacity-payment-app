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

void isCardExpriedTest(void)
{

}

void getTransactionAmountTest(void)
{

}

void isBelowMaxAmountTest(void)
{

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
