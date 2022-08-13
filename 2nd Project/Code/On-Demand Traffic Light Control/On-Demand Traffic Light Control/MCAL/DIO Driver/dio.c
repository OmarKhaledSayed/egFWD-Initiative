/*
 * dio.c
 *
 * Created: 7/25/2022 9:29:53 AM
 *  Author: o.khaled
 */ 

/*----------------------contents-------------------------------*/
/*
1- include.h (lower layer drivers)
2- all global variables
3- all functions definitions
*/
/*-------------------------------------------------------------*/

//include.h (lower layer drivers)
#include "dio.h"

//global variables
//function definitions
EN_DIOError_t g_DIOError = DIO_OK;
EN_DIOError_t DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction){
	switch (portNumber)
	{
		case PORT_A:
			if(direction == IN)
			{
				/*DDRA &=~ (1<<pinNumber);*/ //input
				/*implement clear bit function its arguments are DDRx and pinNumber*/
				CLEAR_BIT(DDRA, pinNumber);
			}
			else if(direction == OUT)
			{
				//DDRA |= (1<<pinNumber); //output
				SET_BIT(DDRA, pinNumber);
			}
			else
			{
				//Error handling
				//we will change the return of the function and will return error status
				g_DIOError = DIO_init_ERROR;
			}
		break;
		case PORT_B:
			if(direction == IN)
			{
				//DDRB &=~ (1<<pinNumber); //input
				CLEAR_BIT(DDRB, pinNumber);
			}
			else if(direction == OUT)
			{
				//DDRB |= (1<<pinNumber); //output
				SET_BIT(DDRB, pinNumber);
			}
			else
			{
				//Error handling
				//we will change the return of the function and will return error status
				g_DIOError = DIO_init_ERROR;
			}
		break;
		case PORT_C:
			if(direction == IN)
			{
				//DDRC &=~ (1<<pinNumber); //input
				CLEAR_BIT(DDRC, pinNumber);
			}
			else if(direction == OUT)
			{
				//DDRC |= (1<<pinNumber); //output
				SET_BIT(DDRC, pinNumber);
			}
			else
			{
				//Error handling
				//we will change the return of the function and will return error status
				g_DIOError = DIO_init_ERROR;
			}
		break;
		case PORT_D:
			if(direction == IN)
			{
				//DDRD &=~ (1<<pinNumber); //input
				CLEAR_BIT(DDRD, pinNumber);
			}
			else if(direction == OUT)
			{
				//DDRD |= (1<<pinNumber); //output
				SET_BIT(DDRD, pinNumber);
			}
			else
			{
				//Error handling
				//we will change the return of the function and will return error status
				g_DIOError = DIO_init_ERROR;
			}
		break;
	}
	return g_DIOError;
}
EN_DIOError_t DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value){
	switch (portNumber)
	{
		case PORT_A:
		if(value == LOW)
		{
			//PORTA &=~ (1<<pinNumber); //write 0
			CLEAR_BIT(PORTA, pinNumber);
		}
		else if(value == HIGH)
		{
			//PORTA |= (1<<pinNumber); //write 1
			SET_BIT(PORTA, pinNumber);
		}
		else
		{
			//Error handling
			//we will change the return of the function and will return error status
			g_DIOError = DIO_write_ERROR;
		}
		break;
		case PORT_B:
		if(value == LOW)
		{
			//PORTB &=~ (1<<pinNumber); //write 0
			CLEAR_BIT(PORTB, pinNumber);
		}
		else if(value == HIGH)
		{
			//PORTB |= (1<<pinNumber); //write 1
			SET_BIT(PORTB, pinNumber);
		}
		else
		{
			//Error handling
			//we will change the return of the function and will return error status
			g_DIOError = DIO_write_ERROR;
		}
		break;
		case PORT_C:
		if(value == LOW)
		{
			//PORTC &=~ (1<<pinNumber); //write 0
			CLEAR_BIT(PORTC, pinNumber);
		}
		else if(value == HIGH)
		{
			//PORTC |= (1<<pinNumber); //write 1
			SET_BIT(PORTC, pinNumber);
		}
		else
		{
			//Error handling
			//we will change the return of the function and will return error status
			g_DIOError = DIO_write_ERROR;
		}
		break;
		case PORT_D:
		if(value == LOW)
		{
			//PORTD &=~ (1<<pinNumber); //write 0
			CLEAR_BIT(PORTD, pinNumber);
		}
		else if(value == HIGH)
		{
			//PORTD |= (1<<pinNumber); //write 1
			SET_BIT(PORTD, pinNumber);
		}
		else
		{
			//Error handling
			//we will change the return of the function and will return error status
			g_DIOError = DIO_write_ERROR;
		}
		break;
	}
	return g_DIOError;
}
EN_DIOError_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber){ //toggle dio
		switch (portNumber)
		{
			case PORT_A:
			TOGGLE_BIT(PORTA, pinNumber);
			break;
			case PORT_B:
			TOGGLE_BIT(PORTB, pinNumber);
			break;
			case PORT_C:
			TOGGLE_BIT(PORTC, pinNumber);
			break;
			case PORT_D:
			TOGGLE_BIT(PORTD, pinNumber);
			break;
			default:
			g_DIOError = DIO_toggle_ERROR;
		}
		return g_DIOError;
	}
EN_DIOError_t DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value){ //read dio
		switch (portNumber)
		{
			case PORT_A:
			*value = (PORTA & (1<<pinNumber))>>pinNumber; //get state ->read bit
			break;
			case PORT_B:
			*value = (PORTB & (1<<pinNumber))>>pinNumber; //get state ->read bit
			break;
			case PORT_C:
			*value = (PORTC & (1<<pinNumber))>>pinNumber; //get state ->read bit
			break;
			case PORT_D:
			*value = (PORTD & (1<<pinNumber))>>pinNumber; //get state ->read bit
			break;
			default:
			g_DIOError = DIO_read_ERROR;
		}
		return g_DIOError;
	} 