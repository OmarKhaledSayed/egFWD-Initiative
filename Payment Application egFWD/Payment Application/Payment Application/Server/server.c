#include "server.h"

/*--------------------------global variables----------------------------*/
ST_accountsDB_t accounts[MAX_ACCOUNT_NUMBER];
uint32_t current_sequence = 0;
ST_transaction_t transactions_DB[MAX_ACCOUNT_NUMBER] = { 0 };
uint32_t g_PAN_index = 0;
/*-----------------------functions definitions----------------------------*/
/*---------------- Server_init function definition----------------------*/
/*Server_init function is used to initialize accounts Data Base with valid data*/
void DataBase_init(void)
{
	accounts[0].balance = 4252.5;
	accounts[1].balance = 5462.5;
	accounts[2].balance = 5514.5;
	accounts[3].balance = 1235.5;
	accounts[4].balance = 3545.5;
	strcpy((char*)accounts[0].primaryAccountNumber, "8811691184512646");
	strcpy((char*)accounts[1].primaryAccountNumber, "7825834626310106");
	strcpy((char*)accounts[2].primaryAccountNumber, "7362101737811789");
	strcpy((char*)accounts[3].primaryAccountNumber, "5669626789229922");
	strcpy((char*)accounts[4].primaryAccountNumber, "1826909489219578");
}
/*---------------- isValidAccount function definition----------------------*/
EN_serverError_t isValidAccount(ST_cardData_t* cardData) {
	EN_serverError_t isValidAccount_Status;
	int32_t PAN_index = searchforPAN(cardData);
	if(PAN_index == -1){
			isValidAccount_Status = ACCOUNT_NOT_FOUND;
			printf("ACCOUNT NOT FOUND!!\n");
	}
	else {
			isValidAccount_Status = SERVER_OK;
			printf("Valid Account...\n");
	}
	return isValidAccount_Status;
}
/*---------------- searchforPAN function definition----------------------*/
int32_t searchforPAN(ST_cardData_t* cardData) {
	g_PAN_index = -1;
	for (int i = 0; i < MAX_ACCOUNT_NUMBER; i++) {
		if (strcmp((char*)cardData->primaryAccountNumber, (char*)accounts[i].primaryAccountNumber) == 0) {
			g_PAN_index = i;
			break;
		}
	}
	return g_PAN_index;
}
/*---------------- isAmountAvailable function definition----------------------*/
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData) {
	EN_serverError_t LOW_BALANCE_Status;
	if (termData->transAmount <= accounts[g_PAN_index].balance) {
		LOW_BALANCE_Status = SERVER_OK;
		printf("Available Amount...\n");
	}
	else {
		LOW_BALANCE_Status = LOW_BALANCE;
		printf("Declined Insufficient Funds!!\n");
	}
	return LOW_BALANCE_Status;
}
/*---------------- saveTransaction function definition----------------------*/
EN_serverError_t saveTransaction(ST_transaction_t* transData) {
	EN_serverError_t saveTransaction_Status = SERVER_OK;
	transactions_DB[transData->transactionSequenceNumber] = *transData;
	transData->transactionSequenceNumber = current_sequence;
	current_sequence++;
	return saveTransaction_Status;
}
/*---------------- recieveTransactionData function definition----------------------*/
EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	EN_transState_t recieveTransactionData_Status;
	if (isValidAccount(&transData->cardHolderData) == ACCOUNT_NOT_FOUND)
	{
		recieveTransactionData_Status = DECLINED_STOLEN_CARD;
		printf("DECLINED STOLEN CARD!!\n");
	}
	else if (isAmountAvailable(&transData->terminalData) == LOW_BALANCE) {
		recieveTransactionData_Status = DECLINED_INSUFFECIENT_FUND;
		printf("DECLINED INSUFFECIENT FUND!!\n");
	}
	else if (saveTransaction(transData) == SAVING_FAILED) {
		recieveTransactionData_Status = INTERNAL_SERVER_ERROR;
		printf("INTERNAL SERVER ERROR!!\n");
	}
	else {
		recieveTransactionData_Status = APPROVED;
		printf("Balance Value before transaction = %f LE\n", accounts[g_PAN_index].balance);
		accounts[g_PAN_index].balance -= transData->terminalData.transAmount;
		printf("Balance value after transaction = %f LE\n", accounts[g_PAN_index].balance);
		printf("Account Balance Updated Sucessfully!\n");
	}
	return recieveTransactionData_Status;
}


/*---------------- getTransaction function definition----------------------*/
// EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t *transData){
//}
