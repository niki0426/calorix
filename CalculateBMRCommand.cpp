#include "CalculateBMRCommand.h"

CalculateBMRCommand::CalculateBMRCommand(Calorix& system) : system(system) {}

void CalculateBMRCommand::execute() {
    system.calculateBMR();
}

std::string CalculateBMRCommand::getDescription() const {
    return "calculate-bmr";
}
