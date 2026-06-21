#include "CalculateBMICommand.h"

CalculateBMICommand::CalculateBMICommand(Calorix& system) : system(system) {}

void CalculateBMICommand::execute() {
    system.calculateBMI();
}

std::string CalculateBMICommand::getDescription() const {
    return "calculate-bmi";
}