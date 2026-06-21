#include "ViewDailySummaryCommand.h"

ViewDailySummaryCommand::ViewDailySummaryCommand(Calorix& system) : system(system) {}

void ViewDailySummaryCommand::execute() {
    system.viewDailySummary();
}

std::string ViewDailySummaryCommand::getDescription() const {
    return "view-daily-summary";
}