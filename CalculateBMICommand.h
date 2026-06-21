#pragma once
#include "Command.h"
#include "Calorix.h"

class CalculateBMICommand : public Command {
private:
    Calorix& system;

public:
    explicit CalculateBMICommand(Calorix& system);
    void execute() override;
    std::string getDescription() const override;
};
