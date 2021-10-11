#include <Arduino.h>

void setLedColor(const char color[]) {
  if (color == "red") {
    analogWrite(A1, 255); //R
    analogWrite(A2, 0); //G
    analogWrite(A3, 0); //B
  } else if (color == "green") {
    analogWrite(A1, 0); //R
    analogWrite(A2, 255); //G
    analogWrite(A3, 0); //B
  } else if (color == "black") {
    analogWrite(A1, 0); //R
    analogWrite(A2, 0); //G
    analogWrite(A3, 0); //B
  } else if (color == "blue") {
    analogWrite(A1, 0); //R
    analogWrite(A2, 0); //G
    analogWrite(A3, 255); //B
  } else if (color == "red2") {
    analogWrite(A1, 100); //R
    analogWrite(A2, 0); //G
    analogWrite(A3, 0); //B
  } else {
    analogWrite(A1, 255); //R
    analogWrite(A2, 255); //G
    analogWrite(A3, 255); //B
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
  if (errorCode == 1) {
    setLedColor("green"); //led to green
    delay(3000);
    setLedColor("black"); //led off
  } else {
    setLedColor("red"); //led to red
  }
  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk; /* Enable deepsleep */
  __DSB(); /* Ensure effect of last store takes effect */
  __WFI(); /* Enter sleep mode */
}
