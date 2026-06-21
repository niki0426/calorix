#pragma once
#include "Command.h"
#include "Calorix.h"

class AddToFavoritesCommand : public Command {
private:
    Calorix& system;
    std::string exerciseName;

public:
    AddToFavoritesCommand(Calorix& system, const std::string& exerciseName);
    void execute() override;
    std::string getDescription() const override;
};
