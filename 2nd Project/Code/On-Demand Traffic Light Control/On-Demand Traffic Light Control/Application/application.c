/*
 * application.c
 *
 * Created: 8/9/2022 4:23:24 PM
 *  Author: Omar Khaled
 */ 
#include "application.h"
//global variables
uint32_t g_CarTrafficLightState = 0;
uint32_t g_counter = 0;
uint32_t g_tick = 0;
/*App_init function initialize all the needed drivers to be initialized such as button driver, led driver, global interrupts*/
void APP_init(void)
{
	/*initialize the cars LEDs*/
	LED_init(PORT_A,PIN0);
	LED_init(PORT_A,PIN1);
	LED_init(PORT_A,PIN2);
	/*initialize the pedestrians LEDs*/
	LED_init(PORT_B,PIN0);
	LED_init(PORT_B,PIN1);
	LED_init(PORT_B,PIN2);
	/*initialize the pedestrians button*/
	BUTTON_init(PORT_D, PIN2);
	/*global interrupt flag I-bit for interrupts*/
	SET_BIT(SREG,PIN7); //turn on global interrupts
	/*Timer Initialization*/
	//calling timer init function
}
/*App_start function it have all the application flow included in while loop*/
void APP_start(void)
{
	while(1)
	{

	}
	
}
//blink led ISR
void blink_Led_ISR(void)
{
	static uint32_t flag = 0;
	g_counter ++;
	if(g_counter <= 9)
	{
		if(flag == 0)
		{
			LED_on(carsPORT,yellowLED);
			flag = 1;
		}
		else
		{
			LED_off(carsPORT,yellowLED);
			flag = 0;
		}
	}
	else
	{
		g_counter = 0;
	}
}
ISR(TIMER0_OVF_vect)
{
	g_tick++;
	if(g_tick == HALF_SECOND && g_counter != 0)
	{
		blink_Led_ISR();
	}
	else if(g_tick == FIVE_SECOND)
	{
		if(g_CarTrafficLightState == 0)
		{
			LED_on(carsPORT, greenLED);
			g_CarTrafficLightState ++;
		}
		else if( g_CarTrafficLightState == 1)
		{
			g_CarTrafficLightState ++;
		}
		else if(g_CarTrafficLightState ==2)
		{
			LED_on(carsPORT, redLED);
			g_CarTrafficLightState --;
		}
		else
		{
			//error handling
		}
	}
	else
	{
		g_tick=0; // reset the ticks counter
	}
}