#include <msp430.h>
//uses the 5529 but could be modified for each board.
//When button1 is pressed the LEDs blink SOS in Morse code
//Fun Fact SOS doesn't stand for anything it's just easy to recognize and tap out. ...---...
//Author: Ben Jukus
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
    volatile unsigned int i;
    while(1)
    {
        switch((P1IN&BIT1)) //| (P2IN&BIT1))
        {
        case 0: //when button is pressed

            P1OUT &= ~BIT0; //starts off

         //S
            for(i=70000;i>0;i--);
            P4OUT ^= BIT7;
            for(i=10000;i>0;i--);
               P4OUT ^= BIT7;
               for(i=10000;i>0;i--);
               P4OUT ^= BIT7;
               for(i=10000;i>0;i--);
               P4OUT ^= BIT7;
               for(i=10000;i>0;i--);
               P4OUT ^= BIT7;
               for(i=10000;i>0;i--);
               P4OUT ^= BIT7;
               for(i=10000;i>0;i--);
               P4OUT &= ~BIT7;
               for(i=30000;i>0;i--);
//O
               P1OUT ^= BIT0;
               for(i=30000;i>0;i--);
               P1OUT ^= BIT0;
               for(i=30000;i>0;i--);
               P1OUT ^= BIT0;
               for(i=3000;i>0;i--);
               P1OUT ^= BIT0;
               for(i=30000;i>0;i--);
               P1OUT ^= BIT0;
               for(i=30000;i>0;i--);
               P1OUT ^= BIT0;
               for(i=30000;i>0;i--);
               P1OUT &= ~BIT0;
               for(i=30000;i>0;i--);
//S
               P4OUT ^= BIT7;
               for(i=10000;i>0;i--);
               P4OUT ^= BIT7;
               for(i=10000;i>0;i--);
               P4OUT ^= BIT7;
               for(i=10000;i>0;i--);
               P4OUT ^= BIT7;
               for(i=10000;i>0;i--);
               P4OUT ^= BIT7;
               for(i=10000;i>0;i--);
               P4OUT ^= BIT7;
               for(i=10000;i>0;i--);
               P4OUT &= ~BIT7;
               for(i=70000;i>0;i--);
            break;
        case 2://when button is not pressed
            //when and'ed together case = 2 since BIT1 = 0x02
            P1OUT ^= BIT0; //sets red led to blink
            P4OUT &= ~BIT7; //sets green led to stop blinking
            for(i=50000;i>0;i--); //delay to blink
           break;

        default : //error checking
            P4OUT=BIT7; //sets green led to stay on
            P1OUT=BIT0; //sets red led to stay on
            break;

     
        }
    }

}
