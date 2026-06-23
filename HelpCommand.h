#pragma once
#include "Command.h"
#include "Calorix.h"

class HelpCommand : public Command {
private:
    Calorix& system;

public:
    explicit HelpCommand(Calorix& system);
    void execute() override;
};
