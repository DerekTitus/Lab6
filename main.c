#include <msp430.h> 

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    P1DIR |= BIT2;                // TA0CCR1 on P1.2
    P1SEL |= BIT2;                // TA0CCR1 on P1.2

    TACTL &= ~MC1|MC0;            // stop timer A0

    TACTL |= TACLR;                // clear timer A0

    TACTL |= TASSEL1;           // configure for SMCLK

    TACCR0 = 100;                // set signal period to 100 clock cycles (~100 microseconds)
    TACCR1 = 50;                // set duty cycle to 25/100 (25%)

    TACCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode

    TACTL |= MC0;                // count up

	
    moverobot();
	return 0;
}
