#include "Include/Knob.h"

Knob::Knob()
{
    pinMode(KNOB_SIG_PIN, INPUT);
}

uint32_t Knob::readValue()
{
   //return 400;
    return analogRead(KNOB_SIG_PIN);
}
