/*
 * dio.c
 *
 * Created: 7/25/2022 9:29:53 AM
 *  Author: o.khaled
 */ 

// /*----------------------contents-------------------------------*/
// /*
// 1- include.h (lower layer drivers)
// 2- all global variables
// 3- all functions definitions
// */
// /*-------------------------------------------------------------*/
// 
// //include.h (lower layer drivers)
// #include "dio.h"
// 
// //global variables
// //function definitions
// EN_DIOError_t g_DIOError = DIO_OK;
// EN_DIOError_t DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction){
// 	switch (portNumber)
// 	{
// 		case PORT_A:
// 			if(direction == IN)
// 			{
// 				/*DDRA &=~ (1<<pinNumber);*/ //input
// 				/*implement clear bit function its arguments are DDRx and pinNumber*/
// 				CLEAR_BIT(DDRA, pinNumber);
// 			}
// 			else if(direction == OUT)
// 			{
// 				//DDRA |= (1<<pinNumber); //output
// 				SET_BIT(DDRA, pinNumber);
// 			}
// 			else
// 			{
// 				//Error handling
// 				//we will change the return of the function and will return error status
// 				g_DIOError = DIO_init_ERROR;
// 			}
// 		break;
// 		case PORT_B:
// 			if(direction == IN)
// 			{
// 				//DDRB &=~ (1<<pinNumber); //input
// 				CLEAR_BIT(DDRB, pinNumber);
// 			}
// 			else if(direction == OUT)
// 			{
// 				//DDRB |= (1<<pinNumber); //output
// 				SET_BIT(DDRB, pinNumber);
// 			}
// 			else
// 			{
// 				//Error handling
// 				//we will change the return of the function and will return error status
// 				g_DIOError = DIO_init_ERROR;
// 			}
// 		break;
// 		case PORT_C:
// 			if(direction == IN)
// 			{
// 				//DDRC &=~ (1<<pinNumber); //input
// 				CLEAR_BIT(DDRC, pinNumber);
// 			}
// 			else if(direction == OUT)
// 			{
// 				//DDRC |= (1<<pinNumber); //output
// 				SET_BIT(DDRC, pinNumber);
// 			}
// 			else
// 			{
// 				//Error handling
// 				//we will change the return of the function and will return error status
// 				g_DIOError = DIO_init_ERROR;
// 			}
// 		break;
// 		case PORT_D:
// 			if(direction == IN)
// 			{
// 				//DDRD &=~ (1<<pinNumber); //input
// 				CLEAR_BIT(DDRD, pinNumber);
// 			}
// 			else if(direction == OUT)
// 			{
// 				//DDRD |= (1<<pinNumber); //output
// 				SET_BIT(DDRD, pinNumber);
// 			}
// 			else
// 			{
// 				//Error handling
// 				//we will change the return of the function and will return error status
// 				g_DIOError = DIO_init_ERROR;
// 			}
// 		break;
// 	}
// 	return g_DIOError;
// }
// EN_DIOError_t DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value){
// 	switch (portNumber)
// 	{
// 		case PORT_A:
// 		if(value == LOW)
// 		{
// 			//PORTA &=~ (1<<pinNumber); //write 0
// 			CLEAR_BIT(PORTA, pinNumber);
// 		}
// 		else if(value == HIGH)
// 		{
// 			//PORTA |= (1<<pinNumber); //write 1
// 			SET_BIT(PORTA, pinNumber);
// 		}
// 		else
// 		{
// 			//Error handling
// 			//we will change the return of the function and will return error status
// 			g_DIOError = DIO_write_ERROR;
// 		}
// 		break;
// 		case PORT_B:
// 		if(value == LOW)
// 		{
// 			//PORTB &=~ (1<<pinNumber); //write 0
// 			CLEAR_BIT(PORTB, pinNumber);
// 		}
// 		else if(value == HIGH)
// 		{
// 			//PORTB |= (1<<pinNumber); //write 1
// 			SET_BIT(PORTB, pinNumber);
// 		}
// 		else
// 		{
// 			//Error handling
// 			//we will change the return of the function and will return error status
// 			g_DIOError = DIO_write_ERROR;
// 		}
// 		break;
// 		case PORT_C:
// 		if(value == LOW)
// 		{
// 			//PORTC &=~ (1<<pinNumber); //write 0
// 			CLEAR_BIT(PORTC, pinNumber);
// 		}
// 		else if(value == HIGH)
// 		{
// 			//PORTC |= (1<<pinNumber); //write 1
// 			SET_BIT(PORTC, pinNumber);
// 		}
// 		else
// 		{
// 			//Error handling
// 			//we will change the return of the function and will return error status
// 			g_DIOError = DIO_write_ERROR;
// 		}
// 		break;
// 		case PORT_D:
// 		if(value == LOW)
// 		{
// 			//PORTD &=~ (1<<pinNumber); //write 0
// 			CLEAR_BIT(PORTD, pinNumber);
// 		}
// 		else if(value == HIGH)
// 		{
// 			//PORTD |= (1<<pinNumber); //write 1
// 			SET_BIT(PORTD, pinNumber);
// 		}
// 		else
// 		{
// 			//Error handling
// 			//we will change the return of the function and will return error status
// 			g_DIOError = DIO_write_ERROR;
// 		}
// 		break;
// 	}
// 	return g_DIOError;
// }

// EN_DIOError_t DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value){ //read dio
// 		switch (portNumber)
// 		{
// 			case PORT_A:
// 			*value = (PORTA & (1<<pinNumber))>>pinNumber; //get state ->read bit
// 			break;
// 			case PORT_B:
// 			*value = (PORTB & (1<<pinNumber))>>pinNumber; //get state ->read bit
// 			break;
// 			case PORT_C:
// 			*value = (PORTC & (1<<pinNumber))>>pinNumber; //get state ->read bit
// 			break;
// 			case PORT_D:
// 			*value = (PORTD & (1<<pinNumber))>>pinNumber; //get state ->read bit
// 			break;
// 			default:
// 			g_DIOError = DIO_read_ERROR;
// 		}
// 		return g_DIOError;
// 	} 
	/*-----------------------------------------------------------------------------*/
#include "dio.h"
#include "../../Utilities/bit_manipulation.h" /* To use the macros like SET_BIT */

//#include "avr/io.h" /* To use the IO Ports Registers */

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRA,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA,pin_num);
			}
			break;
		case PORTB_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRB,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB,pin_num);
			}
			break;
		case PORTC_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRC,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC,pin_num);
			}
			break;
		case PORTD_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRD,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD,pin_num);
			}
			break;
		}
	}
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the pin value as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTA,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTA,pin_num);
			}
			break;
		case PORTB_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTB,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTB,pin_num);
			}
			break;
		case PORTC_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTC,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC,pin_num);
			}
			break;
		case PORTD_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTD,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTD,pin_num);
			}
			break;
		}
	}
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	uint8 pin_value = LOGIC_LOW;

	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the pin value as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(BIT_IS_SET(PINA,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(PINB,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(PINC,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(PIND,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		}
	}

	return pin_value;
}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the port direction as required */
		switch(port_num)
		{
		case PORTA_ID:
			DDRA = direction;
			break;
		case PORTB_ID:
			DDRB = direction;
			break;
		case PORTC_ID:
			DDRC = direction;
			break;
		case PORTD_ID:
			DDRD = direction;
			break;
		}
	}
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the port value as required */
		switch(port_num)
		{
		case PORTA_ID:
			PORTA = value;
			break;
		case PORTB_ID:
			PORTB = value;
			break;
		case PORTC_ID:
			PORTC = value;
			break;
		case PORTD_ID:
			PORTD = value;
			break;
		}
	}
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_readPort(uint8 port_num)
{
	uint8 value = LOGIC_LOW;

	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the port value as required */
		switch(port_num)
		{
		case PORTA_ID:
			value = PINA;
			break;
		case PORTB_ID:
			value = PINB;
			break;
		case PORTC_ID:
			value = PINC;
			break;
		case PORTD_ID:
			value = PIND;
			break;
		}
	}

	return value;
}
void DIO_toggle(uint8 portNumber, uint8 pinNumber){ //toggle dio
	switch (portNumber)
	{
		case PORTA_ID:
		TOGGLE_BIT(PORTA, pinNumber);
		break;
		case PORTB_ID:
		TOGGLE_BIT(PORTB, pinNumber);
		break;
		case PORTC_ID:
		TOGGLE_BIT(PORTC, pinNumber);
		break;
		case PORTD_ID:
		TOGGLE_BIT(PORTD, pinNumber);
		break;
	}
}
