#include <Arduino.h>
#include <Include/CarsController.h>
#include <Include/ZebraController.h>
#include "Include/Dispatcher.h"

const uint32_t TACT = 500000;
uint32_t debug_delay;
uint32_t micros_buffer;
Dispatcher* dispatcher;

void setup() {
    Serial.begin(115200);

    CarsController carsController = CarsController();
    ZebraController zebraController = ZebraController();
    size_t instructionCount = 4;
    RoadState* roadProgram = new RoadState[instructionCount]{
        {ZebraControllerState::RED, CarsControllerState::YELLOW, 1000},
        {ZebraControllerState::RED, CarsControllerState::GREEN, 10000},
        {ZebraControllerState::RED, CarsControllerState::YELLOW, 1000},
        {ZebraControllerState::GREEN, CarsControllerState::RED, 15000},
    };
    dispatcher = new Dispatcher(roadProgram, instructionCount, &carsController, &zebraController, TACT / 1000);
    dispatcher->initialize();
}

void loop() {
    micros_buffer = micros();
    dispatcher->call();
    debug_delay = (TACT + micros_buffer - micros()) / 1000;
    delay(debug_delay);

    Serial.print(" debug_delay_ms: ");
    Serial.println(debug_delay);
}
