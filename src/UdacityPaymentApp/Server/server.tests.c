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

bool TestCase_IsAmountAvailable_ProperAmount(void);
bool TestCase_IsAmountAvailable_SameAsBalance(void);
bool TestCase_IsAmountAvailable_MoreThanBalance(void);

// =====================
// ====== Methods ======
// =====================

void recieveTransactionDataTest(void)
{
    puts("");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("Tester Name: " _APP_VER_COMPANY);
    puts("Function Name: " STRINGIZE(recieveTransactionDataTest));
    puts("");

    puts("~~No test cases available~~");

    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("");
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

// ---------------------------------------------
// isAmountAvailableTest
// 
// Tests isAmountAvailable.
// ---------------------------------------------
void isAmountAvailableTest(void)
{
    puts("");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("Tester Name: " _APP_VER_COMPANY);
    puts("Function Name: " STRINGIZE(isAmountAvailableTest));
    puts("");

    puts("~~Test Case 1~~");
    if (TestCase_IsAmountAvailable_ProperAmount())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 2~~");
    if (TestCase_IsAmountAvailable_SameAsBalance())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("");

    puts("~~Test Case 3~~");
    if (TestCase_IsAmountAvailable_MoreThanBalance())
        puts("++++SUCCEEDED++++");
    else
        puts("----FAILED----");

    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("");
}

// ---------------------------------------------
// saveTransactionTest
// 
// Tests saveTransaction.
// ---------------------------------------------
void saveTransactionTest(void)
{
    puts("");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("Tester Name: " _APP_VER_COMPANY);
    puts("Function Name: " STRINGIZE(saveTransactionTest));
    puts("");

    puts("~~No test cases available~~");

    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("");
}

// ---------------------------------------------
// listSavedTransactionsTest
// 
// Tests listSavedTransactions.
// ---------------------------------------------
void listSavedTransactionsTest(void)
{
    puts("");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("Tester Name: " _APP_VER_COMPANY);
    puts("Function Name: " STRINGIZE(listSavedTransactionsTest));
    puts("");

    puts("~~No test cases available~~");

    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("");
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

bool TestCase_IsAmountAvailable_ProperAmount(void)
{
    ST_terminalData_t inputTermData = { .transAmount = 200.0 };
    ST_accountsDB_t inputAccountData = { .balance = 3000.0 };
    const EN_serverError_t expectedResult = SERVER_OK;

    puts("Case:            " STRINGIZE(TestCase_IsAmountAvailable_ProperAmount));
    printf("Input Data:      Transaction %f, Account %f\n", inputTermData.transAmount, inputAccountData.balance);
    printf("Expected Result: %s\n", STRINGIZE(SERVER_OK));
    printf("Actual Result:   ");

    // Perform Test
    EN_serverError_t actualResult = SERVER_OK;

    actualResult = isAmountAvailable(&inputTermData, &inputAccountData);

    PrintServerError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_IsAmountAvailable_SameAsBalance(void)
{
    ST_terminalData_t inputTermData = { .transAmount = 3000.0 };
    ST_accountsDB_t inputAccountData = { .balance = 3000.0 };
    const EN_serverError_t expectedResult = SERVER_OK;

    puts("Case:            " STRINGIZE(TestCase_IsAmountAvailable_SameAsBalance));
    printf("Input Data:      Transaction %f, Account %f\n", inputTermData.transAmount, inputAccountData.balance);
    printf("Expected Result: %s\n", STRINGIZE(SERVER_OK));
    printf("Actual Result:   ");

    // Perform Test
    EN_serverError_t actualResult = SERVER_OK;

    actualResult = isAmountAvailable(&inputTermData, &inputAccountData);

    PrintServerError(actualResult);

    return actualResult == expectedResult;
}

bool TestCase_IsAmountAvailable_MoreThanBalance(void)
{
    ST_terminalData_t inputTermData = { .transAmount = 5000.0 };
    ST_accountsDB_t inputAccountData = { .balance = 3000.0 };
    const EN_serverError_t expectedResult = LOW_BALANCE;

    puts("Case:            " STRINGIZE(TestCase_IsAmountAvailable_MoreThanBalance));
    printf("Input Data:      Transaction %f, Account %f\n", inputTermData.transAmount, inputAccountData.balance);
    printf("Expected Result: %s\n", STRINGIZE(LOW_BALANCE));
    printf("Actual Result:   ");

    // Perform Test
    EN_serverError_t actualResult = SERVER_OK;

    actualResult = isAmountAvailable(&inputTermData, &inputAccountData);

    PrintServerError(actualResult);

    return actualResult == expectedResult;
}
