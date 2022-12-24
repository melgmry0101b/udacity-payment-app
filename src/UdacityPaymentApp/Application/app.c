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
    COMMAND_PERFORM_TESTS = 1,
    COMMAND_MAKE_TRANSACTION,
    COMMAND_LIST_TRANSACTIONS
};

enum _TESTS_CHOICE {
    TEST_RUN_ALL,
    TEST_CARD_HOLDER_NAME,
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
static void PrintTestChoices(void);
static void CommandPerformTests(void);
static void CommandMakeTransaction(void);

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

        consoleResult = ReadConsolePrompt("Enter your choice: ", " %d ", 1, 2, &choice);
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
        case COMMAND_MAKE_TRANSACTION:
            CommandMakeTransaction();
            break;
        case COMMAND_LIST_TRANSACTIONS:
            listSavedTransactions();
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
    puts("\t[2] Make a Transaction");
    puts("\t[3] List All Transactions");

    puts("");
}

// ---------------------------------------------
// PrintUserReadableCardError
// 
// Print card error as user readable string.
// ---------------------------------------------
static void PrintUserReadableCardError(EN_cardError_t cardError)
{
    switch (cardError)
    {
    case CARD_OK:
        puts("Data has been accepted.");
        break;
    case WRONG_NAME:
        puts("You entered a wrong name.");
        break;
    case WRONG_EXP_DATE:
        puts("Wrong date format.");
        break;
    case WRONG_PAN:
        puts("Wrong PAN.");
        break;
    default:
        puts("##Unknown Error##");
        break;
    }
}

// ---------------------------------------------
// PrintUserReadableTerminalError
// 
// Print terminal error as user readable string.
// ---------------------------------------------
static void PrintUserReadableTerminalError(EN_terminalError_t termError)
{
    switch (termError)
    {
    case TERMINAL_OK:
        puts("Data has been accepted.");
        break;
    case WRONG_DATE:
        puts("Wrong date format.");
        break;
    case EXPIRED_CARD:
        puts("Card is expired.");
        break;
    case INVALID_CARD:
        puts("Invalid card.");
        break;
    case INVALID_AMOUNT:
        puts("Invalid amount provided.");
        break;
    case EXCEED_MAX_AMOUNT:
        puts("Amount exceeds max terminal amount.");
        break;
    case INVALID_MAX_AMOUNT:
        puts("Invalid max amount provided.");
        break;
    default:
        puts("##Unknown Error##");
        break;
    }
}

// ---------------------------------------------
// PrintUserReadableTransactionState
// 
// Print terminal error as user readable string.
// ---------------------------------------------
static void PrintUserReadableTransactionState(EN_transState_t transState)
{
    switch (transState)
    {
    case APPROVED:
        puts("Transaction has been approved.");
        break;
    case DECLINED_INSUFFECIENT_FUND:
        puts("Transaction has been declined because of insufficient funds.");
        break;
    case DECLINED_STOLEN_CARD:
        puts("Transaction has been declined because the card has been reported stolen.");
        break;
    case FRAUD_CARD:
        puts("Transaction has been declined because the data entered is fraudulent.");
        break;
    case INTERNAL_SERVER_ERROR:
        puts("##INTERNAL SERVER ERROR##");
        break;
    default:
        puts("##Unknown Error##");
        break;
    }
}


// ---------------------------------------------
// CommandMakeTransaction
// 
// Handler for performing tests command.
// ---------------------------------------------
static void CommandMakeTransaction(void)
{
    EN_cardError_t cardError = CARD_OK;
    ST_cardData_t cardData = { 0 };

    EN_terminalError_t termError = TERMINAL_OK;
    ST_terminalData_t termData = { 0 };

    EN_transState_t transState = APPROVED;
    ST_transaction_t transData = { 0 };

    puts("");
    puts("~~~Creating a new transaction~~~");
    puts("Max transaction amount is: 5000");
    puts("");

    setMaxAmount(&termData, 5000.0);

    // =-=-=-=-=
    // Get card details.
    // =-=-=-=-=

    cardError = getCardHolderName(&cardData);
    if (cardError != CARD_OK)
    {
        PrintUserReadableCardError(cardError);
        return;
    }

    cardError = getCardExpiryDate(&cardData);
    if (cardError != CARD_OK)
    {
        PrintUserReadableCardError(cardError);
        return;
    }

    cardError = getCardPAN(&cardData);
    if (cardError != CARD_OK)
    {
        PrintUserReadableCardError(cardError);
        return;
    }

    // =-=-=-=-=
    // Get terminal details.
    // =-=-=-=-=

    termError = getTransactionDate(&termData);
    if (termError != TERMINAL_OK)
    {
        PrintUserReadableTerminalError(termError);
        return;
    }

    termError = isCardExpired(&cardData, &termData);
    if (termError != TERMINAL_OK)
    {
        PrintUserReadableTerminalError(termError);
        return;
    }

    termError = getTransactionAmount(&termData);
    if (termError != TERMINAL_OK)
    {
        PrintUserReadableTerminalError(termError);
        return;
    }

    termError = isBelowMaxAmount(&termData);
    if (termError != TERMINAL_OK)
    {
        PrintUserReadableTerminalError(termError);
        return;
    }

    termError = isValidCardPAN(&cardData);
    if (termError != TERMINAL_OK)
    {
        PrintUserReadableTerminalError(termError);
        return;
    }

    // =-=-=-=-=
    // Call the server.
    // =-=-=-=-=

    puts("");
    transData.cardHolderData = cardData;
    transData.terminalData = termData;
    transState = recieveTransactionData(&transData);
    PrintUserReadableTransactionState(transState);
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

        consoleResult = ReadConsolePrompt("Enter your choice: ", " %d ", 1, 2, &choice);
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
        case TEST_RUN_ALL:
            getCardHolderNameTest();
            getCardExpiryDateTest();
            getCardPANTest();
            getTransactionDateTest();
            isCardExpriedTest();
            getTransactionAmountTest();
            isBelowMaxAmountTest();
            setMaxAmountTest();
            isValidCardPANTest();
            recieveTransactionDataTest();
            isValidAccountTest();
            isBlockedAccountTest();
            isAmountAvailableTest();
            saveTransactionTest();
            listSavedTransactionsTest();
            break;
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

    puts("\t[ 0] Run All Tests");
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
