/*
 * bit_manipulation.h
 *
 * Created: 8/8/2022 5:21:31 PM
 *  Author: Omar Khaled
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

//set bit macro
#define SET_BIT(Register, bitNumber) (Register |= (1<<bitNumber))

//clear bit macro
#define CLEAR_BIT(Register, bitNumber) (Register &=~ (1<<bitNumber))

//toggle bit macro
#define TOGGLE_BIT(Register, bitNumber) (Register ^= (1<<bitNumber))


#endif /* BIT_MANIPULATION_H_ */