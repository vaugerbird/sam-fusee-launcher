#include <Arduino.h>
#include <FlashStorage.h>

#include "fuseegelee.h"
#include "trinketLed.h"
#include "payloads.h"
#include "capTouch.h"

// Contains fuseeBin and FUSEE_BIN_LENGTH
#include "hekate_ctcaer_4.2.h"
#include "sxLoader.h"

FlashStorage(flash_payloadNR_INT, int);

void setup()
{
  initCapTouch(A0, 30); //pin A0, the second value depends on capacitive size of ground and pin
  ledInit();

  const int maxPayloads = 2;
  payload pls[maxPayloads] = {{HEKATE_CTCAER_4_2_SIZE, hekate_ctcaer_4_2, "white"}, {SXLOADER_SIZE, sxLoader, "red2"}};

  int selectedPayload = flash_payloadNR_INT.read();
  selectedPayload = (selectedPayload) % maxPayloads;

  if (usbInit() == -1) sleepDeep(-1);

  while (!searchTegraDevice())
  {
    ledBlink(pls[selectedPayload].color, 1, 200);

    if (clicked()) {
      selectedPayload = (selectedPayload + 1) % maxPayloads;
      flash_payloadNR_INT.write(selectedPayload);
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
