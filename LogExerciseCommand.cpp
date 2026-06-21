#include "LogExerciseCommand.h"

LogExerciseCommand::LogExerciseCommand(Calorix& system, const std::string& exerciseName, int durationMinutes)
    : system(system), exerciseName(exerciseName), durationMinutes(durationMinutes) {
}

void LogExerciseCommand::execute() {
    system.logExercise(exerciseName, durationMinutes);
}

std::string LogExerciseCommand::getDescription() const {
    return "log-exercise " + exerciseName;
}