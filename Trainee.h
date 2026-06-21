#pragma once
#include <vector>
#include <string>
#include "User.h"
#include "FoodEntry.h"
#include "ExerciseEntry.h"
#include "FitnessGoal.h"

class Trainee : public User {
private:
    std::vector<FoodEntry> foodDiary;
    std::vector<ExerciseEntry> exerciseDiary;
    FitnessGoal goals;
    std::vector<std::string> favoriteExercises;

public:
    Trainee(const std::string& username, const std::string& password, const UserProfile& profile);
    Trainee(int id, const std::string& username, const std::string& password, const UserProfile& profile);

    bool isAdmin() const override;
    std::string getType() const override;

    std::vector<FoodEntry>& getFoodDiary();
    std::vector<ExerciseEntry>& getExerciseDiary();
    FitnessGoal& getGoals();
    const FitnessGoal& getGoals() const;
    std::vector<std::string>& getFavoriteExercises();

    void setGoals(const FitnessGoal& goals);

    void addFoodEntry(const FoodEntry& foodEntry);
    void addExerciseEntry(const ExerciseEntry& exerciseEntry);
    void addFavoriteExercise(const std::string& name);

    std::string toFileString() const override;
};
