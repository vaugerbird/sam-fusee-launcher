#include <Arduino.h>

#include "fuseegelee.h"
#include "led.h"

// Contains fuseeBin and FUSEE_BIN_SIZE
#include "hekate.h"


void setup()
{
  if (usbInit() == -1) sleepDeep(-1);

  while (!searchTegraDevice())
  {
    ledBlink("orange", 1, 200);
  }

  setupTegraDevice();

  sendPayload(fuseeBin, FUSEE_BIN_SIZE);

  launchPayload();

  sleepDeep(1);
}

void loop()
{
}
