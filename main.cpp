/* S.O.S Example
*   This example displays the message "SOS" in morse code using the functionality of the external
*   LED connected to pin PC_3
*
*   1 time unit is 150ms
*   A dot is 1 time unit
*   A dash is 3 time units
*   Space between parts of a letter is 1 unit
*   Space between letters is 3 units
*   Space between words is 7 units
*
*   Author: Dr Craig A. Evans, University of Leeds
*   Editors: Andrew Knowles, Dr James Chandler 2021
*/
 
#include "mbed.h"
 
DigitalOut LED(PC_3); // define output bus pin 
// declare function prototypes
void init_leds();
void dot();
void dash();
void morse_s();
void morse_o();
void sos();
 
int main(){
    init_leds();
 
    while(1) {
        sos();
        ThisThread::sleep_for(1050ms);  // space between words is 7 units (7*150 ms)
    }
}


void init_leds(){
    LED.write(0); //initialise LED to be off
}
 
void dot(){                           // dot is 1 unit (150 ms)
    LED.write(1);                     // turn LED on
    ThisThread::sleep_for(150ms);
    LED.write(0);                     // turn LED off
}
 
void dash() {                        // dash is 3 units (150 ms)
   LED.write(1);                     // turn LED on
    ThisThread::sleep_for(450ms);
    LED.write(0);                    // turn LED off
}

// the morse equivalent of the letter 'S' is three quick flashes or dots ...
void morse_s() {
    dot();
    ThisThread::sleep_for(150ms);
    dot();
    ThisThread::sleep_for(150ms);
    dot(); 
}
 
// the morse equivalent of the letter 'O' is three long flashes or dashes ---  
void morse_o() {
    dash();
    ThisThread::sleep_for(150ms);
    dash();
    ThisThread::sleep_for(150ms);
    dash(); 
}

// the morse equivalent of 'SOS' is three short flashes followed by three long flashes followed by three more short flashes ... --- ...
void sos() { 
    morse_s();
    ThisThread::sleep_for(450ms);  
    morse_o();
    ThisThread::sleep_for(450ms); 
    morse_s();        
}
