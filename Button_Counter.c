// Create a program that counts when a button is pressed

#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define ButtonPin 1

int counter = 0;          // Variable to tracks num of button presses
int currentState = 0;     // Variable to store the current state of the button (pressed or not pressed)
int previousState = 0;    // Variable to store the previous state of the button

int main(void) {
    setenv("WIRINGPI_GPIOMEM", "1", 1);  // Set environment variable for WiringPi to use GPIO memory
    wiringPiSetup();  // Initialize the WiringPi library

    pinMode(ButtonPin, INPUT);  // Set ButtonPin as an input pin

    while (1) {
        currentState = digitalRead(ButtonPin);  // Read the current state of the button
        printf("Waiting to push button\n");  // Display a message indicating the program's purpose
        delay(500);  // Pause for a short duration to control the frequency of button state checks

        if (currentState == LOW) {
            // If the button is pressed, counter = counter + 1
            counter++;
        } else {
            // If the button is not pressed, set the current state to 1
            currentState = 1;
        }

        if (currentState != previousState) {
            // If the current state is different from the previous state, check if it's a button press
            if (currentState == 1) {
                // If the button has been pressed, display the number of times it has been pressed
                printf("Button has been pressed: %d times\n", counter);
            }
        }

        previousState = currentState;  // Update the previous state for the next iteration
    }

    return 0;  // Return 0 to indicate successful program execution
}
