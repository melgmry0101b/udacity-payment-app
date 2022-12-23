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
    return SERVER_OK;
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

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence)
{
    return SERVER_OK;
}

EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
    return SERVER_OK;
}

void listSavedTransactions(void)
{

}

// ====================================
// ====== Implementation Methods ======
// ====================================
