/*
 * Keypad.h
 *
 * Created: 10/06/2021 00:08:50
 *  Author: Ahmed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"
#include "Keypad_CFG.h"

void KeyPad_Init(void);

uint8_t KeyPad_GetValue(void);





#endif /* KEYPAD_H_ */