#include "LoginCommand.h"

LoginCommand::LoginCommand(Calorix& system, const std::string& username, const std::string& password)
    : system(system), username(username), password(password) {
}

void LoginCommand::execute() {
    system.login(username, password);
}

std::string LoginCommand::getDescription() const {
    return "login " + username;
}