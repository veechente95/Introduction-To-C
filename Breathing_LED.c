// Create a "Breathing LED" program that emulates a light gradually turning on and off

#include <wiringPi.h>
#include <stdio.h>

#define LedPin 1

int main(void) {
    int i;
    wiringPiSetup();  // Initialize the WiringPi library

    pinMode(LedPin, PWM_OUTPUT);   // Set LedPin as PWM output mode

    while (1) { 
        
        // Increasing brightness loop
        for (i = 0; i < 1024; i++) {
            pwmWrite(LedPin, i);  // Set the PWM value to control LED brightness
            delay(2);  // Pause to control the fading speed
        }

        delay(1000);  // Pause for a longer duration between the two breathing phases

        // Decreasing brightness loop
        for (i = 1023; i >= 0; i--) {
            pwmWrite(LedPin, i);
            delay(2);
        }
    }

    return 0;  // Return 0 to indicate successful program execution
}
