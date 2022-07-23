#include "app.h"
#include <stdio.h>
#include <string.h>

void appStart(void) {
	/*objects from structures types*/
	ST_cardData_t VISAData;
	ST_terminalData_t ATMData;
	/*global variables*/
	extern ST_accountsDB_t accounts[MAX_ACCOUNT_NUMBER];
	extern uint32_t current_sequence;
	extern ST_transaction_t transactions_DB[MAX_ACCOUNT_NUMBER];
	extern g_PAN_index;
	/*-------------Card Module functions call---------*/
	getCardHolderName(&VISAData);
	getCardExpiryDate(&VISAData);
	getCardPAN(&VISAData);
	/*------------Terminal Module function call----------*/
	if (isValidCardPAN(&VISAData) == INVALID_CARD) {
		printf("INVALID CARD!!\n");
		return 0;
	}
	else {
		printf("Valid Card PAN...\n");
	}
	getTransactionDate(&ATMData);
	if (isCardExpired(VISAData, ATMData) == EXPIRED_CARD) {
		printf("Declined Expired Card!\n");
		return 0;
	}
	else {
		printf("Valid Expiration Date...\n");
	}
	getTransactionAmount(&ATMData);
	setMaxAmount(&ATMData);
	if (isBelowMaxAmount(&ATMData) == EXCEED_MAX_AMOUNT) {
		printf("Declined Amount Exceeding Limit!\n");
		return 0;
	}
	else {
		printf("Valid Transaction Amount...\n");
	}
	/*------------Server Module function call----------*/
	/*DataBase_init function is used to initialize the Accounts global varibale with valid data*/
	DataBase_init();
	/*then we will update the transactions_DB with the transactions values entered by the user*/
	transactions_DB[current_sequence].cardHolderData = VISAData;
	transactions_DB[current_sequence].terminalData = ATMData;
	/*recieveTransactionData function will validate the data of transaction then update the account balance*/
	recieveTransactionData(&transactions_DB);
}


