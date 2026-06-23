#include "LogoutCommand.h"

LogoutCommand::LogoutCommand(Calorix& system) : system(system) {}

void LogoutCommand::execute() {
    system.logout();
}