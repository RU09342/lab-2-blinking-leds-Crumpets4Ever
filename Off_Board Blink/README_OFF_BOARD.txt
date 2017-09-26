README_OFF_BOARD
Author: Ben Jukus
The code for this project was taken from the multiple blink for 2553, with 1-2 pins added in order to blink more LEDs. 
In order to hook msp into the board the chip was taken from the top on the board, carefully noting which pins lead where (as labelled on the top of the dev board).
For programming on the dev board the code and chip can be debugged on the dev board and then placed on the a breadboard. To supply power the dev board was plugged and a cable was run from port 1 (VCC) to the first pin on the left side of the chip and the ground is connected to GND pin, the first pin on the right side. The RST pin (5th from the top on the right side) must be connected to VCC to stay high, "active low", otherwise the reset will continue to reset the chip. 
The LEDs are connected to their respective pins from pin 1.0, 1.1, and 1.2 (as labelled on board). 

Off-board programming was found as a solution to an inconvience. Rather than removing the board everytime the code was edited cables were run from the dev board to the chip. These cables connected pins VCC, RST, TEST, and GND. This enabled data flow and making it appear like the chip was attached to the board for debugging purposes. 

The code changed very little from Multiple Blink with a few issues arising from RST not being tied to VCC. After that issue was resolved (thanks to Russell) the only further issues were user errors, namely incorrectly inputting LEDs. 

