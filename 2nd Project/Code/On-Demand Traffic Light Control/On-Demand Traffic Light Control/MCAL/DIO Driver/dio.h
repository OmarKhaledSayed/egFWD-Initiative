/*
 * dio.h
 *
 * Created: 7/25/2022 9:30:04 AM
 *  Author: o.khaled
 */ 


#ifndef DIO_H_
#define DIO_H_
/*----------------------contents-------------------------------*/
/*
1- all internal driver typedefs
2- all driver macros
3- all driver function prototypes
*/
/*-------------------------------------------------------------*/

//include Utilities header files
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/StdTypes.h"

//all PORTS macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D' 

//all PINS macros
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5 
#define PIN6 6
#define PIN7 7

//Direction defines
#define IN 0
#define OUT 1

//Value defines
#define LOW 0
#define HIGH 1

//enum for error handling
typedef enum 
{
	DIO_OK, DIO_init_ERROR, DIO_write_ERROR, DIO_read_ERROR, DIO_toggle_ERROR
}EN_DIOError_t;

//all driver function prototypes
EN_DIOError_t DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction); //Initialize dio direction
EN_DIOError_t DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value); //write data to dio pins
EN_DIOError_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber); //toggle dio
EN_DIOError_t DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value); //read dio
#endif /* DIO_H_ */