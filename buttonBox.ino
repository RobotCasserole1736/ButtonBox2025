#include "Joystick.h"

// Define the number of input pins
#define NUM_PINS 18

// Define the digital pins connected to your buttons
const uint8_t buttonPins[NUM_PINS] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 16, 14, 15, A0, A1, A2, A3
};

// Array to store the stable state of each button
bool buttonStates[NUM_PINS] = {0};

// Debounce counters for each button
uint8_t highCounters[NUM_PINS] = {0};
uint8_t lowCounters[NUM_PINS] = {0};

// Threshold for debouncing
const uint8_t debounceThreshold = 5;

// Joystick object with 18 buttons and no axes
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD, NUM_PINS, 0, 
                   false, false, false, false, false, false, false, false, false, false, false);

void setup() {
    // Initialize the joystick
    Joystick.begin();

    // Set button pins as input with pullup
    for (int i = 0; i < NUM_PINS; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }

}

void loop() {
    // Read and debounce each button
    for (int i = 0; i < NUM_PINS; i++) {
        bool rawState = !digitalRead(buttonPins[i]); // Active LOW

        // Update debounce counters
        if (rawState) {
            highCounters[i]++;
            lowCounters[i] = 0;
        } else {
            lowCounters[i]++;
            highCounters[i] = 0;
        }

        // Check if debounce threshold is reached for HIGH
        if (highCounters[i] >= debounceThreshold && !buttonStates[i]) {
            buttonStates[i] = true; // Update stable state
            Joystick.setButton(i, true); // Press the button
        }

        // Check if debounce threshold is reached for LOW
        if (lowCounters[i] >= debounceThreshold && buttonStates[i]) {
            buttonStates[i] = false; // Update stable state
            Joystick.setButton(i, false); // Release the button
        }
    }

    // Send the HID report
    Joystick.sendState();

    // Maintain a 20ms loop interval
    delay(20);
}
