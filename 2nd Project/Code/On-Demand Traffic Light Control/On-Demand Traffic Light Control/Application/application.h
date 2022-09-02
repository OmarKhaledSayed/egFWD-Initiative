/*
 * application.h
 *
 * Created: 8/9/2022 4:23:10 PM
 *  Author: Omar Khaled
 */ 

#ifndef APPLICATION_H_
#define APPLICATION_H_


/*******************************************************************************
 *                               LOWER LAYERS DRIVERS INCLUDES                  *
 *******************************************************************************/
#include "../MCAL/DIO Driver/dio.h"
#include "../MCAL/Timer Driver/timer.h"
#include "../ECUAL/Button Driver/button.h"
#include "../ECUAL/LED Driver/led.h"

/*******************************************************************************
 *                                Functions Definitions                         *
 *******************************************************************************/
#define NUMBER_OF_INTTERUPT_PER_SECOND 4
#define NUMBER_OF_INTTERUPT_PER_5SECOND 19


void TL_5SEC_Tick_Processing(void);
void TL_SEC_Tick_Processing(void);
void TL_SEC(void);
void normal_mode(void);
void TL_5SEC(void);
void pedestrian_mode(void);
void App_init(void);
void App_start(void);
#endif /* APPLICATION_H_ */
