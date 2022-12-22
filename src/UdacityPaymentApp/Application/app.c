/*-----------------------------------------------------------------*\
 *
 * app.c
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

#include "app.h"

// ===================
// ====== Types ======
// ===================

enum _COMMAND_CHOICE {
    COMMAND_PERFORM_TESTS = 1
};

enum _TESTS_CHOICE {
    TEST_CARD_HOLDER_NAME = 1,
    TEST_CARD_EXPIRY_DATE,
    TEST_CARD_PAN,
    TEST_TRANSACTION_DATE,
    TEST_CARD_EXPIRED,
    TEST_TRANSACTION_AMOUNT,
    TEST_BELOW_MAX_AMOUNT,
    TEST_MAX_AMOUNT,
    TEST_VALID_CARD_PAN,
    TEST_RECEIVE_TRANSACTION_DATA,
    TEST_VALID_ACCOUNT,
    TEST_BLOCKED_ACCOUNT,
    TEST_AMOUNT_AVAILABLE,
    TEST_SAVE_TRANSACTION,
    TEST_LIST_SAVED_TRANSACTIONS
};

// ==========================
// ====== Declarations ======
// ==========================

static void PrintHeader(void);
static void PrintChoices(void);
static void CommandPerformTests(void);
static void PrintTestChoices(void);

// =====================
// ====== Methods ======
// =====================

// ---------------------------------------------
// appStart
// 
// Application's Main Procedure
// ---------------------------------------------
void appStart(void)
{
    CONSOLE_RESULT consoleResult = CONSOLE_OK;
    int choice = 0;

    PrintHeader();

    // Loop our application till we receive an exit from the user
    while (1)
    {
        // Print choices header.
        PrintChoices();

        consoleResult = ReadConsolePrompt("Enter your choice: ", "%d ", 1, 2, &choice);
        switch (consoleResult)
        {
        case CONSOLE_OK:
            break;
        case CONSOLE_UNKNOWN_ERROR:
            puts("## Unknown Error Encountered ##");
            exit(EXIT_FAILURE);
            break;
        case CONSOLE_OUT_OF_MEMORY:
            puts("## Out of Memory Error Encountered ##");
            exit(EXIT_FAILURE);
            break;
        case CONSOLE_CANCELED:
            puts("\n~~~Good Bye!~~~\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            continue;
        }

        switch (choice)
        {
        case COMMAND_PERFORM_TESTS:
            CommandPerformTests();
            break;
        default:
            continue;
        }
    }
}

// =============================
// ====== Private Methods ======
// =============================

// ---------------------------------------------
// PrintHeader
// 
// Print application's header.
// ---------------------------------------------
static void PrintHeader(void)
{
    puts("******************************************************************************************");
    puts("\t" _APP_ROOT_NAME);
    puts("\t\t" _APP_VER_PRODUCT);
    puts("");
    puts("\t" _APP_VER_COPYRIGHT);
    puts("\t" _APP_VER_VERSION);
    puts("******************************************************************************************");
    puts("");
}

// ---------------------------------------------
// PrintChoices
// 
// Print command choices.
// ---------------------------------------------
static void PrintChoices(void)
{
    puts("");
    puts("Select your command:");
    puts("");

    puts("\t[1] Perform Tests");

    puts("");
}

// ---------------------------------------------
// CommandPerformTests
// 
// Handler for performing tests command.
// ---------------------------------------------
static void CommandPerformTests(void)
{
    CONSOLE_RESULT consoleResult = CONSOLE_OK;
    int choice = 0;

    while (1)
    {
        // Print choices header.
        PrintTestChoices();

        consoleResult = ReadConsolePrompt("Enter your choice: ", "%d ", 1, 2, &choice);
        switch (consoleResult)
        {
        case CONSOLE_OK:
            break;
        case CONSOLE_UNKNOWN_ERROR:
            puts("## Unknown Error Encountered ##");
            return;
        case CONSOLE_OUT_OF_MEMORY:
            puts("## Out of Memory Error Encountered ##");
            return;
        case CONSOLE_CANCELED:
            return;
        default:
            continue;
        }

        switch (choice)
        {
        case TEST_CARD_HOLDER_NAME:
            getCardHolderNameTest();
            break;
        case TEST_CARD_EXPIRY_DATE:
            getCardExpiryDateTest();
            break;
        case TEST_CARD_PAN:
            getCardPANTest();
            break;
        case TEST_TRANSACTION_DATE:
            getTransactionDateTest();
            break;
        case TEST_CARD_EXPIRED:
            isCardExpriedTest();
            break;
        case TEST_TRANSACTION_AMOUNT:
            getTransactionAmountTest();
            break;
        case TEST_BELOW_MAX_AMOUNT:
            isBelowMaxAmountTest();
            break;
        case TEST_MAX_AMOUNT:
            setMaxAmountTest();
            break;
        case TEST_VALID_CARD_PAN:
            isValidCardPANTest();
            break;
        case TEST_RECEIVE_TRANSACTION_DATA:
            recieveTransactionDataTest();
            break;
        case TEST_VALID_ACCOUNT:
            isValidAccountTest();
            break;
        case TEST_BLOCKED_ACCOUNT:
            isBlockedAccountTest();
            break;
        case TEST_AMOUNT_AVAILABLE:
            isAmountAvailableTest();
            break;
        case TEST_SAVE_TRANSACTION:
            saveTransactionTest();
            break;
        case TEST_LIST_SAVED_TRANSACTIONS:
            listSavedTransactionsTest();
            break;
        default:
            continue;
        }
    }
}

// ---------------------------------------------
// PrintTestChoices
// 
// Print test choices.
// ---------------------------------------------
static void PrintTestChoices(void)
{
    puts("");
    puts("Select your test:");
    puts("");

    puts("\t[ 1] getCardHolderNameTest");
    puts("\t[ 2] getCardExpiryDateTest");
    puts("\t[ 3] getCardPANTest");
    puts("\t[ 4] getTransactionDateTest");
    puts("\t[ 5] isCardExpriedTest");
    puts("\t[ 6] getTransactionAmountTest");
    puts("\t[ 7] isBelowMaxAmountTest");
    puts("\t[ 8] setMaxAmountTest");
    puts("\t[ 9] isValidCardPANTest");
    puts("\t[10] recieveTransactionDataTest");
    puts("\t[11] isValidAccountTest");
    puts("\t[12] isBlockedAccountTest");
    puts("\t[13] isAmountAvailableTest");
    puts("\t[14] saveTransactionTest");
    puts("\t[15] listSavedTransactionsTest");

    puts("");
}
