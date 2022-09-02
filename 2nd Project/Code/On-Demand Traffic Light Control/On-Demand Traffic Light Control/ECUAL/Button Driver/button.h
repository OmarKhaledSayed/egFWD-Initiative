/*
 * button.h
 *
 * Created: 7/25/2022 1:43:58 PM
 *  Author: o.khaled
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

//including lower layer driver
#include "../../MCAL/DIO Driver/dio.h"
#include <avr/interrupt.h>

#define BUTTON_PORT	PORTD_ID
#define BUTTON_PIN	PIN2_ID

//Button state
#define HIGH	1
#define LOW		0
//prototype functions
//initialize
void BUTTON_init(uint8 buttonPort, uint8 buttonPin);

//button read or button get state (pressed or not)
void BUTTON_read(uint8 buttonPort, uint8 buttonPin, uint8 *value); //pointer(value) to char will be used to save the return value of the button if pressed or not in it



#endif /* BUTTON_H_ */
