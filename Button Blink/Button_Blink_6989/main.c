//Button Blink 6989
//Pretty Much the Author: Ben Jukus
#include <msp430.h> 
/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //Button I am using is port 5.6
    //LED I am using is port 1.0
    //P1SEL &= ~BIT1; //Set the button pin to I/O
    P1DIR &= ~BIT2; //Sets button2, pin1.2 as an input
    P1REN |=  BIT2; //Enables the pullup/down resistor
    P1OUT |=  BIT2; //Set the resistor to be a pullup resistor

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= BIT0; //sets the direction of pin 1 to output
    P1OUT &= ~BIT0; //sets output high
    P9DIR |= BIT7; //sets the direction of pin 1 to output
    P9OUT &= ~BIT7; //sets output high
    while(1)
    {
        switch(P1IN&BIT2)//checks when P1IN
        {
        case 0: //when button is not pressed
            //when
           P9OUT ^= BIT7;
           P1OUT &= ~BIT0;
            __delay_cycles(100000);
            break;
        case 4://when button is pressed
            //when and'ed together = 2 bc BIT1 = 2
            P1OUT ^= BIT0;
            P9OUT &= ~BIT7;
           __delay_cycles(100000);
           break;
        default : //error checking
            P9OUT=BIT7;
            P1OUT=BIT0;
            break;
        }
    }

}
