/*-----------------------------------------------------------------*\
 *
 * server.c
 *   UdacityPaymentApp
 *     udacity-payment-app
 *
 * see LICENSE at root directory
 *
 * CREATED: 2022-12-21 06:20 PM
 * AUTHORS: Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 *
\*-----------------------------------------------------------------*/

#include "pch.h"

#include "../Application/app.h"
#include "server.h"

// ==================
// ====== Defs ======
// ==================

#define MAX_ENTRIES 255

// ==========================
// ====== Declarations ======
// ==========================

const char *TransactionStateToStr(EN_transState_t transState);

// =====================
// ====== Globals ======
// =====================

// NOTE: I would've implemented theses globals into an `sqlite` database,
//  but as I am running tight on time, I would stick with the required
//  parameters for now.

// ---------------------------------------------
// Global variable holding accounts.
// ---------------------------------------------
static ST_accountsDB_t accountsDB[MAX_ENTRIES] = {
    { 2000.0, RUNNING, "8989374615436851" },
    { 100000.0, BLOCKED, "5807007076043875" },
    { 198000.0, BLOCKED, "5610591081018250" },
    { 0.0, RUNNING, "378282246310005" },
    { 500.0, RUNNING, "371449635398431" },
    { 5200.0, RUNNING, "378734493671000" },
    { 300.0, RUNNING, "30569309025904" },
    { 15900.0, BLOCKED, "38520000023237" },
    { 4000.0, BLOCKED, "6011111111111117" },
    { 0.0, RUNNING, "6011000990139424" }
};

// ---------------------------------------------
// Global variable holding transactions.
// ---------------------------------------------
static ST_transaction_t transactionsDB[MAX_ENTRIES] = { 0 };

// ---------------------------------------------
// Global variable telling how many transactions
//  we have saved.
// ---------------------------------------------
static uint16_t transactionsCount = 0;

// =====================
// ====== Methods ======
// =====================

// ---------------------------------------------
// recieveTransactionData
//
// Makes a transactions on an account.
// ---------------------------------------------
EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{
    assert(transData != NULL);

    EN_transState_t transState = APPROVED;
    EN_serverError_t serverError = SERVER_OK;
    ST_accountsDB_t account = { 0 };

    // Check if the account is valid.
    serverError = isValidAccount(&transData->cardHolderData, &account);
    if (serverError != SERVER_OK) { goto done; }

    // check if the account is blocked
    serverError = isBlockedAccount(&account);
    if (serverError != SERVER_OK) { goto done; }

    // Check if enough balance is available
    serverError = isAmountAvailable(&transData->terminalData, &account);
    if (serverError != SERVER_OK) { goto done; }
done:
    switch (serverError)
    {
    case SERVER_OK:
        transState = APPROVED;
        break;
    case ACCOUNT_NOT_FOUND:
        transState = FRAUD_CARD;
        break;
    case LOW_BALANCE:
        transState = DECLINED_INSUFFECIENT_FUND;
        break;
    case BLOCKED_ACCOUNT:
        transState = DECLINED_STOLEN_CARD;
        break;
    default:
        transState = INTERNAL_SERVER_ERROR;
        break;
    }

    transData->transState = transState;

    if (saveTransaction(transData) != SERVER_OK)
    {
        transData->transState = INTERNAL_SERVER_ERROR;
        return INTERNAL_SERVER_ERROR;
    }

    // Update balance if the transaction has been approved and saved.
    if (transState == APPROVED)
    {
        account.balance -= transData->terminalData.transAmount;
    }

    return transState;
}

// ---------------------------------------------
// isValidAccount
//
// Checks if an account is valid.
// ---------------------------------------------
EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountRefrence)
{
    assert(cardData != NULL);
    assert(accountRefrence != NULL);

    // Check if the account exists using PAN
    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        if (strcmp(accountsDB[i].primaryAccountNumber, cardData->primaryAccountNumber) == 0)
        {
            *accountRefrence = accountsDB[i];
            return SERVER_OK;
        }
    }

    return ACCOUNT_NOT_FOUND;
}

// ---------------------------------------------
// isBlockedAccount
//
// Checks if an account is blocked.
// ---------------------------------------------
EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence)
{
    assert(accountRefrence != NULL);

    return accountRefrence->state == BLOCKED ? BLOCKED_ACCOUNT : SERVER_OK;
}

// ---------------------------------------------
// isAmountAvailable
//
// Checks if an account is has enough balance.
// ---------------------------------------------
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence)
{
    assert(termData != NULL);
    assert(accountRefrence != NULL);

    return termData->transAmount > accountRefrence->balance ? LOW_BALANCE : SERVER_OK;
}

// ---------------------------------------------
// saveTransaction
//
// Saves transaction into the database.
// ---------------------------------------------
EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
    assert(transData != NULL);

    if (transactionsCount == MAX_ENTRIES)
    {
        return SAVING_FAILED;
    }

    // I could've used `transactionsCount` directly, but this check is for being aligned with the rubric.
    uint32_t nextSquenceNumber = transactionsCount == 0 ? 1 : transactionsDB[transactionsCount - 1].transactionSequenceNumber + 1;

    transData->transactionSequenceNumber = nextSquenceNumber;

    if (memcpy_s(&transactionsDB[transactionsCount], sizeof(ST_transaction_t), transData, sizeof(ST_transaction_t)) != 0)
    {
        _RPTF0(_CRT_ERROR, "Unexpected error occurred during `memcpy_s`\n");
        return SAVING_FAILED;
    }

    transactionsCount++;

    return SERVER_OK;
}

// ---------------------------------------------
// listSavedTransactions
//
// List transactions saved in the system.
// ---------------------------------------------
void listSavedTransactions(void)
{
    if (transactionsCount == 0)
    {
        puts("~~No transactions~~");
        return;
    }

    for (int i = 0; i < transactionsCount; i++)
    {
        puts("#########################");
        printf("Transaction Sequence Number: %.4d\n", transactionsDB[i].transactionSequenceNumber);
        printf("Transaction Date:            %s\n", transactionsDB[i].terminalData.transactionDate);
        printf("Transaction Amount:          %f\n", transactionsDB[i].terminalData.transAmount);
        printf("Transaction State:           %s\n", TransactionStateToStr(transactionsDB[i].transState));
        printf("Terminal Max Amount:         %f\n", transactionsDB[i].terminalData.maxTransAmount);
        printf("PAN:                         %s\n", transactionsDB[i].cardHolderData.primaryAccountNumber);
        printf("Card Expiration Date:        %s\n", transactionsDB[i].cardHolderData.cardExpirationDate);
        puts("#########################");
        puts("");
    }
}

// ====================================
// ====== Implementation Methods ======
// ====================================

// ---------------------------------------------
// ResetDatabase
//
// Resets the database.
// ---------------------------------------------
void ResetDatabase(void)
{
    accountsDB[0].balance = 2000.0;
    accountsDB[1].balance = 100000.0;
    accountsDB[2].balance = 198000.0;
    accountsDB[3].balance = 0.0;
    accountsDB[4].balance = 500.0;
    accountsDB[5].balance = 5200.0;
    accountsDB[6].balance = 300.0;
    accountsDB[7].balance = 15900.0;
    accountsDB[8].balance = 4000.0;
    accountsDB[9].balance = 0.0;

    memset(transactionsDB, 0, sizeof(transactionsDB));
    transactionsCount = 0;
}

// =============================
// ====== Private Methods ======
// =============================

const char *TransactionStateToStr(EN_transState_t transState)
{
    switch (transState)
    {
    case APPROVED:
        return STRINGIZE(APPROVED);
    case DECLINED_INSUFFECIENT_FUND:
        return STRINGIZE(DECLINED_INSUFFECIENT_FUND);
    case DECLINED_STOLEN_CARD:
        return STRINGIZE(DECLINED_STOLEN_CARD);
    case FRAUD_CARD:
        return STRINGIZE(FRAUD_CARD);
    case INTERNAL_SERVER_ERROR:
        return STRINGIZE(INTERNAL_SERVER_ERROR);
    default:
        return "(unknown)";
    }
}
