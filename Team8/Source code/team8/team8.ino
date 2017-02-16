#include <SoftwareSerial.h>

const int buttonPin = 8;
const int ledPin = 13;
int buttonState = 0;
int counter = 0;

SoftwareSerial bluetooth(2, 3);

void setup() {
  Serail.begin(9600);
  bluetooth.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  delay(100);

  if(buttonState == HIGH) {
    if(digitalRead(buttonPin) != buttonState) {
      if(counter == 0) {
        counter = 1;
        Serial.write("out\n");
        bluetooth.write("out\n");
      }
      else {
        counter = 0;
        Serial.write("in\n");
        bluetooth.write("in\n");
      }
    }
  }
}

