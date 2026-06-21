#pragma once
#include "Command.h"
#include "Calorix.h"

class ViewFavoritesCommand : public Command {
private:
    Calorix& system;

public:
    explicit ViewFavoritesCommand(Calorix& system);
    void execute() override;
    std::string getDescription() const override;
};
