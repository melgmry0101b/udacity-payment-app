/*-----------------------------------------------------------------*\
 *
 * server.tests.c
 *   UdacityPaymentApp
 *     udacity-payment-app
 *
 * see LICENSE at root directory
 *
 * CREATED: 2022-12-21 11:10 PM
 * AUTHORS: Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 *
\*-----------------------------------------------------------------*/

#include "pch.h"

#include "../Application/app.h"
#include "server.tests.h"

// ==========================
// ====== Declarations ======
// ==========================

bool TestCase_IsValidAccount_ValidAccount(void);
bool TestCase_IsValidAccount_InvalidAccount(void);

bool TestCase_IsBlockedAccount_RunningAccount(void);
bool TestCase_IsBlockedAccount_BlockedAccount(void);

// =====================
// ====== Methods ======
// =====================

void recieveTransactionDataTest(void)
{

}

// ---------------------------------------------
// isValidAccountTest
// 
// Tests isValidAccount.
// ---------------------------------------------
void isValidAccountTest(void)
{
    puts("");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("Tester Name: " _APP_VER_COMPANY);
    puts("Function Name: " STRINGIZE(isValidAccountTest));
    puts("");

    puts("~~Test Case 1~~");
    if (TestCase_IsValidAccount_ValidAccount())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 2~~");
    if (TestCase_IsValidAccount_InvalidAccount())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("");
}

// ---------------------------------------------
// isBlockedAccountTest
// 
// Tests isBlockedAccount.
// ---------------------------------------------
void isBlockedAccountTest(void)
{
    puts("");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("Tester Name: " _APP_VER_COMPANY);
    puts("Function Name: " STRINGIZE(isBlockedAccountTest));
    puts("");

    puts("~~Test Case 1~~");
    if (TestCase_IsBlockedAccount_RunningAccount())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 2~~");
    if (TestCase_IsBlockedAccount_BlockedAccount())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("");
}

void isAmountAvailableTest(void)
{

}

void saveTransactionTest(void)
{

}

void listSavedTransactionsTest(void)
{

}

// =============================
// ====== Private Methods ======
// =============================

void PrintServerError(EN_serverError_t serverError)
{
    switch (serverError)
    {
    case SERVER_OK:
        puts(STRINGIZE(SERVER_OK));
        break;
    case SAVING_FAILED:
        puts(STRINGIZE(SAVING_FAILED));
        break;
    case TRANSACTION_NOT_FOUND:
        puts(STRINGIZE(TRANSACTION_NOT_FOUND));
        break;
    case ACCOUNT_NOT_FOUND:
        puts(STRINGIZE(ACCOUNT_NOT_FOUND));
        break;
    case LOW_BALANCE:
        puts(STRINGIZE(LOW_BALANCE));
        break;
    case BLOCKED_ACCOUNT:
        puts(STRINGIZE(BLOCKED_ACCOUNT));
        break;
    default:
        puts("(unknown)");
        break;
    }
}

void PrintTransactionState(EN_transState_t transState)
{
    switch (transState)
    {
    case APPROVED:
        puts(STRINGIZE(APPROVED));
        break;
    case DECLINED_INSUFFECIENT_FUND:
        puts(STRINGIZE(DECLINED_INSUFFECIENT_FUND));
        break;
    case DECLINED_STOLEN_CARD:
        puts(STRINGIZE(DECLINED_STOLEN_CARD));
        break;
    case FRAUD_CARD:
        puts(STRINGIZE(FRAUD_CARD));
        break;
    case INTERNAL_SERVER_ERROR:
        puts(STRINGIZE(INTERNAL_SERVER_ERROR));
        break;
    default:
        puts("(unknown)");
        break;
    }
}

bool TestCase_IsValidAccount_ValidAccount(void)
{
    ST_cardData_t inputData = { .primaryAccountNumber = "8989374615436851" };
    const EN_serverError_t expectedResult = SERVER_OK;

    puts("Case:            " STRINGIZE(TestCase_IsValidAccount_ValidAccount));
    printf("Input Data:      %s\n", inputData.primaryAccountNumber);
    printf("Expected Result: %s\n", STRINGIZE(SERVER_OK));
    printf("Actual Result:   ");

    // Perform Test
    ST_accountsDB_t account = { 0 };
    EN_serverError_t actualResult = SERVER_OK;

    actualResult = isValidAccount(&inputData, &account);

    PrintServerError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_IsValidAccount_InvalidAccount(void)
{
    ST_cardData_t inputData = { .primaryAccountNumber = "0000000000000000" };
    const EN_serverError_t expectedResult = ACCOUNT_NOT_FOUND;

    puts("Case:            " STRINGIZE(TestCase_IsValidAccount_InvalidAccount));
    printf("Input Data:      %s\n", inputData.primaryAccountNumber);
    printf("Expected Result: %s\n", STRINGIZE(ACCOUNT_NOT_FOUND));
    printf("Actual Result:   ");

    // Perform Test
    ST_accountsDB_t account = { 0 };
    EN_serverError_t actualResult = SERVER_OK;

    actualResult = isValidAccount(&inputData, &account);

    PrintServerError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_IsBlockedAccount_RunningAccount(void)
{
    ST_accountsDB_t inputData = { .state = RUNNING };
    const EN_serverError_t expectedResult = SERVER_OK;

    puts("Case:            " STRINGIZE(TestCase_IsBlockedAccount_RunningAccount));
    printf("Input Data:      %s\n", "RUNNING");
    printf("Expected Result: %s\n", STRINGIZE(SERVER_OK));
    printf("Actual Result:   ");

    // Perform Test
    EN_serverError_t actualResult = SERVER_OK;

    actualResult = isBlockedAccount(&inputData);

    PrintServerError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_IsBlockedAccount_BlockedAccount(void)
{
    ST_accountsDB_t inputData = { .state = BLOCKED };
    const EN_serverError_t expectedResult = BLOCKED_ACCOUNT;

    puts("Case:            " STRINGIZE(TestCase_IsBlockedAccount_BlockedAccount));
    printf("Input Data:      %s\n", "RUNNING");
    printf("Expected Result: %s\n", STRINGIZE(BLOCKED_ACCOUNT));
    printf("Actual Result:   ");

    // Perform Test
    EN_serverError_t actualResult = SERVER_OK;

    actualResult = isBlockedAccount(&inputData);

    PrintServerError(actualResult);

    return actualResult == expectedResult;
}
