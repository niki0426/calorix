#include "ViewDailySummaryCommand.h"

ViewDailySummaryCommand::ViewDailySummaryCommand(Calorix& system) : system(system) {}

void ViewDailySummaryCommand::execute() {
    system.viewDailySummary();
}
