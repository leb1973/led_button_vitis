/*
 * button.h
 *
 *  Created on: 2022. 10. 18.
 *      Author: kccistc
 */

#ifndef SRC_HW_BUTTON_H_
#define SRC_HW_BUTTON_H_

//#include "platform.h"
#include "xparameters.h"
#include "xgpio.h"
#include "sleep.h"



#define RELEASED	0
#define PUSHED		1
#define BUTTON_0	0
#define BUTTON_1	1
#define BUTTON_2	2

#define CHANNEL_1 1
#define OUTPUT 0x00
#define INPUT  0xff

XGpio GPIO_BUTTON;


typedef struct _buttonInst {
	int prevState;
	int buttonNum;
}buttonInst;

void Button_MakeInst(buttonInst *button, int buttonNum);
void Button_Init();
int Button_GetState(buttonInst *button);

#endif /* SRC_HW_BUTTON_H_ */
