#pragma once
#include "Command.h"
#include "Calorix.h"

class UpdateFoodCommand : public Command {
private:
    Calorix& system;
    std::string foodName;
    double newCalories;

public:
    UpdateFoodCommand(Calorix& system, const std::string& foodName, double newCalories);
    void execute() override;
};
