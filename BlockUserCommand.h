#pragma once
#include "Command.h"
#include "Calorix.h"

class BlockUserCommand : public Command {
private:
    Calorix& system;
    std::string username;

public:
    BlockUserCommand(Calorix& system, const std::string& username);
    void execute() override;
    std::string getDescription() const override;
};
