#ifndef KNOB_H
#define KNOB_H
#include <Arduino.h>

#define KNOB_SIG_PIN A4

class Knob
{
private:
public:
    Knob();
    uint32_t readValue();
};

#endif // KNOB_H