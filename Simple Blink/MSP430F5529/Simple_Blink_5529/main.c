//Simple Blink 5529
//Kind of Author, not super really: Ben Jukus
/*******************************************************************************
 *
 *                       MSP430 CODE EXAMPLE DISCLAIMER
 *
 * MSP430 code examples are self-contained low-level programs that typically
 * demonstrate a single peripheral function or device feature in a highly
 * concise manner. For this the code may rely on the device's power-on default
 * register values and settings such as the clock configuration and care must
 * be taken when combining code from several examples to avoid potential side
 * effects. Also see www.ti.com/grace for a GUI- and www.ti.com/msp430ware
 * for an API functional library-approach to peripheral configuration.
 *
 * --/COPYRIGHT--*/
//******************************************************************************
//   MSP430F552x Demo - Software Toggle P1.0
//
//   Description: Toggle P1.0 by xor'ing P1.0 inside of a software loop.
//   ACLK = 32.768kHz, MCLK = SMCLK = default DCO~1MHz
//
//                MSP430F552x
//             -----------------
//         /|\|                 |
//          | |                 |
//          --|RST              |
//            |                 |
//            |             P1.0|-->LED
//
//   Bhargavi Nisarga
//   Texas Instruments Inc.
//   April 2009
//   Built with CCSv4 and IAR Embedded Workbench Version: 4.21
//******************************************************************************/
#include <msp430.h>

int main(void)
{
  volatile unsigned int i; //delay variable, increments in while loop until if statement is fulfilled and then resets.
  WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT

  P4DIR |= BIT7;                            // P4.7 set as output, green LED
  P4OUT &= ~BIT7;                           //starts off
  while(1)                                  // continuous loop
  {
    if (i>=5000) //delay rate, it take 5000 cycles until the LED switches on and off
    {
    P4OUT ^= BIT7; //changes LED on and off
    i=0; //resets delay var
    }
                    // Delay
    i++;//increments delay var

  }
}
