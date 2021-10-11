#include <Arduino.h>

#include "fuseegelee.h"
#include "led_ca.h"

// Contains fuseeBin and FUSEE_BIN_SIZE
#include "hekate.h"


void setup()
{
  if (usbInit() == -1) sleepDeep(-1);

  while (!searchTegraDevice())
  {
    ledBlink("blue", 1, 500);
  }

  setupTegraDevice();

  sendPayload(fuseeBin, FUSEE_BIN_SIZE);

  launchPayload();

  sleepDeep(1);
}

void loop()
{
}
