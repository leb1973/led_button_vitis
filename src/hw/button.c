/*
 * button.c
 *
 *  Created on: 2022. 10. 18.
 *      Author: kccistc
 */

#include "button.h"


//(1<<BUTTON_0);
//static int prevState0 = RELEASED;



void Button_Init()
{
	 XGpio_Initialize(&GPIO_BUTTON, XPAR_AXI_GPIO_1_DEVICE_ID);
	    XGpio_SetDataDirection(&GPIO_BUTTON, CHANNEL_1, 0xff);		// 비트가 1이면 input, 0이면 output
}


void Button_MakeInst(buttonInst *button, int buttonNum)
{
	button->prevState = RELEASED;
	button->buttonNum = buttonNum;
 }

int Button_GetState(buttonInst *button)
{
//	static int prevState0 = RELEASED;
	int curState = XGpio_DiscreteRead(&GPIO_BUTTON, CHANNEL_1) & (1<<button->buttonNum);

	if((curState != RELEASED) && (button->prevState == RELEASED)) {
		usleep(20000);
		button->prevState = PUSHED;
		return FALSE;
	}
	else if ((curState == RELEASED) && (button->prevState != RELEASED)) {
		usleep(20000);
		button->prevState = RELEASED;
		return TRUE;
	}
	return FALSE;
}


