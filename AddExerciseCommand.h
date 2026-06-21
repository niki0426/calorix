#pragma once
#include "Command.h"
#include "Calorix.h"

class AddExerciseCommand : public Command {
private:
    Calorix& system;
    std::string name;
    double caloriesPerHour;
    std::string muscleGroup;

public:
    AddExerciseCommand(Calorix& system, const std::string& name, double caloriesPerHour, const std::string& muscleGroup);
    void execute() override;
    std::string getDescription() const override;
};
