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

// =====================
// ====== Methods ======
// =====================

EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{
    return SERVER_OK;
}

EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountRefrence)
{
    return SERVER_OK;
}

EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence)
{
    return SERVER_OK;
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
