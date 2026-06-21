#include "Calorix.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

void Calorix::blockUser(const std::string& username) {
    Admin* admin = dynamic_cast<Admin*>(currentUser);
    if (!admin) {
        std::cout << "Error: Admin access required.\n";
        return;
    }
    auto it = std::find_if(users.begin(), users.end(), [&username](const std::unique_ptr<User>& u) { return u->getUsername() == username; });
    if (it == users.end()) {
        std::cout << "Error: User not found.\n";
        return;
    }
    if ((*it)->getUsername() == admin->getUsername()) {
        std::cout << "Error: Cannot block yourself.\n";
        return;
    }
    users.erase(it);
    std::cout << "User " << username << " blocked and account deleted.\n";
}

void Calorix::addFood(const std::string& name, double calories, double protein, double carbs, double fat) {
    Admin* admin = dynamic_cast<Admin*>(currentUser);
    if (!admin) {
        std::cout << "Error: Admin access required.\n";
        return;
    }

    try {
        findFoodByName(name);
        std::cout << "Error: Food already exists.\n";
        return;
    }
    catch (const std::runtime_error&) {
        foods.push_back(Food(name, calories, protein, carbs, fat));
        std::cout << "Food added successfully.\n";
    }
}

void Calorix::addExercise(const std::string& name, double caloriesPerHour, const std::string& muscleGroupStr) {
    Admin* admin = dynamic_cast<Admin*>(currentUser);
    if (!admin) {
        std::cout << "Error: Admin access required.\n";
        return;
    }

    try {
        findExerciseByName(name);
        std::cout << "Error: Exercise already exists.\n";
        return;
    }
    catch (const std::runtime_error&) {
        try {
            MuscleGroup muscleGroup = stringToMuscleGroup(muscleGroupStr);
            exercises.push_back(Exercise(name, caloriesPerHour, muscleGroup));
            std::cout << "Exercise added successfully.\n";
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << "\n";
        }
    }
}

void Calorix::updateFood(const std::string& foodName, double newCalories) {
    Admin* admin = dynamic_cast<Admin*>(currentUser);
    if (!admin) {
        std::cout << "Error: Admin access required.\n";
        return;
    }

    try {
        findFoodByName(foodName);
        for (auto& f : foods) {
            if (f.getName() == foodName) {
                f.setCaloriesPer100g(newCalories);
                std::cout << "Food updated successfully.\n";
                return;
            }
        }
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << "\n";
    }
}