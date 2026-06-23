#pragma once
#include "Command.h"
#include "Calorix.h"

class SetGoalsCommand : public Command {
private:
    Calorix& system;
    std::string goalType;
    double targetValue;
    std::string deadline;

public:
    SetGoalsCommand(Calorix& system, const std::string& goalType, double targetValue, const std::string& deadline);
    void execute() override;
};
