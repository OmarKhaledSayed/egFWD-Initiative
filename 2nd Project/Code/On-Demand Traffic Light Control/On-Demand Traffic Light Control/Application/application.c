
/*
 * application.c
 *
 * Created: 8/9/2022 4:23:24 PM
 *  Author: Omar Khaled
 */ 

#include "application.h"

//global variables

uint8 volatile g_flag_5sec = 0; // flag to indicate 5 seconds passed
uint8 volatile g_flag_1sec = 0;	// flag to indicate 1 second passed
uint8 volatile g_5sec_c = 0;	// counter for 5 sec
uint8 volatile g_1sec_c = 0; 	// counter for 1 sec
uint8 volatile g_Count_SEC = 0; // counter for overflow of timer 0
uint8 volatile g_Mode_Flag=0;	// flag to indicate the mode of the traffic light (0: for normal mode , 1: for pedestrian mode)


// modes states
uint8 volatile normal_mode_state = 0;
uint8 volatile pedestrian_mode_state = 0;

ISR(INT0_vect)
{
	g_Mode_Flag = 1; // change mode to pedestrian mode
	// reset timer
	g_5sec_c = 0;
	g_1sec_c = 0;
	g_Count_SEC = 0;
}



void TL_5SEC_Tick_Processing(void) {
	g_Count_SEC++;
	// if 1 sec passed
	if (g_Count_SEC == NUMBER_OF_INTTERUPT_PER_SECOND) {
		g_Count_SEC = 0;
		g_5sec_c++;
		g_1sec_c++;

		// if 5 sec passed
		if (g_5sec_c == 5) {
			g_5sec_c = 0;
			//set flag to 1
			g_flag_5sec = 1;
		}
		// if 1 sec passed
		if (g_1sec_c == 1) {
			g_1sec_c = 0;
			//set flag to 1
			g_flag_1sec = 1;
		}
	}
}

void TL_5SEC(void) {
	TIMER_ConfigType TIMER_Config = { 0, 0, F_CPU_1024, OVERFLOW };
	Timer0_init(&TIMER_Config); /* initialize TIMER0 driver */
	timer_setCallBack(TL_5SEC_Tick_Processing);
}

/**
 * @brief normal mode of the traffic light
 * 
 */
void normal_mode(void) {
	/*
		car's LEDs will be changed every 5 seconds starting from green to yellow to red and then back yellow to green
		the yellow LED will be blinking for 5 seconds before changing to red or green
	*/
	// switch between the 4 states
	switch (normal_mode_state) {
	case 0:
		// turn on green LED
		LED_on(carsPORT, greenLED);
		// turn off yellow LED
		LED_off(carsPORT, yellowLED);
		// turn off red LED
		LED_off(carsPORT, redLED);
		// if 5 sec passed
		if (g_flag_5sec){
			//reset flag
			g_flag_5sec = 0;
			// change state
			normal_mode_state = 1;
			// yellow LED will be on
			LED_on(carsPORT, yellowLED);
		}
		break;
	case 1:
		// turn off green LED
		LED_off(carsPORT, greenLED);
		// toggle yellow LED every 2 sec
		if (g_flag_1sec) {
			//reset flag
			g_flag_1sec = 0;
			// toggle yellow LED
			LED_toggle(carsPORT, yellowLED);
		}
		// turn off red LED
		LED_off(carsPORT, redLED);
		// if 5 sec passed
		if (g_flag_5sec){
			//reset flag
			g_flag_5sec = 0;
			// change state
			normal_mode_state = 2;
		}

		break;
	case 2:
		// turn off green LED
		LED_off(carsPORT, greenLED);
		// turn off yellow LED
		LED_off(carsPORT, yellowLED);
		// turn on red LED
		LED_on(carsPORT, redLED);
		// if 5 sec passed
		if (g_flag_5sec){
			//reset flag
			g_flag_5sec = 0;
			// change state
			normal_mode_state = 3;
		}
		break;
	case 3:
		// turn off green LED
		LED_off(carsPORT, greenLED);
		// toggle yellow LED every 2 sec
		if (g_flag_1sec) {
			//reset flag
			g_flag_1sec = 0;
			// toggle yellow LED
			LED_toggle(carsPORT, yellowLED);
		}
		// turn off red LED
		LED_off(carsPORT, redLED);
		// if 5 sec passed
		if (g_flag_5sec){
			//reset flag
			g_flag_5sec = 0;
			// change state
			normal_mode_state = 0;
		}
		break;

	}
}

/**
 * @brief pedestrian mode of the traffic light
 * 
 */
void pedestrian_mode(void)
{
	// if the cars' LED is RED set the pedestrian's LED to GREEN for 5 seconds
	// read the cars' RED LED state
	if (normal_mode_state == 2) {
		switch (pedestrian_mode_state) {
		case 0:
			// turn on green LED
			LED_on(pedestriansPORT, greenLED);
			// turn off red LED
			LED_off(pedestriansPORT, redLED);
			// if 5 sec passed
			if (g_flag_5sec) {
				//reset flag
				g_flag_5sec = 0;
				// turn off pedestrian's green LED
				LED_off(pedestriansPORT, greenLED);
				// turn on pedestrian's red LED
				LED_on(pedestriansPORT, yellowLED);
				// turn on cars' yellow LED
				LED_on(carsPORT, yellowLED);
				// change state
				pedestrian_mode_state = 1;
			}
			break;
		case 1:
			// toggle yellow LEDs every 2 sec
			if (g_flag_1sec) {
				//reset flag
				g_flag_1sec = 0;
				// toggle pedestrian's yellow LED
				LED_toggle(pedestriansPORT, yellowLED);
				// toggle cars' yellow LED
				LED_toggle(carsPORT, yellowLED);
			}
			// if 5 sec passed
			if (g_flag_5sec) {
				//reset flag
				g_flag_5sec = 0;
				// turn off pedestrian's yellow LED
				LED_off(pedestriansPORT, yellowLED);
				// turn off cars' yellow LED
				LED_off(carsPORT, yellowLED);
				// turn on pedestrian's red LED
				LED_on(pedestriansPORT, redLED);
				// turn on cars' green LED
				LED_on(carsPORT, greenLED);
				// change pedestrian's state
				pedestrian_mode_state = 0;
				// change cars' state
				normal_mode_state = 0;
				// change mode
				g_Mode_Flag = 0;
			}
			break;
		}
	}
	else {
		// set both cars' and pedestrian's yellow LED to ON for 5 seconds and toggle them every 2 seconds
		// if 2 sec passed
		switch (pedestrian_mode_state) {
			case 0:
				// turn off red & green cars' LEDs
				LED_off(carsPORT, greenLED);
				LED_off(carsPORT, redLED);
				// turn off red pedestrian's LED
				//LED_off(pedestriansPORT, redLED);

				// toggle cars' yellow LED every 2 sec
				if (g_flag_1sec) {
					//reset flag
					g_flag_1sec = 0;
					// toggle cars' yellow LED
					LED_toggle(carsPORT, yellowLED);
					// toggle pedestrian's yellow LED
					LED_toggle(pedestriansPORT, yellowLED);
				}
				// if 5 sec passed
				if (g_flag_5sec) {
					//reset flag
					g_flag_5sec = 0;
					// turn off cars' yellow LED
					LED_off(carsPORT, yellowLED);
					// turn off pedestrian's yellow LED
					LED_off(pedestriansPORT, yellowLED);
					// turn off red pedestrian's LED
					LED_off(pedestriansPORT, redLED);

					// change state
					pedestrian_mode_state = 1;
				}
				break;
			case 1:
				// set cars' red LED to ON
				LED_on(carsPORT, redLED);
				// set pedestrian's green LED to ON
				LED_on(pedestriansPORT, greenLED);
				// if 5 sec passed
				if (g_flag_5sec) {
					//reset flag
					g_flag_5sec = 0;
					// turn off cars' red LED
					LED_off(carsPORT, redLED);
					// turn off pedestrian's green LED
					//LED_off(pedestriansPORT, greenLED);
					// turn on yellow LEDs
					LED_on(carsPORT, yellowLED);
					LED_on(pedestriansPORT, yellowLED);
					// change state
					pedestrian_mode_state = 2;
					
				}
				break;
			case 2:
				// blink yellow LEDs every 2 sec
				if (g_flag_1sec) {
					//reset flag
					g_flag_1sec = 0;
					// toggle cars' yellow LED
					LED_toggle(carsPORT, yellowLED);
					// toggle pedestrian's yellow LED
					LED_toggle(pedestriansPORT, yellowLED);
				}
				// if 5 sec passed
				if (g_flag_5sec) {
					//reset flag
					g_flag_5sec = 0;
					// turn off cars' yellow LED
					LED_off(carsPORT, yellowLED);
					// turn off pedestrian's yellow LED
					LED_off(pedestriansPORT, yellowLED);
					LED_off(pedestriansPORT, greenLED);
					// turn on green LEDs
					LED_on(carsPORT, greenLED);
					LED_on(pedestriansPORT, redLED);
					// change pedestrian's state
					pedestrian_mode_state = 0;
					// change cars' state
					normal_mode_state = 0;
					// change mode to normal mode
					g_Mode_Flag = 0;
				}
				break;
		}
	}
}

void App_init(void){
	SREG |= (1 << 7);	// Enable interrupts by setting I-bit

	// CARS
	LED_init(carsPORT, greenLED);
	LED_init(carsPORT, yellowLED);
	LED_init(carsPORT, redLED);

	// init cars LEDs
	LED_off(carsPORT, greenLED);
	LED_off(carsPORT, yellowLED);
	LED_off(carsPORT, redLED);

	// Pedestrians
	LED_init(pedestriansPORT, greenLED);
	LED_init(pedestriansPORT, yellowLED);
	LED_init(pedestriansPORT, redLED);
	
	//init pedestrians LEDs
	LED_on(pedestriansPORT, redLED);

	//init button 
	BUTTON_init(BUTTON_PORT, BUTTON_PIN);

	/*Notes for Interrupts*/
	/*
	1. you have to set I-Bit in SREG 
	2. Set the Module Interrupt Enable (External Interrupts) INT0 which is bit 6 in GICR
	3. using MCUCR Register (MCU Control Register) you have to choose whether you will detect Rising or Falling edge for INT0 Control by setting or Clearing the ISC00(bit 0) and ISC01(bit 1) bits in MCUCR
	4. ISC00 = 0, ISC01 = 1 --> means the falling edge of INT0 generates an interrupt request
	5. ISC00 = 1, ISC01 = 1 --> means the rising edge of INT0 generates an interrupt request
	6. GIFR (general interrupt flag register) you have to clear this flag once the ISR ends in order to be able to accept any other interrupts but thanks god it will be cleared automatically in AVR, Also you have to know that this flag is a result of detecting the falling or the rising edge
	7. we include the #include<avr/interrupt.h> library in order to understand the ISR definitions
	8. Write ISR for a specific interrupt in this way
		ISR(INTERRUPT_NAME_vect)
		{
			//ISR Code
		}
	*/
	SET_BIT(GICR ,PIN6_ID);
	SET_BIT(MCUCR,PIN0_ID);
	SET_BIT(MCUCR,PIN1_ID);

	TL_5SEC();
}
void App_start(void){
	while (1) {
		if(g_Mode_Flag == 1) // if button is pressed
		{
			pedestrian_mode(); // operating mode 2 (pedestrian mode)
			}else{
			normal_mode(); // operating mode 1 (normal mode)
		}
	}
}