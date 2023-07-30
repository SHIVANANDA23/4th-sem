/*
Interfacing HC-SR04 Ultrasonic Distance sensor with LPC2148 - Example Source Code for KEIL ARM.
www.tmisystems.in
*/

#include <lpc214x.h>
#include <stdio.h> 
#include "lib_funcs.h"

#define TRIG (1<<5) //P0.5
#define ECHO (1<<4) //P0.4

int main(void)
{
	initClocks(); //Set PCLK = CCLK = 60Mhz - used by: UART, Timer and ADC
	initUART0();  //Initialize UART0 for retargeted printf()
	initTimer0(); //Init Timer for delay functions
	int echoTime=0;
	float distance=0;

	IO0DIR |= TRIG;    //Set P0.2(TRIG) as output
	IO0DIR &= ~(ECHO); //Set P0.3(ECHO) as input (explicitly)
	IO0CLR |= TRIG;    //Set P0.2 LOW initially

	printf("Ultrasonic sensor\n");
	delayMS(2000);//Wait for GPIO to be stable

	while(1)
	{
		//Output 10us HIGH on TRIG pin
		IO0SET |= TRIG;
		delayUS(10);
		IO0CLR |= TRIG;

		while(!(IO0PIN & ECHO)); //Wait for a HIGH on ECHO pin
		startTimer0(); //Start counting
		while(IO0PIN & ECHO); //Wait for a LOW on ECHO pin
		echoTime = stopTimer0(); //Stop counting and save value(us) in echoTime

		distance = (0.0343 * echoTime)/2; //Find the distance

		printf("Distance = %0.2fcm\n",distance);
		
		delayMS(1000); //wait 1 second for next update
	}
	
	//return 0; //This won't execute normally
}
