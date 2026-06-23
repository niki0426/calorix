#pragma once
#include "Command.h"
#include "Calorix.h"

class ViewProgressCommand : public Command {
private:
    Calorix& system;

public:
    explicit ViewProgressCommand(Calorix& system);
    void execute() override;
};
