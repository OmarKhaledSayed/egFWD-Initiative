/*
 * button.c
 *
 * Created: 7/25/2022 1:43:48 PM
 *  Author: o.khaled
 */ 
#include "button.h"

//initialize
void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin) //button is an input device
{
	DIO_init(buttonPin, buttonPort, IN);//IN as the button is input device
}

//button read
void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value)
{
	DIO_read(buttonPort, buttonPin, value);
}
