/*
 * led.h
 *
 *  Created on: 2022. 10. 18.
 *      Author: kccistc
 */

#ifndef SRC_HW_LED_H_
#define SRC_HW_LED_H_

#include "xparameters.h"
#include "xgpio.h"
#include "sleep.h"




#define CHANNEL_1 1
#define OUTPUT 0x00
#define INPUT  0xff

#define led_0	0
#define led_1	1
#define led_2	2


#include "xparameters.h"
#include "xgpio.h"
#include "sleep.h"

XGpio GPIO_LED;

typedef struct _LedInst {
	int ledState;
	int ledNum;

}ledInst;

void led_MakeInst(ledInst *led ,int ledNum);
void led_Init();
void led_on_off(ledInst *led);
void led_left_shift(ledInst *led);
void led_right_shift(ledInst *led);


#endif /* SRC_HW_LED_H_ */
