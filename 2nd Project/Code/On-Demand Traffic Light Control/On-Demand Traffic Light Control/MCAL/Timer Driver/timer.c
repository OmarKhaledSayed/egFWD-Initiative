 /******************************************************************************
 *
 * Module: Timer
 *
 * File Name: timer.c
 *
 * Description: Source file for the timer AVR driver
 *
 * Author: Omar Khaled
 *
 *******************************************************************************/
#include "timer.h"
#include <avr/interrupt.h>

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/

/**************************************************************************
 *                                 Timer0
 * ************************************************************************/
ISR(TIMER0_OVF_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}


/*
 * Description :
 * Function to Initialize Timer Driver:
 * Work in Interrupt Mode
 * Timer initial value
 * Timer_Mode (OverFlow, Compare)
 * if using CTC mode: Timer compare match
 * Timer_Prescaler
 */
void Timer0_init(const TIMER_ConfigType * Config_Ptr)
{
	/*Clear registers of Timer0 before accessing any of them*/
	TCCR0 &= 0X00;
	TCNT0 &= 0X00;
	//OCR0  &= 0X00;
	TIMSK &= 0X00;

	/*
	 * TIMER Pre-scaler value for Timer0 in TCCR0 Register
	 * 0XF8 to make sure that the least 3-bits in TCCR0 register=0
	 * ORing with the chosen timer Pre-scaler to enter it into the least 3-bits
	 */
	TCCR0 = (TCCR0  & 0XF8) | (Config_Ptr -> timer_clock);
	/*
		 * Configure initial value for Timer0 to start count from it
		 */
		TCNT0 = Config_Ptr -> timer_InitialValue;

		SET_BIT(TIMSK, TOIE0); // Enable Timer0 Overflow Interrupt
		/* Configure the timer control register
		 * 1. Non PWM mode FOC0=1
		 * 2. Normal Mode WGM01=0 & WGM00=0
		 * 3. Normal Mode COM00=0 & COM01=0
		 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
		 */
		CLEAR_BIT(TCCR0 , WGM00);
		CLEAR_BIT(TCCR0 , WGM01);
		SET_BIT(TCCR0, FOC0);
		TCCR0 = (1<<CS02) | (1<<CS00);
}

/*
 * Description :  Function to DeInit the timer to start again from beginning.
 *
 */
void Timer_DeInit()
{
	/*Clear all register in Timer0*/
	TCCR0 &= 0X00;
	TCNT0 &= 0X00;
	//OCR0  &= 0X00;
	TIMSK &= 0X00;
}

/*
 * Description : Function to stop the clock of the timer to stop incrementing.
 *
 */
void Timer_stop()
{
	/*
	 * Clear the first 3-bits in TCCR0 register
	 * stop the clock of the timer
	 */
	TCCR0 = (TCCR0 & 0XF8) ;
}

/*
 * Description : Function to set the Call Back function address.
 *
 */
void timer_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr  = a_ptr;
}