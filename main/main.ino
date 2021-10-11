#include <Arduino.h>

#include "fuseegelee.h"
#include "led_ca.h" //Uncomment for common anode LEDs
//#include "led_cc.h" //Uncomment for common cathode LEDs
//See README for more explanation of above 2 lines.

// Contains fuseeBin and FUSEE_BIN_SIZE
#include "hekate.h"


void setup()
{
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  
  if (usbInit() == -1) sleepDeep(-1);

  while (!searchTegraDevice())
  {
    ledBlink("blue", 1, 1000);
  }

  setupTegraDevice();

  sendPayload(fuseeBin, FUSEE_BIN_SIZE);

  launchPayload();

  sleepDeep(1);
}

void loop()
{
}
