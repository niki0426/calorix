#include "AddToFavoritesCommand.h"

AddToFavoritesCommand::AddToFavoritesCommand(Calorix& system, const std::string& exerciseName) : system(system), exerciseName(exerciseName) {}

void AddToFavoritesCommand::execute() {
    system.addToFavorites(exerciseName);
}