#define NUM_BUTTONS 4

int buttonPins[NUM_BUTTONS] = {A0, A1, A2, A3};
int ledPins[NUM_BUTTONS] = {6, 7, 8, 9};
bool ledState[NUM_BUTTONS] = {false, false, false, false};
bool buttonPressed[NUM_BUTTONS] = {false, false, false, false};

void setup() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      if (!buttonPressed[i]) {
        buttonPressed[i] = true;
        ledState[i] = !ledState[i];
        digitalWrite(ledPins[i], ledState[i] ? HIGH : LOW); 
      }
    } else {
      buttonPressed[i] = false;
    }
  }
}
