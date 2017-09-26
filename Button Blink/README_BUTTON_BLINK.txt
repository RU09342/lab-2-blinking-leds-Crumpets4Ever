README_BUTTON_BLINK
First step to button blink was figuring out how the circuit would need to be designed on the board. 
	The main component to figure out was whether a pullup or pulldown resistor would be needed. 
	A pullup resistor was used. So the resistor is enabled (PxREN set to 1) and the output (PxOUT) is set to 1, a pullup resistor. 
After setting the resistor the button was set to be an input and a switch statement was used to figure out if the button was pressed.
	0 if pressed (not blinking the red led) 
	case (the decimal form of whichever bit is on the button's pin) (for 5529 Bit1, case 2), if not pressed (blinking the red led)

The switch statement was adapted to make the green led blink when the red led is not blinking. 
Additionally this code was modified for Morse_Blink for fun. 
