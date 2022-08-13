 /******************************************************************************
 *
 * Module: Timer
 *
 * File Name: timer.h
 *
 * Description: Header file for the timer AVR driver
 *
 * Author: Omar Khaled
 *
 *******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/StdTypes.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
/*******************************************************************************
 *                         Configurations                                      *
 *******************************************************************************/
#define HALF_SECOND 2
#define FIVE_SECOND 19

/*TCCR0 register bits defines*/
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0 7

typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Timer_Clock;


typedef struct
{
	uint32_t timer_InitialValue;
	uint32_t timer_CompareValue;
	Timer_Clock timer_clock;
}TIMER_ConfigType;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function to Initialize Timer Driver:
 * Work in Interrupt Mode
 * Timer initial value
 * Timer_Mode (OverFlow, Compare)
 * if using CTC mode: Timer compare match
 * Timer_Prescaler
 */
void Timer0_init(const TIMER_ConfigType * Config_Ptr);

/*
 * Description: Function to set the Call Back function address.
 */
void timer_setCallBack(void(*a_ptr)(void));

/*
 * Description: Function to stop the clock of the timer to stop incrementing.
 */
void Timer_stop();

/*
 * Description: Function to DeInit the timer to start again from beginning.
 */
void Timer_DeInit();

#endif /* TIMER_H_ */
