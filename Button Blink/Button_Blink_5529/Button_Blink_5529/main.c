//Button Blink 5529
//Pretty Much the Author: Ben Jukus
#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //Button I am using is port 1.1
    //LEDs I am using are ports 1.0 and 4.7
    //P1SEL &= ~BIT1; //Set the button pin to I/O
    P1DIR &= ~BIT1; //Sets button2, pin1.2 as an input
    P1REN |=  BIT1; //Enables the pullup/down resistor
    P1OUT |=  BIT1; //Set the resistor to be a pullup resistor

    //PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= BIT0; //sets the direction of pin 1 to output
    P1OUT &= ~BIT0; //sets output high
    P4DIR |= BIT7; //sets the direction of pin 1 to output
    P4OUT &= ~BIT7; //sets output high
    while(1)
    {
        switch(P1IN&BIT1)
        {
        case 0: //when button is pressed
           P4OUT ^= BIT7; //sets green led to blink
           P1OUT &= ~BIT0; //sets Red led to not blink
            __delay_cycles(100000);//delay
            break;
        case 2://when button is not pressed
            //when and'ed together case = 2 since BIT1 = 2
            P1OUT ^= BIT0; //sets red led to blink
            P4OUT &= ~BIT7; //sets green led to stop blinking
           __delay_cycles(100000); //delay to blink
           break;
        default : //error checking
            P4OUT=BIT7; //sets green led to stay on
            P1OUT=BIT0; //sets red led to stay on
            break;
        }
    }

}
