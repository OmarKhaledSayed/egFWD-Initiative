#include "terminal.h"

/*----------------------- functions definitions -------------------------------*/
/*---------------- getTransactionDate function definition----------------------*/
EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {
	EN_terminalError_t WRONG_DATE_Status = TERMINAL_OK;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(termData->transactionDate, "%d/%02d/%02d\n", tm.tm_mday, (tm.tm_mon + 1), (tm.tm_year + 1900));
	printf("Fetching transaction date ..\n");
	printf("transaction date is %s\n", termData->transactionDate);
	return WRONG_DATE_Status;
}
/*--------------------------------------------------------------------------------------------*/
/*---------------- isCardExpired function definition----------------------*/
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData) {
	EN_terminalError_t EXPIRED_CARD_Status = TERMINAL_OK;
	if (cardData.cardExpirationDate[3] > termData.transactionDate[8]) {
		EXPIRED_CARD_Status = TERMINAL_OK;
	}
	if (cardData.cardExpirationDate[3] < termData.transactionDate[8]) {
		EXPIRED_CARD_Status = EXPIRED_CARD;
	}
	if (cardData.cardExpirationDate[3] == termData.transactionDate[8]) {
		if (cardData.cardExpirationDate[4] > termData.transactionDate[9]) {
			EXPIRED_CARD_Status = TERMINAL_OK;
		}
		else if (cardData.cardExpirationDate[4] < termData.transactionDate[9]) {
			EXPIRED_CARD_Status = EXPIRED_CARD;
		}
		else {
			if (cardData.cardExpirationDate[0] > termData.transactionDate[3]) {
				EXPIRED_CARD_Status = TERMINAL_OK;
			}
			else if (cardData.cardExpirationDate[0] < termData.transactionDate[3]) {
				EXPIRED_CARD_Status = EXPIRED_CARD;
			}
			else {
				if (cardData.cardExpirationDate[1] > termData.transactionDate[4]) {
					EXPIRED_CARD_Status = TERMINAL_OK;
				}
				else if (cardData.cardExpirationDate[1] < termData.transactionDate[4]) {
					EXPIRED_CARD_Status = EXPIRED_CARD;
				}
				else {
					EXPIRED_CARD_Status = TERMINAL_OK;
				}
			}

		}

	}
	return EXPIRED_CARD_Status;
}
/*--------------------------------------------------------------------------------------------*/
/*----------------------- getTransactionAmount function definition----------------------*/

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {
	EN_terminalError_t INVALID_AMOUNT_Status = TERMINAL_OK;
	printf("Enter the transaction amount in LE, Knowing that the Maximum Amount per transaction is 10000 LE\n");
	scanf("%f", &termData->transAmount);
	if (termData->transAmount <= 0) {
		INVALID_AMOUNT_Status = INVALID_AMOUNT;
		printf("INVALID AMOUNT, less than or equal zero !!\n");
	}
	return INVALID_AMOUNT_Status;
}
/*--------------------------------------------------------------------------------------------*/
/*----------------------- isBelowMaxAmount function definition----------------------*/
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {
	EN_terminalError_t EXCEED_MAX_AMOUNT_Status = TERMINAL_OK;
	if (termData->transAmount > termData->maxTransAmount) {
		EXCEED_MAX_AMOUNT_Status = EXCEED_MAX_AMOUNT;
	}
	return EXCEED_MAX_AMOUNT_Status;
}
/*--------------------------------------------------------------------------------------------*/
/*----------------------- setMaxAmount function definition----------------------*/
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData) {
	EN_terminalError_t INVALID_MAX_AMOUNT_Status = TERMINAL_OK;
	termData->maxTransAmount = MaxAmount;
	if (termData->maxTransAmount <= 0) {
		INVALID_MAX_AMOUNT_Status = INVALID_MAX_AMOUNT;
	}
	return INVALID_MAX_AMOUNT_Status;
}
/*--------------------------------------------------------------------------------------------*/
/*----------------------- isValidCardPAN function definition----------------------*/
EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData) {
	EN_terminalError_t isValidCardPAN_Status;
	/*Luhn Algorithm checker to chech PAN is a luhn number or not*/
	/*I searched about the algorithm, understand it then I wrote down it with the help of code from geeksforgeeks below*/
	/*References: https://www.geeksforgeeks.org/luhn-algorithm */
	int nDigits = 16;
	int nSum = 0, isSecond = F;
	for (int i = nDigits - 1; i >= 0; i--) {
		int d = cardData->primaryAccountNumber[i] - '0';
		if (isSecond == T) {
			d = d * 2;
		}
		nSum += d / 10;
		nSum += d % 10;
		isSecond = !isSecond;
	}
	/*the conditional if checks on the return if it returns 1 then it will be a Luhn number otherwise it will not a luhn number*/
	if (nSum % 10 == 0) {
		isValidCardPAN_Status = TERMINAL_OK;
		printf("PAN is a Luhn number\n");
	}
	else {
		isValidCardPAN_Status = INVALID_CARD;
		printf("PAN is not a Luhn number\n");
	}
	return isValidCardPAN_Status;
}
