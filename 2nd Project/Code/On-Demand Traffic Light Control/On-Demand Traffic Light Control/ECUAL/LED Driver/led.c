/*
 * led.c
 *
 * Created: 7/25/2022 12:42:22 PM
 *  Author: o.khaled
 */ 

#include "led.h"

//functions definition
void LED_init(uint8 ledPort, uint8 ledPin)  //output device
{ 
	GPIO_setupPinDirection(ledPort, ledPin, PIN_OUTPUT);
}
void LED_on(uint8 ledPort, uint8 ledPin)
{
	GPIO_writePin(ledPort, ledPin, LOGIC_HIGH);
}
void LED_off(uint8 ledPort, uint8 ledPin)
{
	GPIO_writePin(ledPort, ledPin, LOGIC_LOW);
}
void LED_toggle(uint8 ledPort, uint8 ledPin)
{
	DIO_toggle(ledPort, ledPin);
}
uint8 LED_read(uint8 ledPort, uint8 ledPin)
{
	GPIO_readPin(ledPort, ledPin);
}

