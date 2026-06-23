#pragma once
#include "Command.h"
#include "Calorix.h"

class LogoutCommand : public Command {
private:
    Calorix& system;

public:
    explicit LogoutCommand(Calorix& system);
    void execute() override;
};
