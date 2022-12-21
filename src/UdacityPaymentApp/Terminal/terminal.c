/*-----------------------------------------------------------------*\
 *
 * terminal.c
 *   UdacityPaymentApp
 *     udacity-payment-app
 *
 * see LICENSE at root directory
 *
 * CREATED: 2022-12-21 06:19 PM
 * AUTHORS: Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 *
\*-----------------------------------------------------------------*/

#include "pch.h"

#include "../Application/app.h"
#include "terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
    return TERMINAL_OK;
}

EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData)
{
    return TERMINAL_OK;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    return TERMINAL_OK;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    return TERMINAL_OK;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData, float maxAmount)
{
    return TERMINAL_OK;
}

EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData) // Optional
{
    return TERMINAL_OK;
}
