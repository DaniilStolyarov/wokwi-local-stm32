#ifndef CARS_CONTROLLER_H
#define CARS_CONTROLLER_H

#include "Include/LED.h"

#define RED_LED_PIN D7
#define YELLOW_LED_PIN D4
#define GREEN_LED_PIN D2

enum class CarsControllerState {RED, YELLOW, GREEN};

class CarsController
{
private:
    CarsControllerState state;
public:
    LED red = LED(RED_LED_PIN);
    LED yellow = LED(YELLOW_LED_PIN);
    LED green = LED(GREEN_LED_PIN);
    CarsController();
    
    void setState(CarsControllerState _state);
    CarsControllerState getState();
    
    void apply();
};  

#endif // CARS_CONTROLLER_H