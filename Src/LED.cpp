#include "Include/LED.h"

LED::LED(uint32_t pin)
{
    this->Pin = pin; 
    this->Value = LOW;
}

void LED::enable()
{
    this->Value = HIGH;
}

void LED::disable()
{
    this->Value = LOW;
}

void LED::toggle()
{
    ++this->Value %= 2;
}

void LED::apply()
{
    pinMode(Pin, OUTPUT);
    digitalWrite(Pin, Value);
}