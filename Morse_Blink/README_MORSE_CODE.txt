README_MORSE_CODE
Author: Ben Jukus
So this was a fun little thing. 
SOS_Blink will blink S&S in morse code on the green LED and O on the red led. This just uses simple blink and switches the led. 
MC_Count_Blink makes button 1 the input to count, when button is held down the leds will blink in morse code the number of times the button is held down. This counts up to 9 and then resets to 0. The blinking will also reset if button 2 (pin 1.2) is pressed; button 2 resets the count variable. 

MC_Count_Blink is a modified Button Blink, it uses two switch statements and was built off the Button Blink.  
