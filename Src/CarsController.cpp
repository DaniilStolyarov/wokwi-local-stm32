#include <Arduino.h>
#include "Include/CarsController.h"

CarsController::CarsController()
{
    state = CarsControllerState::RED;
}

void CarsController::setState(CarsControllerState _state)
{
        state = _state;
        red.Value = (state == CarsControllerState::RED) ? HIGH : LOW;
        yellow.Value = (state == CarsControllerState::YELLOW) ? HIGH : LOW; 
        green.Value = (state == CarsControllerState::GREEN) ? HIGH : LOW; 
}

CarsControllerState CarsController::getState()
{
    return state;
}

void CarsController::apply()
{
    red.apply(); yellow.apply(); green.apply(); 
}