/*
 * button.c
 *
 * Created: 7/25/2022 1:43:48 PM
 *  Author: o.khaled
 */ 
#include "button.h"

//initialize
void BUTTON_init(uint8 buttonPort, uint8 buttonPin) //button is an input device
{
	GPIO_setupPinDirection(buttonPort, buttonPin, PIN_INPUT);	//button

}

//button read
void BUTTON_read(uint8 buttonPort, uint8 buttonPin, uint8 *value)
{
	GPIO_readPin(buttonPort, buttonPin);
}
