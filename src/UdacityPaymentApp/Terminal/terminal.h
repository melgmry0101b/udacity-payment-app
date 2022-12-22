/*-----------------------------------------------------------------*\
 *
 * terminal.h
 *   UdacityPaymentApp
 *     udacity-payment-app
 *
 * see LICENSE at root directory
 *
 * CREATED: 2022-12-21 06:19 PM
 * AUTHORS: Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 *
\*-----------------------------------------------------------------*/

#ifndef UDACITYPAYAPP_TERMINAL_H
#define UDACITYPAYAPP_TERMINAL_H

// ==================
// ====== Defs ======
// ==================

#define TERMINAL_TRANSACTION_DATE_BUF_SIZE  11
#define TERMINAL_TRANSACTION_DATE_LEN       10

#define TERMINAL_AMOUNTS_MAX_INPUT_LEN 25 // Includes sign and decimal

// ===================
// ====== Types ======
// ===================

typedef struct ST_terminalData_t
{
    float transAmount;
    float maxTransAmount;
    uint8_t transactionDate[11];
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
    TERMINAL_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t;

// =====================
// ====== Methods ======
// =====================

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData);
EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData);
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData);
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData, float maxAmount);
EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData); // Optional

// ====================================
// ====== Implementation Methods ======
// ====================================

// ---------------------------------------------
// Processes the input date and copy to output
//  if applicable.
// ---------------------------------------------
EN_terminalError_t TerminalProcessTransactionDate(
    ST_terminalData_t *termData,
    const uint8_t *transactionDate,
    size_t transactionDateSize);

// ---------------------------------------------
// Processes the input amount and copy to output
//  if applicable.
// ---------------------------------------------
EN_terminalError_t TerminalProcessTransactionAmount(ST_terminalData_t *termData, float amount);

#endif
