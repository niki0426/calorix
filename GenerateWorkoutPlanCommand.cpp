#include "GenerateWorkoutPlanCommand.h"

GenerateWorkoutPlanCommand::GenerateWorkoutPlanCommand(Calorix& system, int duration) : system(system), duration(duration) {}

void GenerateWorkoutPlanCommand::execute() {
    system.generateWorkoutPlan(duration);
}
