/*
 * led.c
 *
 *  Created on: 2022. 10. 18.
 *      Author: kccistc
 */

#include "led.h"

void led_Init()
{
	XGpio_Initialize(&GPIO_LED, XPAR_AXI_GPIO_0_DEVICE_ID);
	    XGpio_SetDataDirection(&GPIO_LED, CHANNEL_1, 0x00);

}

void led_MakeInst(ledInst *led ,int ledNum)
{
	led -> ledState = 0x00;
	led-> ledNum = ledNum;
}

void led_on_off(ledInst *led)
{
	led->ledState = ~(led->ledState);
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1,led->ledState);

}

void led_left_shift(ledInst *led)
{
	int mask = 0x01;
	for(int i =0;i<8;i++)
	{
		led->ledNum = mask;
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1,led->ledNum);
		mask = mask << i;

		led->ledNum = mask;
		usleep(200000);
	}
	led->ledNum = 0x00;

}



void led_right_shift(ledInst *led)
{
	int mask = 0b10000000;
	for(int i=0;i<8;i++)
	{
		led->ledNum = mask;
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1,led->ledNum);
		mask = mask >> i;

		led -> ledNum = mask;
		usleep(200000);
	}
	led->ledNum = 0x00;
}


