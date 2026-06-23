#include "EndCommand.h"
#include <iostream>

EndCommand::EndCommand(Calorix& system, bool& running) : system(system), running(running) {}

void EndCommand::execute() {
    std::cout << "Saving data and exiting...\n";
    system.saveData();
    running = false;
}
