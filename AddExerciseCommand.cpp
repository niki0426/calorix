#include "AddExerciseCommand.h"

AddExerciseCommand::AddExerciseCommand(Calorix& system, const std::string& name, double caloriesPerHour, const std::string& muscleGroup)
    : system(system), name(name), caloriesPerHour(caloriesPerHour), muscleGroup(muscleGroup) {}

void AddExerciseCommand::execute() {
    system.addExercise(name, caloriesPerHour, muscleGroup);
}

