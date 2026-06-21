#pragma once
#include <vector>
#include <memory>
#include <string>
#include "User.h"
#include "Trainee.h"
#include "Admin.h"
#include "Food.h"
#include "Exercise.h"

class Calorix {
private:
    std::vector<std::unique_ptr<User>> users;
    std::vector<Food> foods;
    std::vector<Exercise> exercises;
    User* currentUser;

    const std::string usersFile = "users.txt";
    const std::string foodsFile = "foods.txt";
    const std::string exercisesFile = "exercises.txt";
    const std::string foodDiaryFile = "food_diary.txt";
    const std::string exerciseDiaryFile = "exercise_diary.txt";

public:
    Calorix();
    ~Calorix();

    // CalorixIO.cpp
    void loadData();
    void saveData();

    void loadUsers();
    void saveUsers();
    void loadFoods();
    void saveFoods();
    void loadExercises();
    void saveExercises();
    void loadFoodDiary();
    void saveFoodDiary();
    void loadExerciseDiary();
    void saveExerciseDiary();

    // CalorixUsers.cpp
    User* findUserByUsername(const std::string& username);
    Trainee* findTraineeById(int id);
    const Food* findFoodByName(const std::string& name);
    bool foodExists(const std::string& name) const;
    const Food* findFoodById(int id);
    const Exercise* findExerciseByName(const std::string& name);
    const Exercise* findExerciseById(int id);

    void registerUser(const std::string& username, const std::string& password,
        int age, double weight, double height, const std::string& genderStr);
    void login(const std::string& username, const std::string& password);
    void logout();
    User* getCurrentUser() const;

    void printHelp();
    void ensureAdminExists();

    // CalorixTrainee.cpp
    void setGoals(const std::string& goalTypeStr, double targetValue, const std::string& deadline);
    void logFood(const std::string& foodName, double quantityGrams);
    void logExercise(const std::string& exerciseName, int durationMinutes);
    void viewDailySummary();
    void viewProgress();
    void calculateBMI();
    void calculateBMR();
    void generateWorkoutPlan(int durationMinutes);
    void addToFavorites(const std::string& exerciseName);
    void viewFavorites();

    // CalorixAdmin.cpp
    void blockUser(const std::string& username);
    void addFood(const std::string& name, double calories, double protein, double carbs, double fat);
    void addExercise(const std::string& name, double calPerHour, const std::string& muscleGroupStr);
    void updateFood(const std::string& foodName, double newCalories);

};
