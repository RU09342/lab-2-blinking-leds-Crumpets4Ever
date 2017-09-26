//Button Blink 5994
//Pretty Much the Author: Ben Jukus
#include <msp430.h> 
/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	//Button I am using is port 5.6
	//LED I am using is port 1.0
	P5DIR &= ~BIT6; //Set the pin direction to I/O
	P5REN |= BIT6; //Enables the pullup/down resistor
	P5OUT |= BIT6; //Set the resistor to be a pullup resistor
	
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= BIT1; //sets the direction of pin 1 to output
    P1OUT &= ~BIT1; //sets output high
    P1DIR |= BIT0; //sets the direction of pin 1 to output
    P1OUT &= ~BIT0; //sets output high
    while(1)
    {
        if(P5IN==BIT6)
        {
            P1OUT ^= BIT1;
            P1OUT &= ~BIT0;
            __delay_cycles(100000);
        }
        if(P5IN!=BIT6)
        {
            P1OUT ^= BIT0;
            P1OUT &= ~BIT1;
            __delay_cycles(100000);
        }

    }

}
