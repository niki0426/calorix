#include "SetGoalsCommand.h"

SetGoalsCommand::SetGoalsCommand(Calorix& system, const std::string& goalType, double targetValue, const std::string& deadline)
    : system(system), goalType(goalType), targetValue(targetValue), deadline(deadline) {
}

void SetGoalsCommand::execute() {
    system.setGoals(goalType, targetValue, deadline);
}

std::string SetGoalsCommand::getDescription() const {
    return "set-goals " + goalType;
}