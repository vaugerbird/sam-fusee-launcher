

# sam-fusee-launcher
Fusee Launcher for the Seeed Studio Seeeduino XIAO. Based on [sam fusee launcher](https://github.com/atlas44/sam-fusee-launcher).

Build and tested with Arduino SDK.

# Install
* Download and extract the firmware: [CTCaer Hekate 5.6.3](https://github.com/vaugerbird/sam-fusee-launcher/releases/tag/v0.1)
* Connect the XIAO to your computer and quickly bridge the reset pins twice
* Open the "Arduino" device and copy the extracted files on the device


# Build
Full guide: [Seeeduino XIAO software setup](https://wiki.seeedstudio.com/Seeeduino-XIAO/#software)

Summary:
* Download and install arduino IDE http://www.arduino.cc/en/Main/Software
* In Arduino: go to "Prefences" and add to "Additional Board Manager URLs" followin URL:
*  `https://files.seeedstudio.com/arduino/package_seeeduino_boards_index.json`
* go to "Tools > Board > Board Manager" and select "Type: All" and
* Input "Seeeduino XIAO" in the search box
* Select the Seeeduino XIAO with "Tools > Board > Seeeduino XIAO M0"

Go to Sketch > Include Library > Manage Libraries
Install USBHost and FlashStorage

Connect the XIAO to your computer and double click on the reset button.
Your computer should detect the XIAO automatically

Got to Tools > Port and select your conneted XIAO. (If the name does not show up, use Device Manager to find the proper COM port)

Download this repository, open main/main.ino with Arduino IDE.

Then Verify/Compile (Ctrl + R)
If no errors appear
Upload (Ctrl + U).

The XIAO is ready for use.

LED is:
* blinking orange -> searching for Switch in RCM mode
* red -> no Switch found
* off (except the power LED) -> finished successfully

# Update the Payload
Download your favorite payload from its appropriate repository.
Run the python script `tools/binConverter.py` with the path to the file as an argument:
`python binConverter.py "C:\pathToMyPayload\hekateNew.bin` or just drag the .bin file on the script

In the same folder as the .bin file is located, a new .h file should appear. Copy the new file to the main folder and in the main.ino go to line 6 `#include "hekate_ctcaer_2.3.h"` and rename it to your new file `#include "hekateNew.h"`

Then just compile and upload.

# Hardware
[Seeedduino XIAO](https://www.amazon.com/gp/product/B09FSQM3K5/ref=crt_ewc_title_dp_1?ie=UTF8&psc=1&smid=A1YP59NGBNBZUR) + [Adafruit LiPoly Backpack](https://www.amazon.com/Adafruit-Trinket-LiIon-LiPoly-Backpack/dp/B00SK697AU/ref=sr_1_1?crid=17DZC8FSOW9ZN&dchild=1&keywords=adafruit+lipo+backpack&qid=1633812236&sprefix=adafruit+lipo%2Caps%2C240&sr=8-1) + Button + LiPoly Battery

![Layout](./images/layout.png)

# Thanks to:
* [noemu](https://github.com/noemu/sam-fusee-launcher)
* [atlas44](https://github.com/atlas44/sam-fusee-launcher)
* [CTCaer](https://github.com/CTCaer/hekate)


