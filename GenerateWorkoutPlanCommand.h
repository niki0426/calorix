#pragma once
#include "Command.h"
#include "Calorix.h"

class GenerateWorkoutPlanCommand : public Command {
private:
    Calorix& system;
    int duration;

public:
    GenerateWorkoutPlanCommand(Calorix& system, int duration);
    void execute() override;
};
