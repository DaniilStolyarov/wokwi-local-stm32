#include "Include/Dispatcher.h"
#include <Arduino.h>
Dispatcher::Dispatcher(RoadState *_roadProgram, size_t _instructionCount, CarsController* _carsController, ZebraController* _zebraController, uint32_t _millisPerTick)
{
    carsController = _carsController;
    zebraController = _zebraController;
    roadProgram = _roadProgram;
    instructionCount = _instructionCount;
    millisPerTick = _millisPerTick;
    stateTicks = 0;
    instructionIndex = 0;
}

void Dispatcher::executeInstruction()
{
    Serial.print("Execute Instruction: #");
    Serial.print(instructionIndex);
    Serial.print(", State ticks: ");
    Serial.print(stateTicks);
    Serial.print(", ms eval: ");
    Serial.print(stateTicks * millisPerTick);

    if (stateTicks * millisPerTick >= roadProgram[instructionIndex].delayMillis) 
    {
        ++instructionIndex %= instructionCount;
        stateTicks = 0;
    }
    carsController->setState(roadProgram[instructionIndex].cars);
    zebraController->setState(roadProgram[instructionIndex].zebra);
}

void Dispatcher::initialize()
{
    carsController->setState(roadProgram[instructionIndex].cars);
    zebraController->setState(roadProgram[instructionIndex].zebra);
    carsController->apply();
    zebraController->apply();
}

void Dispatcher::apply()
{
    carsController->apply();
    zebraController->apply();
    stateTicks++;
}

void Dispatcher::call()
{
    executeInstruction();
    apply();
}