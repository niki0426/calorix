#include "AddToFavoritesCommand.h"

AddToFavoritesCommand::AddToFavoritesCommand(Calorix& system, const std::string& exerciseName) : system(system), exerciseName(exerciseName) {}

void AddToFavoritesCommand::execute() {
    system.addToFavorites(exerciseName);
}

std::string AddToFavoritesCommand::getDescription() const {
    return "add-to-favorites " + exerciseName;
}