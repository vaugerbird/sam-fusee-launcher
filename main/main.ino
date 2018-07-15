#include <Arduino.h>

#include "fuseegelee.h"
#include "trinketLed.h"
#include "payloads.h"
#include "capTouch.h"

// Contains fuseeBin and FUSEE_BIN_LENGTH
#include "hekate_ctcaer_3.0.h"
#include "sxLoader.h"


void setup()
{
  initCapTouch(A0, 30); //depends on capacitive size of ground and pin
  ledInit();

  const int maxPayloads = 2;
  payload pls[maxPayloads] = {{HEKATE_3_SIZE, hekate_3, "white"}, {SX_LOADER_SIZE, sx_loader, "red2"}};

  int selectedPayload = 1;

  if (usbInit() == -1) sleepDeep(-1);

  while (!searchTegraDevice())
  {
    ledBlink(pls[selectedPayload].color, 1, 200);

    if (clicked()) {
      selectedPayload = (selectedPayload + 1) % maxPayloads;
    }
  }

  setupTegraDevice();

  sendPayload(pls[selectedPayload].data, pls[selectedPayload].p_size);

  launchPayload();

  sleepDeep(1);
}

void loop()
{
}
