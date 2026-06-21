#include "ViewFavoritesCommand.h"

ViewFavoritesCommand::ViewFavoritesCommand(Calorix& system) : system(system) {}

void ViewFavoritesCommand::execute() {
    system.viewFavorites();
}

std::string ViewFavoritesCommand::getDescription() const {
    return "view-favorites";
}