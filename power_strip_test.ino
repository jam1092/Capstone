// Global variables
#define NUM_RELAYS 4
int relaySignal[NUM_RELAYS] = {2, 3, 4, 5};
int sensorSignal = 6;

// Starting with relays on
void setup(){

  for (int i = 0; i < NUM_RELAYS; i++){
    pinMode(relaySignal[i], OUTPUT);
    digitalWrite(relaySignal[i], HIGH);
  }

  delay(100);
}

// Relay logic
void loop() {
  for (int i = 0; i < NUM_RELAYS; i++){
    delay(1000);
    digitalWrite(relaySignal[i], HIGH);
    delay(1000);
    digitalWrite(relaySignal[i], LOW);
  }

  delay(100);
}