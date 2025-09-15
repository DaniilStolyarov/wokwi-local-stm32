#line 1 "D:\\4_kurs_sem1\\CyberPhysics\\practices\\1\\TrafficLight\\Include\\LED.h"
#ifndef LED_H
#define LED_H

#include <Arduino.h>
class LED
{
public:
    uint32_t Pin;
    uint32_t Value;
    LED(uint32_t pin);
    void enable();
    void disable();
    void toggle();
    void apply();
};

#endif // LED_H