// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 2;  // the number of the pushbutton pin
const int buttonPin2 = 3;  // the number of the pushbutton pin
const int buttonPin3 = 4;  // the number of the pushbutton pin
const int buttonPin4 = 5;  // the number of the pushbutton pin

const int ledPin1 = 13;    // the number of the LED pin
const int ledPin2 = 12;    // the number of the LED pin
const int ledPin3 = 11;    // the number of the LED pin
const int ledPin4 = 10;    // the number of the LED pin

// variables will change:
int buttonState1 = 0;  // variable for reading the pushbutton status
int buttonState2 = 0;  // variable for reading the pushbutton status
int buttonState3 = 0;  // variable for reading the pushbutton status
int buttonState4 = 0;  // variable for reading the pushbutton status

int buttonRead1 = 0;  // variable for reading the pushbutton status
int buttonRead2 = 0;  // variable for reading the pushbutton status
int buttonRead3 = 0;  // variable for reading the pushbutton status
int buttonRead4 = 0;  // variable for reading the pushbutton status

int oldRead1 = 1;  // variable for reading the pushbutton status
int oldRead2 = 1;  // variable for reading the pushbutton status
int oldRead3 = 1;  // variable for reading the pushbutton status
int oldRead4 = 1;  // variable for reading the pushbutton status

unsigned long time = 0;           // the last time the output pin was toggled
unsigned long debounce = 200UL;   // the debounce time, increase if the output flickers

void setup() {
  // initialize the LED pin as an output:
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);

}

void loop() {
  // read the state of the pushbutton value:
  buttonRead1 = digitalRead(buttonPin1);
  buttonRead2 = digitalRead(buttonPin2);
  buttonRead3 = digitalRead(buttonPin3);
  buttonRead4 = digitalRead(buttonPin4);

  if((buttonRead1 == 1) && (oldRead1 == 0) && millis() - time > debounce){
    if(buttonState1 == 1){
      buttonState1 = 0;
    }
    else {
      buttonState1 = 1;
      }    
    time = millis();

  }

  if((buttonRead2 == 1) && (oldRead2 == 0) && millis() - time > debounce){
    if(buttonState2 == 1){
      buttonState2 = 0;
    }
    else {
      buttonState2 = 1;
      }    
    time = millis();

  }

  if((buttonRead3 == 1) && (oldRead3 == 0) && millis() - time > debounce){
    if(buttonState3 == 1){
      buttonState3 = 0;
    }
    else {
      buttonState3 = 1;
      }   
    time = millis();

  }

  if((buttonRead4 == 1) && (oldRead4 == 0) && millis() - time > debounce){
    if(buttonState4 == 1){
      buttonState4 = 0;
    }
    else {
      buttonState4 = 1;
      }    
    time = millis();

  }
  digitalWrite(ledPin1, buttonState1);
  digitalWrite(ledPin2, buttonState2);
  digitalWrite(ledPin3, buttonState3);
  digitalWrite(ledPin4, buttonState4);

  oldRead1 = buttonRead1;
  oldRead2 = buttonRead2;
  oldRead3 = buttonRead3;
  oldRead4 = buttonRead4;
  delay(120);
}
