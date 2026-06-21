#include "Calorix.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

User* Calorix::findUserByUsername(const std::string& username) {
    for (auto& user : users) {
        if (user->getUsername() == username) {
            return user.get();
        }
    }
    throw std::runtime_error("Error: User with username '" + username + "' not found.");
}

Trainee* Calorix::findTraineeById(int id) {
    for (auto& user : users) {
        if (user->getUserId() == id) {
            auto trainee = dynamic_cast<Trainee*>(user.get());
            if (!trainee) {
                throw std::runtime_error("Error: User found, but they are not a Trainee.");
            }
            return trainee;
        }
    }
    throw std::runtime_error("Error: Trainee with ID " + std::to_string(id) + " not found.");
}

const Food* Calorix::findFoodByName(const std::string& name) {
    for (auto& food : foods) {
        if (food.getName() == name) {
            return &food;
        }
    }
    throw std::runtime_error("Error: Food '" + name + "' not found.");
}

const Food* Calorix::findFoodById(int id) {
    for (auto& food : foods) {
        if (food.getFoodId() == id) {
            return &food;
        }
    }
    return nullptr;
}

const Exercise* Calorix::findExerciseByName(const std::string& name) {
    for (auto& exercise : exercises) {
        if (exercise.getName() == name) {
            return &exercise;
        }
    }
    throw std::runtime_error("Error: Exercise '" + name + "' not found.");
}

const Exercise* Calorix::findExerciseById(int id) {
    for (auto& exercise : exercises) {
        if (exercise.getExerciseId() == id) {
            return &exercise;
        }
    }
    return nullptr;
}

void Calorix::registerUser(const std::string& username, const std::string& password, int age, double weight, double height, const std::string& genderStr) {
    if (username.length() < 3) {
        std::cout << "Error: Username must be at least 3 characters long.\n";
        return;
    }
    if (password.length() < 6) {
        std::cout << "Error: Password must be at least 6 characters long.\n";
        return;
    }
    if (age < 10 || age > 120) {
        std::cout << "Error: Age must be between 10 and 120.\n";
        return;
    }
    if (weight < 30.0 || weight > 300.0) {
        std::cout << "Error: Weight must be between 30 and 300 kg.\n";
        return;
    }
    if (height < 100.0 || height > 250.0) {
        std::cout << "Error: Height must be between 100 and 250 cm.\n";
        return;
    }

    try {
        findUserByUsername(username);
        std::cout << "Error: Username already exists.\n";
        return;
    }
    catch (const std::runtime_error&) {
        try {
            Gender gender = stringToGender(genderStr);
            UserProfile prof(age, weight, height, gender, ActivityLevel::SEDENTARY);
            users.push_back(std::make_unique<Trainee>(username, password, prof));
            std::cout << "User registered successfully.\n";
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << "\n";
        }
    }
}

void Calorix::login(const std::string& username, const std::string& password) {
    try {
        User* u = findUserByUsername(username);
        if (u->getPassword() != password) {
            std::cout << "Error: Incorrect password.\n";
            return;
        }
        currentUser = u;
        std::cout << "Login successful. Welcome, " << username << "!\n";
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << "\n";
    }
}

void Calorix::logout() {
    if (currentUser) {
        std::cout << "Goodbye, " << currentUser->getUsername() << "!\n";
        currentUser = nullptr;
    }
    else {
        std::cout << "Error: No user is currently logged in.\n";
    }
}

User* Calorix::getCurrentUser() const {
    return currentUser;
}

void Calorix::printHelp() {
    std::cout << "=== Available Commands ===\n";
    std::cout << "register <username> <password> <age> <weight> <height> <gender>\n";
    std::cout << "login <username> <password>\n";
    std::cout << "logout\n";
    std::cout << "help\n";
    std::cout << "end\n";
    if (currentUser && !currentUser->isAdmin()) {
        std::cout << "set-goals <goal-type> <target-value> <deadline>\n";
        std::cout << "log-food <food-name> <quantity_grams>\n";
        std::cout << "log-exercise <exercise-name> <duration_minutes>\n";
        std::cout << "view-daily-summary\n";
        std::cout << "view-progress\n";
        std::cout << "calculate-bmi\n";
        std::cout << "calculate-bmr\n";
        std::cout << "generate-workout-plan <duration_minutes>\n";
        std::cout << "add-to-favorites <exercise-name>\n";
        std::cout << "view-favorites\n";
    }
    if (currentUser && currentUser->isAdmin()) {
        std::cout << "block-user <username>\n";
        std::cout << "add-food <name> <calories_per_100g> <protein_per_100g> <carbs_per_100g> <fat_per_100g>\n";
        std::cout << "add-exercise <name> <calories_burned_per_hour> <muscle-group>\n";
        std::cout << "update-food <food-name> <new-calories>\n";
    }
}

void Calorix::ensureAdminExists() {
    bool hasAdmin = false;
    for (const auto& user : users) {
        if (user->isAdmin()) {
            hasAdmin = true;
            break;
        }
    }
    if (!hasAdmin) {
        UserProfile adminProf(25, 70, 175, Gender::MALE, ActivityLevel::MODERATE);
        users.push_back(std::make_unique<Admin>("admin", "admin", adminProf));
    }
}