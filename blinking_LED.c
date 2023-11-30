// Create a blinking LED program

#include <wiringPi.h>  // Include the wiringPi library for GPIO access
#include <stdio.h>     // Include the standard input/output library
#define LedPin 0        // Define the GPIO pin number for the LED

int main(void) {
    wiringPiSetup();   // Initialize the wiringPi library for GPIO access

    pinMode(LedPin, OUTPUT);   // Set the LED pin as an output

    while (1) {
        digitalWrite(LedPin, LOW);   // Turn the LED on by setting the GPIO pin to LOW
        printf("LED on...\n");       // Print a message indicating that the LED is on
        delay(500);                  // Pause for 500 milliseconds

        digitalWrite(LedPin, HIGH);  // Turn the LED off by setting the GPIO pin to HIGH
        printf("LED off...\n");      // Print a message indicating that the LED is off
        delay(500);                  // Pause for 500 milliseconds
    }

    return 0;   // Return 0 to indicate successful program execution
}
