#include "ViewFavoritesCommand.h"

ViewFavoritesCommand::ViewFavoritesCommand(Calorix& system) : system(system) {}

void ViewFavoritesCommand::execute() {
    system.viewFavorites();
}