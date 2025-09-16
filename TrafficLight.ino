#include <Arduino.h>
#include "Include/CarsController.h"
#include "Include/ZebraController.h"
#include "Include/Dispatcher.h"
#include "Include/FlagButton.h"
#include "Include/Knob.h"


const uint32_t TACT = 500000;
uint32_t debug_delay;
uint32_t micros_buffer;
Dispatcher* dispatcher;
Knob* knob;
void setup() {
    Serial.begin(115200);
    knob = new Knob();
    int knobValue = knob->readValue();
    
    CarsController carsController = CarsController();
    ZebraController zebraController = ZebraController();
    FlagButton flagButton = FlagButton();
    
    size_t instructionCount = 4;
    Instruction* roadProgram = new Instruction[instructionCount]{
        {ZebraControllerState::RED, CarsControllerState::YELLOW, 5000},
        {ZebraControllerState::RED, CarsControllerState::GREEN, 30000, .flagButtonDependency=false},
        {ZebraControllerState::RED, CarsControllerState::YELLOW, 5000},
        {ZebraControllerState::GREEN, CarsControllerState::RED, 30000},
    };
    dispatcher = new Dispatcher(roadProgram, instructionCount, &carsController, &zebraController, &flagButton, TACT / 1000);
    dispatcher->initialize();

    dispatcher->setInstructionDelay(3, knobValue * 100);
    Serial.print(" ZEBRA_GREEN_DELAY_ms: ");
    Serial.print(knobValue * 100);
}

void loop() {
    micros_buffer = micros();

    dispatcher->call();

    debug_delay = (TACT + micros_buffer - micros()) / 1000;

    delay(debug_delay);

    Serial.print(" debug_delay_ms: ");
    Serial.println(debug_delay);
}
