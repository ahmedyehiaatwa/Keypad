/*
 * Keypad_CFG.h
 *
 *  Author: Ahmed
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#include "DIO.h"

#define COL_INIT   0
#define COL_FINAL  3

#define ROW_INIT   0
#define ROW_FINAL  3

#define KEYPAD_COL_PORT  DIO_PORTC
#define KEYPAD_ROW_PORT  DIO_PORTC

#define KEYPAD_COL0      DIO_PIN5
#define KEYPAD_COL1      DIO_PIN6
#define KEYPAD_COL2      DIO_PIN7

#define KEYPAD_ROW0      DIO_PIN2
#define KEYPAD_ROW1      DIO_PIN3
#define KEYPAD_ROW2      DIO_PIN4





#endif /* KEYPAD_CFG_H_ */