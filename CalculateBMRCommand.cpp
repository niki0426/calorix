#include "CalculateBMRCommand.h"

CalculateBMRCommand::CalculateBMRCommand(Calorix& system) : system(system) {}

void CalculateBMRCommand::execute() {
    system.calculateBMR();
}

