#include <msp430.h> 
#include "MoveBot.h"
/*
 * main.c
 */
int main(void) {

	WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

	initMotors();
	
	while(1)
	{
		TurnLeft();
		ShortDelay();
		StopBot();
		Delay();
		TurnRight();
		ShortDelay();
		StopBot();
		Delay();
		MoveForward();
		Delay();
		StopBot();
		Delay();
		MoveBack();
		Delay();
		StopBot();
		Delay();
		TurnRight();
		Delay();
		StopBot();
		Delay();
		TurnLeft();
		Delay();
		StopBot();
		Delay();
		Delay();
		Delay();

//		StopBot();
//		Delay();
//		MoveForward();
//		Delay();
//		StopBot();
//		Delay();
//		Delay();
//		MoveBack();
//		Delay();
//		StopBot();
//		Delay();\

//		TurnRight();
//		ShortDelay();
//		StopBot();
//		Delay();
//		Delay();
//		TurnRight();
//		Delay();
//		StopBot();
//		Delay();
//		Delay();

	}

}
