#include "GenerateWorkoutPlanCommand.h"

GenerateWorkoutPlanCommand::GenerateWorkoutPlanCommand(Calorix& system, int duration) : system(system), duration(duration) {}

void GenerateWorkoutPlanCommand::execute() {
    system.generateWorkoutPlan(duration);
}

std::string GenerateWorkoutPlanCommand::getDescription() const {
    return "generate-workout-plan " + std::to_string(duration);
}