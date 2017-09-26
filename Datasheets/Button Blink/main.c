#include <msp430.h>

int main(void)
{
 volatile unsigned int i;
 volatile unsigned int j;
  WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT
  P1SEL &= ~BIT1;
  P1DIR |= ~BIT1; //sets the button to input
  P1REN |= BIT1; // enables a pullup/down resistor
  P1OUT ^= BIT1; //
  while(1)
  {
      if(P1IN&BIT1)// P1in = 1 when button is up. Blink red if button is up
      {
          if(i>5000)
          {
              P1OUT ^= BIT0;
              //P4OUT &= ~BIT7;
              i=0;
          }
      }
      if((P1IN&BIT1)) //P1in = 0 when button is down. Stop blinking red if button is down
      {
          if(i>5000)
          {
              //P4OUT ^= BIT7;
              P1OUT &=~BIT0;
              j=0;
          }
      }
      i++;
      j++;
  }

}
