#include "ViewProgressCommand.h"

ViewProgressCommand::ViewProgressCommand(Calorix& system) : system(system) {}

void ViewProgressCommand::execute() {
    system.viewProgress();
}

std::string ViewProgressCommand::getDescription() const {
    return "view-progress";
}