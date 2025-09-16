#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "Include/CarsController.h"
#include "Include/ZebraController.h"
#include "Include/FlagButton.h"
struct RoadState
{
    ZebraControllerState zebra;
    CarsControllerState cars;
    uint32_t delayMillis;
    bool flagButtonDependency = true;
};
class Dispatcher
{
private:
    uint32_t stateTicks;
    uint32_t millisPerTick;
    int16_t instructionIndex;
    int16_t executedInstructionIndex;
    void apply();
    void executeInstruction();
    void nextInstruction();
public:
    RoadState* roadProgram;
    CarsController* carsController;
    ZebraController* zebraController;
    FlagButton* flagButton;
    size_t instructionCount;
    Dispatcher(RoadState* _roadProgram, size_t _instructionCount, CarsController* _carsController, ZebraController* _zebraController, FlagButton* _flagButton, uint32_t _millisPerTick);
    
    void initialize();
    void call();
};

#endif // DISPATCHER_H