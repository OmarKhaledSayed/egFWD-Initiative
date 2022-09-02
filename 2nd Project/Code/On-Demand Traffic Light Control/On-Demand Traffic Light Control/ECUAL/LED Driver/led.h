/*
 * led.h
 *
 * Created: 7/25/2022 12:42:12 PM
 *  Author: o.khaled
 */ 

#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"

//LEDs defines
#define greenLED	PIN0_ID
#define yellowLED	PIN1_ID
#define redLED		PIN2_ID
//PORTS defines
/*cars traffic light port*/
#define carsPORT		PORTA_ID
/*pedestrians traffic light port*/
#define pedestriansPORT	PORTB_ID

//functions prototype
void LED_init(uint8 ledPort, uint8 ledPin);
void LED_on(uint8 ledPort, uint8 ledPin);
void LED_off(uint8 ledPort, uint8 ledPin);
void LED_toggle(uint8 ledPort, uint8 ledPin);
uint8 LED_read(uint8 ledPort, uint8 ledPin);

#endif /* LED_H_ */
