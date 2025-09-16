#include "Include/FlagButton.h"
#include <Arduino.h>
void handleClickCallback()
{
    FlagButton::contactCount += 1;
    Serial.println("User requested GREEN!");
}
FlagButton::FlagButton()
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), &handleClickCallback, FALLING);
}

uint32_t FlagButton::reset()
{
    uint32_t temp = contactCount;
    contactCount = 0;
    return temp;
}

uint32_t FlagButton::getValue()
{
    return contactCount;
}



