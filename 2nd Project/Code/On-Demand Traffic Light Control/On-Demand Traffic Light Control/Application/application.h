/*
 * application.h
 *
 * Created: 8/9/2022 4:23:10 PM
 *  Author: Omar Khaled
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_


//include low layers drivers
#include "../MCAL/DIO Driver/dio.h"
#include "../MCAL/Timer Driver/timer.h"
#include "../ECUAL/Button Driver/button.h"
#include "../ECUAL/LED Driver/led.h"

//prototype functions
void APP_init(void);
void APP_start(void);
void blink_Led_ISR(void);

#endif /* APPLICATION_H_ */