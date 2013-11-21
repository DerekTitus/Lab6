/*
 * MoveBot.c
 *
 *  Created on: Nov 18, 2013
 *      Author: C15Derek.Titus
 */

#include "MoveBot.h"
#include <msp430.h>

void initMotors()
{

    P1DIR |= BIT1;				//TA0.0 on P1.1
    P1SEL |= BIT1;              //TA0.0 on P1.1

    P1DIR |= BIT2;                // TA0CCR1 on P1.2
    P1SEL |= BIT2;                // TA0CCR1 on P1.2

    TACTL &= ~(MC1|MC0);            // stop timer A0

    TACTL |= TACLR;                // clear timer A0

    TACTL |= TASSEL1;           // configure for SMCLK

    TACCR0 = 100;                // set signal period to 100 clock cycles (~100 microseconds)
    TACCR1 = 50;                // set duty cycle to 25/100 (25%)

    TACCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
    TACCTL0 |= OUTMOD_5;

    TACTL |= MC0; //count up


    P2DIR |= BIT0;				//TA0.0 on P1.1
    P2SEL |= BIT0;              //TA0.0 on P1.1

    P2DIR |= BIT1;                // TA0CCR1 on P1.2
    P2SEL |= BIT1;                // TA0CCR1 on P1.2

    TA1CTL &= ~(MC1|MC0);            // stop timer A0

    TA1CTL |= TACLR;                // clear timer A0

    TA1CTL |= TASSEL1;           // configure for SMCLK

    TA1CCR0 = 100;                // set signal period to 100 clock cycles (~100 microseconds)
    TA1CCR1 = 50;                // set duty cycle to 25/100 (25%)

    TA1CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
    TA1CCTL0 |= OUTMOD_5;

    TA1CTL |= MC0; //count up
    TACTL |= MC0;                // count up

}


void RightMotorForward()
    {
		TA1CCTL1 &= ~OUTMOD0;
		TA1CCTL1 |= OUTMOD_4;        // set TACCTL1 to Reset mode
		TA1CCTL0 &= ~OUTMOD0;
		TA1CCTL0 |= OUTMOD_5;
	}

void	RightMotorBackward(){
		TA1CCTL1 &= ~OUTMOD0;
		TA1CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
	    TA1CCTL0 &= ~OUTMOD0;
		TA1CCTL0 |= OUTMOD_4;
	}

void	RightMotorStop(){
		TA1CCTL1 &= ~OUTMOD0;
				TA1CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
			    TA1CCTL0 &= ~OUTMOD0;
				TA1CCTL0 |= OUTMOD_5;
	}

void	LeftMotorForward(){
		TACCTL1 &= ~OUTMOD0;
		TACCTL1 |= OUTMOD_4;        // set TACCTL1 to Reset / Set mode
		TACCTL0 &= ~OUTMOD0;
		TACCTL0 |= OUTMOD_5;
	}

void	LeftMotorBackward(){
		TACCTL1 &= ~OUTMOD0;
		TACCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
		TACCTL0 &= ~OUTMOD0;
		TACCTL0 |= OUTMOD_4;
	}

void	LeftMotorStop(){
		TACCTL1 &= ~OUTMOD0;
		TACCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
		TACCTL0 &= ~OUTMOD0;
		TACCTL0 |= OUTMOD_5;
	}

void	MoveForward(){
		RightMotorForward();
		LeftMotorForward();
	}

void	MoveBack(){
		RightMotorBackward();
		LeftMotorBackward();
	}

void	TurnRight(){
		RightMotorBackward();
		LeftMotorForward();
	}

void	TurnLeft(){
		RightMotorForward();
		LeftMotorBackward();
	}

void	StopBot(){
		RightMotorStop();
		LeftMotorStop();
		}

void    Delay(){
		__delay_cycles(100000);
}

