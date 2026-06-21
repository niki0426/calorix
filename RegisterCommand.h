#pragma once
#include "Command.h"
#include "Calorix.h"

class RegisterCommand : public Command {
private:
    Calorix& system;
    std::string username;
    std::string password;
    int age;
    double weight, height;
    std::string gender;

public:
    RegisterCommand(Calorix& system, const std::string& username, const std::string& password, int age, double weight, double height, const std::string& gender);
    void execute() override;
    std::string getDescription() const override;
};