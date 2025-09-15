#line 1 "D:\\4_kurs_sem1\\CyberPhysics\\practices\\1\\TrafficLight\\Include\\Dispatcher.h"
#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "Include/CarsController.h"
#include "Include/ZebraController.h"

struct RoadState
{
    ZebraControllerState zebra;
    CarsControllerState cars;
    uint32_t delayMillis;
};
class Dispatcher
{
private:
    uint32_t stateTicks;
    uint32_t millisPerTick;
    uint32_t instructionIndex;
    void apply();
    void executeInstruction();
public:
    RoadState* roadProgram;
    CarsController* carsController;
    ZebraController* zebraController;
    size_t instructionCount;
    Dispatcher(RoadState* _roadProgram, size_t _instructionCount, CarsController* _carsController, ZebraController* _zebraController, uint32_t _millisPerTick);
    
    void initialize();
    void call();
};

#endif // DISPATCHER_H