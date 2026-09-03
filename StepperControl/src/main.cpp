#include <Arduino.h>

const int dirPin = 2;
const int stepPin = 3;
const int stepsPerRevolution = 1600;
const int gearRatio = 10;

void stop()
{
    while (true) {
        // Stay here forever.
        delay(1000);
    }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Code started.");
}

void loop() {

  // set motor direction clockwise
  Serial.println("Motor direction set.");
  digitalWrite(dirPin, HIGH);

  // spin motor slowly
  Serial.println("Moving init.");
  for (int x = 0; x < (stepsPerRevolution*gearRatio); x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(800);
  }
  Serial.println("Moving ends.");


  // prob just wait a second
  delay(1000);

  Serial.println("Motor direction set 2.");
  // set motor direction to counterclockwise
  digitalWrite(dirPin, LOW);

  // spin motor quickly

  Serial.println("Moving init 2.");
  for (int x = 0; x < (stepsPerRevolution*gearRatio); x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(800);
  }
  Serial.println("Moving ends 2.");

  // prob just wait a second
  delay(1000);

  // Serial.println("Everything stops.");
  // stop();

}
