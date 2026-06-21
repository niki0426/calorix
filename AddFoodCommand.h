#pragma once
#include "Command.h"
#include "Calorix.h"

class AddFoodCommand : public Command {
private:
    Calorix& system;
    std::string name;
    double calories, protein, carbs, fat;

public:
    AddFoodCommand(Calorix& system, const std::string& name, double calories, double protein, double carbs, double fat);
    void execute() override;
    std::string getDescription() const override;
};
