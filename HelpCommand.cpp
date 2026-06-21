#include "HelpCommand.h"

HelpCommand::HelpCommand(Calorix& system) : system(system) {}

void HelpCommand::execute() {
    system.printHelp();
}

std::string HelpCommand::getDescription() const {
    return "help";
}