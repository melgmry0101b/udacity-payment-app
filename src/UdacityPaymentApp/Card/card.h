/*-----------------------------------------------------------------*\
 *
 * card.h
 *   UdacityPaymentApp
 *     udacity-payment-app
 *
 * see LICENSE at root directory
 *
 * CREATED: 2022-12-21 06:19 PM
 * AUTHORS: Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 *
\*-----------------------------------------------------------------*/

#ifndef UDACITYPAYAPP_CARD_H
#define UDACITYPAYAPP_CARD_H

// ==================
// ====== Defs ======
// ==================

// NOTE: As the prototypes are required to be present as-is, we can't use these defs
//  in the prototypes, but we have to use them everywhere else.

#define CARD_HOLDER_NAME_BUF_SIZE   25
#define CARD_HOLDER_NAME_MAX_LEN    24
#define CARD_HOLDER_NAME_MIN_LEN    20

#define CARD_EXP_DATE_BUF_SIZE  6
#define CARD_EXP_DATE_LEN       5

#define CARD_PAN_BUF_SIZE   20
#define CARD_PAN_MAX_LEN    19
#define CARD_PAN_MIN_LEN    16

// ===================
// ====== Types ======
// ===================

typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef enum EN_cardError_t
{
    CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;

// =====================
// ====== Methods ======
// =====================

EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);

// ====================================
// ====== Implementation Methods ======
// ====================================

// ---------------------------------------------
// Processes the input data and copy to output
//  if applicable.
// ---------------------------------------------
EN_cardError_t CardProcessGetCardHolderName(ST_cardData_t *cardData, const uint8_t *cardHolderName, size_t cardHolderNameSize);

// ---------------------------------------------
// Processes the input date and copy to output
//  if applicable.
// ---------------------------------------------
EN_cardError_t CardProcessCardExpiryDate(ST_cardData_t *cardData, const uint8_t *cardExpiryDate, size_t cardExpiryDateSize);

// ---------------------------------------------
// Processes the input PAN and copy to output
//  if applicable.
// ---------------------------------------------
EN_cardError_t CardProcessCardPAN(ST_cardData_t *cardData, const uint8_t *cardPAN, size_t cardPANSize);

#endif
