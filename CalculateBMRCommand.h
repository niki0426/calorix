#pragma once
#include "Command.h"
#include "Calorix.h"

class CalculateBMRCommand : public Command {
private:
    Calorix& system;

public:
    explicit CalculateBMRCommand(Calorix& system);
    void execute() override;
};

