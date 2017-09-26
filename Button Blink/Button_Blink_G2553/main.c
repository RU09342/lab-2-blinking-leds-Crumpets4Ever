//Button Blink 2553
//Pretty Much the Author: Ben Jukus
#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //Button I am using is port 1.3
    //LED I am using is port 1.0
    //P1SEL &= ~BIT1; //Set the button pin to I/O
    P1DIR &= ~BIT3; //Sets button1, pin1.3 as an input
    P1REN |=  BIT3; //Enables the pullup/down resistor
    P1OUT |=  BIT3; //Set the resistor to be a pullup resistor


    P1DIR |= BIT0; //sets the direction of pin 1 to output
    P1OUT &= ~BIT0; //sets output high
    P1DIR |= BIT6; //sets the direction of pin 1 to output
    P1OUT &= ~BIT6; //sets output high
    while(1)
    {
        switch(P1IN&BIT3)//checks when P1IN
        {
        case 0: //when button is not pressed
            //when
           P1OUT ^= BIT6;
           P1OUT &= ~BIT0;
            __delay_cycles(100000);
            break;
        case 8://when button is pressed
            //when and'ed together = 2 bc BIT1 = 2
            P1OUT ^= BIT0;
            P1OUT &= ~BIT6;
           __delay_cycles(100000);
           break;
        default : //error checking
            P1OUT=BIT6;
            P1OUT=BIT0;
            break;
        }
    }

}
