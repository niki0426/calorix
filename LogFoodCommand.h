#pragma once
#include "Command.h"
#include "Calorix.h"

class LogFoodCommand : public Command {
private:
    Calorix& system;
    std::string foodName;
    double quantityGrams;

public:
    LogFoodCommand(Calorix& system, const std::string& foodName, double quantityGrams);
    void execute() override;
};
