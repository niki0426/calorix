#pragma once
#include "Command.h"
#include "Calorix.h"

class LoginCommand : public Command {
private:
    Calorix& system;
    std::string username;
    std::string password;

public:
    LoginCommand(Calorix& system, const std::string& username, const std::string& password);
    void execute() override;
};
