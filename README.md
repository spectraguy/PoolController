# PoolController

## Prerequisites

* [Arduino IDE](https://www.arduino.cc/en/software/): version 2+
* Arduino board manager:
    * esp32 by Espressif Systems: 3.0.2
* Select "ESP32 Dev Module" as board + appropriate COM port
* Tools -> Upload -> 115200 baud

## Operations

### Upload via serial:

* Put ESP32 in upload mode
    * Press & hold IO0
	* Press & release EN
	* Release IO0
* Press Upload in IDE (will compile, then upload, then switch to Serial Monitor)
* Press and release EN to restart and boot normally
