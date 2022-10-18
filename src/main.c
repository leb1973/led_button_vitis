

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include "main.h"






int main()
{
	init_platform();

	print("Hello World\n\r");
	print("Successfully ran Hello World application");

	ledInst led0;
	ledInst led1;
	ledInst led2;
	led_Init();
	led_MakeInst(&led0,led_0);
	led_MakeInst(&led1,led_1);
	led_MakeInst(&led2,led_2);


   buttonInst modeButton;
   buttonInst upButton;
   buttonInst downButton;
   Button_Init();
   Button_MakeInst(&modeButton, BUTTON_0);
   Button_MakeInst(&upButton, BUTTON_1);
   Button_MakeInst(&downButton, BUTTON_2);

    while (1)
    {
       if (Button_GetState(&modeButton)) {
    	   print("pushed mode button\n\r");
    	   // led all off <-> led all on
    	   led_on_off(&led0);
       }
       else if (Button_GetState(&upButton)) {
		   print("pushed up button\n\r");
		   // 0.3초 간격으로 led right shift
		   led_left_shift(&led1);
	  }
       else if (Button_GetState(&downButton)) {
	   print("pushed down button\n\r");
	   led_right_shift(&led2);
	   // 0.3 초 간격으로 led left shift
	  }



//       XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1 , 0x01);
//    	*(volatile uint32_t *)0x40000000 = 0x00;


//        *(volatile uint32_t *)0x40000000 = 0xff;

    }


    cleanup_platform();
    return 0;
}
