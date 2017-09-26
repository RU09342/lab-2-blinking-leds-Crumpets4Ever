//Multi Blink 5529
//Kind of Author, a bit more so: Ben Jukus
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
  volatile unsigned int i;
  volatile unsigned int j;
  WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT
  P1DIR |=BIT0;
  P4DIR |= BIT7;                            // P1.0 set as output

  P1OUT &= ~BIT0;
  P4OUT &= ~BIT7;
  while(1)                                  // continuous loop
  {
    if (i>=5000)
    {
    P4OUT ^= BIT7;
    i=0;
    }
    if(j>=2500)
    {
    P1OUT ^= BIT0;                          // XOR P1.0
    j=0;
    }                  // Delay

    i++;
    j++;
  }
}
