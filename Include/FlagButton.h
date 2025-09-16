#ifndef FLAGBUTTON_H
#define FLAGBUTTON_H

#include <Arduino.h>

#define BUTTON_PIN A0

class FlagButton
{
public:
    static inline uint32_t contactCount;
    FlagButton();
    uint32_t reset();
    uint32_t getValue();
};
void handleClickCallback();
#endif // FLAGBUTTON_H