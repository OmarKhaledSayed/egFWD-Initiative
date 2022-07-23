#include "card.h"

/*----------------functions definitions--------------*/
/*------getCardHolderName function definition---------*/
/*This function will ask for the cardholder's name and store it into card data*/
EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	EN_cardError_t WRONG_NAME_Status;
	printf("Enter your cardholder's name, Please!\n");
	gets(cardData->cardHolderName);
	/*Card holder name is 24 characters string max and 20 min*/
	/*If the cardholder name is NULL, less than 20 characters or more than 24 will return WRONG_NAME error, else return OK*/
	if (!(cardData->cardHolderName) ||
		((strlen(cardData->cardHolderName)) < 20) ||
		((strlen(cardData->cardHolderName)) > 24))
	{

		WRONG_NAME_Status = WRONG_NAME;
		printf("INVALID CARD HOLDER NAME!!\n");
	}
	else
	{
		WRONG_NAME_Status = CARD_OK;
		printf("Valid Card Holder Name...\n");
	}
	return WRONG_NAME_Status;
}

/*--------------getCardExpiryDate function definition--------------*/
/*This function will ask for the card expiry date and store it in card data*/
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
	EN_cardError_t WRONG_EXP_DATE_Status;
	printf("Enter the card expiration date in the format ""MM/YY"", e.g ""05/25""\n");
	gets(cardData->cardExpirationDate);
	/*Card expiry date is 5 characters string in the format "MM/YY", e.g "05/25"*/
	/*Knowing that:*/
	/*ASCII code for "/" is 47, I used this check between MM and YY*/
	/*ASCII code for numbers from 0 to 9 is from 47 to 58, so I used this condition in order to check that entered date format*/
	/*If the card expiry date is NULL, less or more than 5 characters, or has the wrong format will return WRONG_EXP_DATE error, else return OK*/
	if ((!(cardData->cardExpirationDate)) ||
		((strlen(cardData->cardExpirationDate)) < 5) ||
		((strlen(cardData->cardExpirationDate)) > 5) ||
		(cardData->cardExpirationDate[2] != 47) ||
		(cardData->cardExpirationDate[0] < 47) ||
		(cardData->cardExpirationDate[0] > 57) ||
		(cardData->cardExpirationDate[1] < 47) ||
		(cardData->cardExpirationDate[1] > 57) ||
		(cardData->cardExpirationDate[3] < 47) ||
		(cardData->cardExpirationDate[3] > 57) ||
		(cardData->cardExpirationDate[4] < 47) ||
		(cardData->cardExpirationDate[4] > 57))
	{
		WRONG_EXP_DATE_Status = WRONG_EXP_DATE;
		printf("WRONG EXPIRATION DATE FORMAT!!\n");
	}
	else
	{
		WRONG_EXP_DATE_Status = CARD_OK;
		printf("Valid Expiration Date Format...\n");
	}
	return WRONG_EXP_DATE_Status;
}
/*--------------getCardPAN function definition----------------*/
/*This function will ask for the card's Primary Account Number and store it in card data*/
/*PAN is 20 characters alphanumeric only string 19 character max, and 16 character min*/
EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
	EN_cardError_t WRONG_PAN_Status = CARD_OK;
	uint8_t index;
	printf("Enter the card's Primary Account Number\n");
	gets(cardData->primaryAccountNumber);
	/*If the PAN is NULL, less than 16 or more than 19 characters, will return WRONG_PAN error, else return OK*/
	if (!((cardData->primaryAccountNumber == NULL) || (strlen(cardData->primaryAccountNumber)) == 0)) {  /*-----> this condition is the NULL check*/
		printf("Valid PAN, is not NULL...\n");
		if (((strlen(cardData->primaryAccountNumber)) >= 16) && ((strlen(cardData->primaryAccountNumber)) < 19)) {
			printf("Valid PAN Length...\n");
			for (index = 0; index < strlen(cardData->primaryAccountNumber); index++) {
				if (((cardData->primaryAccountNumber[index]) >= '0') && ((cardData->primaryAccountNumber[index]) <= '9')) {
				}
				else {
					WRONG_PAN_Status = WRONG_PAN;
				}
			}
			if (WRONG_PAN_Status == WRONG_PAN) {
				printf("WRONG PAN, it is not alphanumeric!!\n");
			}
			else {
				printf("Valid Card PAN, it is alphanumeric...\n");
			}
		}
		else {
			printf("WRONG PAN LENGTH!!\n");
		}
	}
	else{
		printf("WRONG PAN, it is NULL!!\n");
	}
	return WRONG_PAN_Status;
}
