#include <msp430.h> 
//This uses the 5529 but could be easily modified for the other dev boards that have 2 buttons.

//Author: Ben Jukus
/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
       //Button I am using is port 1.1 and 2.1
       //LEDs I am using are ports 1.0 and 4.7
       //P1SEL &= ~BIT1; //Set the button pin to I/O
       P1DIR &= ~BIT1; //Sets button2, pin1.2 as an input
       P1REN |=  BIT1; //Enables the pullup/down resistor
       P1OUT |=  BIT1; //Set the resistor to be a pullup resistor
       P2DIR &= ~BIT1; //Sets button2, pin1.2 as an input
       P2REN |=  BIT1; //Enables the pullup/down resistor
       P2OUT |=  BIT1; //Set the resistor to be a pullup resistor

       //PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                               // to activate previously configured port settings
       P1DIR |= BIT0; //sets the direction of pin 1 to output
       P1OUT &= ~BIT0; //sets output high
       P4DIR |= BIT7; //sets the direction of pin 1 to output
       P4OUT &= ~BIT7; //sets output high

       int count = 0; // button counting variable

       volatile unsigned int i; // delay decrement variable.

       while(1)
          {
           if((P1IN&BIT1)==0)//button 1 counts
               {
                   count++;
               }
           if((P2IN&BIT1)==0)//button 2 is a reset
               {
               count=0;
               }
              switch(count) //Morse code for each number.
              {
              case 0:
                  P4OUT ^= BIT7;        //-
                  for(i=210000;i>0;i--);
                  P4OUT ^= BIT7;
                  for(i=30000;i>0;i--);
                  P4OUT ^= BIT7;        //-
                  for(i=210000;i>0;i--);
                  P4OUT ^= BIT7;
                  for(i=30000;i>0;i--);
                  P4OUT ^= BIT7;        //-
                  for(i=210000;i>0;i--);
                  P4OUT ^= BIT7;
                  for(i=30000;i>0;i--);
                  P4OUT ^= BIT7;        //-
                  for(i=210000;i>0;i--);
                  P4OUT ^= BIT7;
                  for(i=30000;i>0;i--);
                  P4OUT ^= BIT7;        //-
                  for(i=210000;i>0;i--);
                  P4OUT ^= BIT7;
                  for(i=30000;i>0;i--);
                  P4OUT &= ~BIT7;       //break
                  __delay_cycles(210000);
               break;
              case 1:
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT &= ~BIT7;       //break
              __delay_cycles(210000);
            break;
              case 2:
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT &= ~BIT7;       //break
              __delay_cycles(210000);
            break;
              case 3:
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT &= ~BIT7;       //break
              __delay_cycles(210000);
            break;
              case 4:
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT &= ~BIT7;       //break
              __delay_cycles(210000);
            break;
              case 5:
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT &= ~BIT0;       //break
              __delay_cycles(210000);
            break;
              case 6:
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT &= ~BIT0;       //break
              __delay_cycles(210000);
            break;
              case 7:
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P1OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT &= ~BIT0;       //break
              __delay_cycles(210000);
            break;
              case 8:
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT ^= BIT7;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT &= ~BIT0;       //break
              __delay_cycles(210000);
            break;
              case 9:
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT ^= BIT7;        //-
              for(i=90000;i>0;i--);
              P4OUT ^= BIT7;
              for(i=30000;i>0;i--);
              P4OUT ^= BIT7;        //.
              for(i=30000;i>0;i--);
              P1OUT ^= BIT0;
              for(i=30000;i>0;i--);
              P1OUT &= ~BIT0;       //break
              __delay_cycles(210000);
            break;
             default : //error checking
                  P4OUT=BIT7; //sets green led to stay on
                  P1OUT=BIT0; //sets red led to stay on
                  break;
}
}
}
