#include "Calorix.h"
#include <fstream>
#include <sstream>
#include <vector>

Calorix::Calorix() : currentUser(nullptr) {
    loadData();
}

Calorix::~Calorix() {
    saveData();
}

void Calorix::loadData() {
    loadUsers();
    loadFoods();
    loadExercises();
    loadFoodDiary();
    loadExerciseDiary();
}

void Calorix::saveData() {
    saveUsers();
    saveFoods();
    saveExercises();
    saveFoodDiary();
    saveExerciseDiary();
}

void Calorix::loadUsers() {
    std::ifstream file(usersFile);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> parts;
        while (std::getline(iss, token, '|')) {
            parts.push_back(token);
        }
        if (parts.size() < 9) continue;

        int id = std::stoi(parts[0]);
        std::string username = parts[1];
        std::string password = parts[2];
        std::string type = parts[3];
        int age = std::stoi(parts[4]);
        double weight = std::stod(parts[5]);
        double height = std::stod(parts[6]);
        Gender gender = stringToGender(parts[7]);
		ActivityLevel level = stringToActivityLevel(parts[8]);        

        UserProfile prof(age, weight, height, gender, level);

        if (type == "Admin") {
            users.push_back(std::make_unique<Admin>(id, username, password, prof));
        }
        else {
            auto trainee = std::make_unique<Trainee>(id,username, password, prof);
            if (parts.size() >= 14) {
                std::string goalStr = parts[9] + "|" + parts[10] + "|" + parts[11] + "|" + parts[12] + "|" + parts[13];
                trainee->setGoals(FitnessGoal::fromFileString(goalStr));
            }
            if (parts.size() >= 15 && !parts[14].empty()) {
                std::istringstream favIss(parts[14]);
                std::string fav;
                while (std::getline(favIss, fav, ',')) {
                    if (!fav.empty()) trainee->addFavoriteExercise(fav);
                }
            }
            users.push_back(std::move(trainee));
        }
    }
    file.close();
}

void Calorix::saveUsers() {
    std::ofstream file(usersFile);
    if (!file.is_open()) return;
    for (const auto& user : users) {
        file << user->toFileString() << "\n";
    }
    file.close();
}

void Calorix::loadFoods() {
    std::ifstream file(foodsFile);
    if (!file.is_open()) return;
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        foods.push_back(Food::fromFileString(line));
    }
    file.close();
}

void Calorix::saveFoods() {
    std::ofstream file(foodsFile);
    if (!file.is_open()) return;
    for (const auto& food : foods) {
        file << food.toFileString() << "\n";
    }
    file.close();
}

void Calorix::loadExercises() {
    std::ifstream file(exercisesFile);
    if (!file.is_open()) return;
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        exercises.push_back(Exercise::fromFileString(line));
    }
    file.close();
}

void Calorix::saveExercises() {
    std::ofstream file(exercisesFile);
    if (!file.is_open()) return;
    for (const auto& exercise : exercises) {
        file << exercise.toFileString() << "\n";
    }
    file.close();
}

void Calorix::loadFoodDiary() {
    std::ifstream file(foodDiaryFile);
    if (!file.is_open()) return;
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> parts;
        while (std::getline(iss, token, '|')) {
            parts.push_back(token);
        }
        if (parts.size() < 5) continue;
        int userId = std::stoi(parts[0]);
        int entryId = std::stoi(parts[1]);
        int foodId = std::stoi(parts[2]);
        double quantity = std::stod(parts[3]);
        std::string date = parts[4];

        Trainee* trainee = nullptr;
        try {
            trainee = findTraineeById(userId);
        }
        catch (const std::runtime_error&) {
            continue;
        }
        const Food* food = findFoodById(foodId);
        if (trainee && food) {
            trainee->addFoodEntry(FoodEntry(entryId, food, quantity, date));
        }
    }
    file.close();
}

void Calorix::saveFoodDiary() {
    std::ofstream file(foodDiaryFile);
    if (!file.is_open()) return;
    for (const auto& user : users) {
        Trainee* trainee = dynamic_cast<Trainee*>(user.get());
        if (!trainee) continue;
        for (const auto& fe : trainee->getFoodDiary()) {
            file << user->getUserId() << "|" << fe.toFileString() << "\n";
        }
    }
    file.close();
}

void Calorix::loadExerciseDiary() {
    std::ifstream file(exerciseDiaryFile);
    if (!file.is_open()) return;
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> parts;
        while (std::getline(iss, token, '|')) {
            parts.push_back(token);
        }
        if (parts.size() < 5) continue;
        int userId = std::stoi(parts[0]);
        int entryId = std::stoi(parts[1]);
        int exerciseId = std::stoi(parts[2]);
        int duration = std::stoi(parts[3]);
        std::string date = parts[4];

        Trainee* trainee = nullptr;
        try {
            trainee = findTraineeById(userId);
        }
        catch (const std::runtime_error&) {
            continue;
        }
        const Exercise* exercise = findExerciseById(exerciseId);
        if (trainee && exercise) {
            trainee->addExerciseEntry(ExerciseEntry(entryId, exercise, duration, date));
        }
    }
    file.close();
}

void Calorix::saveExerciseDiary() {
    std::ofstream file(exerciseDiaryFile);
    if (!file.is_open()) return;
    for (const auto& user : users) {
        Trainee* trainee = dynamic_cast<Trainee*>(user.get());
        if (!trainee) continue;
        for (const auto& ee : trainee->getExerciseDiary()) {
            file << user->getUserId() << "|" << ee.toFileString() << "\n";
        }
    }
    file.close();
}