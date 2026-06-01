#include <iostream>
#include "Trainee.h"

void Trainee::help() const
{
    std::cout << "Available commands (Trainee):\n"
        << "  log-food <food-name> <quantity_grams>\n"
        << "  log-exercise <exercise-name> <duration_minutes>\n"
        << "  view-daily-summary\n"
        << "  set-goals <goal-type> <target-value> <deadline>\n"
        << "  view-progress\n"
        << "  calculate-bmi\n"
        << "  calculate-bmr\n"
        << "  generate-workout-plan <duration_minutes>\n"
        << "  add-to-favorites <exercise-name>\n"
        << "  view-favorites\n"
        << "  logout\n"
        << "  help\n";
}

void Trainee::print() const
{
    User::print();
    std::cout << "  Role: Trainee\n"
        << "  Food entries today:     " << foodDiary.size() << "\n"
        << "  Exercise entries today: " << exerciseDiary.size() << "\n";
}

Trainee::Trainee() : User() {}

Trainee::Trainee(const std::string name, const std::string& password, const UserProfile& profile)
    :User(name, password, profile) {}

const std::vector<FoodEntry>& Trainee::getFoodDiary() const
{
    return foodDiary;
}

const std::vector<ExerciseEntry>& Trainee::getExerciseEntry() const
{
    return exerciseDiary;
}

const FitnessGoal& Trainee::getGoals() const
{
    return goals;
}

const std::vector<Exercise> Trainee::getFavoriteExercises() const
{
    return favoriteExercises;
}
