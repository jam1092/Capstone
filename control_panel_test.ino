#define NUM_BUTTONS 4

int buttonPins[NUM_BUTTONS] = {A0, A1, A2, A3};  // Button input pins
int ledPins[NUM_BUTTONS] = {6, 7, 8, 9};         // LED output pins
bool ledState[NUM_BUTTONS] = {false, false, false, false}; // Track LED states
bool buttonPressed[NUM_BUTTONS] = {false, false, false, false}; // Track button press state

void setup() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);  // Enable internal pull-up resistor
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // Ensure LEDs start OFF
  }
}

void loop() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    if (digitalRead(buttonPins[i]) == LOW) { // Button Pressed
      if (!buttonPressed[i]) {  // Only trigger if it wasn't already pressed
        buttonPressed[i] = true;  // Mark button as pressed
        ledState[i] = !ledState[i]; // Toggle LED state
        digitalWrite(ledPins[i], ledState[i] ? HIGH : LOW); // Update LED
      }
    } else {
      buttonPressed[i] = false; // Reset button press flag when released
    }
  }
}