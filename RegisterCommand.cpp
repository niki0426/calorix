#include "RegisterCommand.h"

RegisterCommand::RegisterCommand(Calorix& system, const std::string& username, const std::string& password, int age, double weight, double height, const std::string& gender)
    : system(system), username(username), password(password), age(age), weight(weight), height(height), gender(gender) {
}

void RegisterCommand::execute() {
    system.registerUser(username, password, age, weight, height, gender);
}