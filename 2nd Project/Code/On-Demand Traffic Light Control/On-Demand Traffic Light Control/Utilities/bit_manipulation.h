/*
 * bit_manipulation.h
 *
 * Created: 8/8/2022 5:21:31 PM
 *  Author: Omar Khaled
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

/*Set bit macro*/
#define SET_BIT(Register, bitNumber) (Register |= (1<<bitNumber))

/*Clear bit macro*/
#define CLEAR_BIT(Register, bitNumber) (Register &=~ (1<<bitNumber))

/*Toggle bit macro*/
#define TOGGLE_BIT(Register, bitNumber) (Register ^= (1<<bitNumber))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )




#endif /* BIT_MANIPULATION_H_ */