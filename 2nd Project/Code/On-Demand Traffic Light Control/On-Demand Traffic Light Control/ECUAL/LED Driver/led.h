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
#define greenLED	PIN0
#define yellowLED	PIN1
#define redLED		PIN2
//PORTS defines
/*cars traffic light port*/
#define carsPORT		PORT_A
/*pedestrians traffic light port*/
#define pedestriansPORT	PORT_B

//functions prototype
void LED_init(uint8_t ledPort, uint8_t ledPin);
void LED_on(uint8_t ledPort, uint8_t ledPin);
void LED_off(uint8_t ledPort, uint8_t ledPin);
void LED_toggle(uint8_t ledPort, uint8_t ledPin);


#endif /* LED_H_ */