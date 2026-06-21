#pragma once
#include "Command.h"
#include "Calorix.h"

class LogExerciseCommand : public Command {
private:
    Calorix& system;
    std::string exerciseName;
    int durationMinutes;

public:
    LogExerciseCommand(Calorix& system, const std::string& exerciseName, int durationMinutes);
    void execute() override;
    std::string getDescription() const override;
};
