#include "AddFoodCommand.h"

AddFoodCommand::AddFoodCommand(Calorix& system, const std::string& name, double calories, double protein, double carbs, double fat)
    : system(system), name(name), calories(calories), protein(protein), carbs(carbs), fat(fat) {}

void AddFoodCommand::execute() {
    system.addFood(name, calories, protein, carbs, fat);
}

std::string AddFoodCommand::getDescription() const {
    return "add-food " + name;
}