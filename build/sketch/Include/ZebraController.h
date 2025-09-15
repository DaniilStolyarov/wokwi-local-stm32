#line 1 "D:\\4_kurs_sem1\\CyberPhysics\\practices\\1\\TrafficLight\\Include\\ZebraController.h"
#ifndef ZEBRA_CONTROLLER_H
#define ZEBRA_CONTROLLER_H

#include <Arduino.h>
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_CS D1
#define TFT_DC D0
#define TFT_LED D8


#define IMAGE_WIDTH 12
#define IMAGE_HEIGHT 16
#define SCALE 5
enum class ZebraControllerState {RED, GREEN};
class ZebraController
{
private:
    ZebraControllerState state;
    Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
    const unsigned char* image;
    uint16_t imageColor;
public:
    ZebraController();
    void setState(ZebraControllerState _state);
    void apply();
};



#endif // ZEBRA_CONTROLLER_H
