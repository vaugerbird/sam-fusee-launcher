#include <Arduino.h>

void setLedColor(const char color[]) {
  if (color == "red") {
    analogWrite(A1, 255); //VIN
    digitalWrite(2, LOW); //R
    digitalWrite(3, HIGH); //G
    digitalWrite(4, HIGH); //B
  } else if (color == "green") {
    analogWrite(A1, 255); //VIN
    digitalWrite(2, HIGH); //R
    digitalWrite(3, LOW); //G
    digitalWrite(4, HIGH); //B
  } else if (color == "black") {
    analogWrite(A1, 0); //VIN
    digitalWrite(2, LOW); //R
    digitalWrite(3, LOW); //G
    digitalWrite(4, LOW); //B
  } else if (color == "blue") {
    analogWrite(A1, 255); //VIN
    digitalWrite(2, HIGH); //R
    digitalWrite(3, HIGH); //G
    digitalWrite(4, LOW); //B
  } else {
    analogWrite(A1, 255); //VIN
    digitalWrite(2, LOW); //R
    digitalWrite(3, LOW); //G
    digitalWrite(4, LOW); //B
  }
}

void ledBlink(const char color[], int count, int duration) {
  for (int counter = 0; counter < count; counter++) {
    for (int onOff = 1; onOff >= 0; onOff--) {
      if (onOff == 1) {
        setLedColor(color);
      } else {
        setLedColor("black");
      }
      delay(duration / (2.0 * count));
    }
  }
}

void sleepDeep(int errorCode) {
  // Turn off all LEDs and go to sleep. To launch another payload, press the reset button on the device.
  //delay(100);
  digitalWrite(PIN_LED_RXL, HIGH);
  digitalWrite(PIN_LED_TXL, HIGH);
  if (errorCode == 1) {
    setLedColor("green"); //led to green
    delay(1000);
    setLedColor("black"); //led off
  } else {
    setLedColor("red"); //led to red
  }
  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk; /* Enable deepsleep */
  __DSB(); /* Ensure effect of last store takes effect */
  __WFI(); /* Enter sleep mode */
}
