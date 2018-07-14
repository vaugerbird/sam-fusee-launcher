#include "Arduino.h"

int pin = 0;

int avg = 0;

bool alreadyClicked = false;
int offset = 100;

int readCap(int count) {
  int maxVal = -10000;
  for (int index = 0; index < count; index++) {
    pinMode(pin, INPUT_PULLUP);

    pinMode(A1, OUTPUT);
    digitalWrite(A1, 0);
    delayMicroseconds(500); //500 for 
    analogRead(A1);

    pinMode(pin, INPUT);
    int value = analogRead(pin);

    if (maxVal < value) {
      maxVal = value;
    }
  }

  return maxVal; //maybe median would be better, but max is easier and faster to calculate
}

bool pressed() {
  return readCap(15) > avg + offset;
}

bool clicked() {
  bool pressedVal = pressed();
  if (pressedVal & !alreadyClicked) {
    alreadyClicked = true;
    return true;
  }
  if (!pressedVal & alreadyClicked) {
    alreadyClicked = false;
  }
  return false;
}

void initCapTouch(int pinNr = A0, int off=100) {
  pin = pinNr;
  offset = off;
  avg = readCap(500);
}
