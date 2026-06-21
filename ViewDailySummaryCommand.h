#pragma once
#include "Command.h"
#include "Calorix.h"

class ViewDailySummaryCommand : public Command {
private:
    Calorix& system;

public:
    explicit ViewDailySummaryCommand(Calorix& system);
    void execute() override;
    std::string getDescription() const override;
};
