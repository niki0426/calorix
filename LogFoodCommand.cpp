#include "LogFoodCommand.h"

LogFoodCommand::LogFoodCommand(Calorix& system, const std::string& foodName, double quantityGrams)
    : system(system), foodName(foodName), quantityGrams(quantityGrams) {
}

void LogFoodCommand::execute() {
    system.logFood(foodName, quantityGrams);
}