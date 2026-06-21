#include "UpdateFoodCommand.h"

UpdateFoodCommand::UpdateFoodCommand(Calorix& system, const std::string& foodName, double newCalories)
    : system(system), foodName(foodName), newCalories(newCalories) {
}

void UpdateFoodCommand::execute() {
    system.updateFood(foodName, newCalories);
}

std::string UpdateFoodCommand::getDescription() const {
    return "update-food " + foodName;
}