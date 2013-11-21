#include <msp430.h> 
#include "MoveBot.h"
/*
 * main.c
 */
int main(void) {

	
	while(1)
	{
		StopBot();
		Delay();
		MoveForward();
		Delay();
		StopBot();
		Delay();
		MoveBackward();
		Delay();
		StopBot();
		Delay();

	}

}
