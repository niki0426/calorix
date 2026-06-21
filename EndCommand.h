#pragma once
#include "Command.h"
#include "Calorix.h"

class EndCommand : public Command {
private:
    Calorix& system;
    bool& running;

public:
    EndCommand(Calorix& system, bool& running);
    void execute() override;
    std::string getDescription() const override;
};