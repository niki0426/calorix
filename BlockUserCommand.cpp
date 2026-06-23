#include "BlockUserCommand.h"

BlockUserCommand::BlockUserCommand(Calorix& system, const std::string& username) : system(system), username(username) {}

void BlockUserCommand::execute() {
    system.blockUser(username);
}