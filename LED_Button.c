// Create a program that allows you to turn on/off a LED using a button

#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

#define LedPin 0
#define ButtonPin 1

int main(void) {
    setenv("WIRINGPI_GPIOMEM", "1", 1);
    wiringPiSetup();

    pinMode(LedPin, OUTPUT);
    pinMode(ButtonPin, INPUT);

    pullUpDnControl(ButtonPin, PUD_UP); // pull up to 3.3V, make GPIO1 a stable level

    while (1) {
        digitalWrite(LedPin, HIGH);
        if (digitalRead(ButtonPin) == 0) { // indicate that button has pressed down
            digitalWrite(LedPin, LOW);    // led on
        }
    }

    return 0;
}
