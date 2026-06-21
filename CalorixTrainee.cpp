#include "Calorix.h"
#include "CurrentDate.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

void Calorix::setGoals(const std::string& goalTypeStr, double targetValue, const std::string& deadline) {
    Trainee* trainee = dynamic_cast<Trainee*>(currentUser);
    if (!trainee) {
        std::cout << "Error: Only trainees can set goals.\n";
        return;
    }

    try {
        GoalType goalType = stringToGoalType(goalTypeStr);
        trainee->setGoals(FitnessGoal(goalType, targetValue, currentDate(), deadline));
        std::cout << "Goal set successfully.\n";
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n";
    }
}

void Calorix::logFood(const std::string& foodName, double quantityGrams) {
    Trainee* trainee = dynamic_cast<Trainee*>(currentUser);
    if (!trainee) {
        std::cout << "Error: Only trainees can log food.\n";
        return;
    }

    try {
        const Food* food = findFoodByName(foodName);
        trainee->addFoodEntry(FoodEntry(food, quantityGrams, currentDate()));
        std::cout << "Food logged successfully.\n";
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << "\n";
    }
}

void Calorix::logExercise(const std::string& exerciseName, int durationMinutes) {
    Trainee* trainee = dynamic_cast<Trainee*>(currentUser);
    if (!trainee) {
        std::cout << "Error: Only trainees can log exercise.\n";
        return;
    }

    try {
        const Exercise* exercise = findExerciseByName(exerciseName);
        trainee->addExerciseEntry(ExerciseEntry(exercise, durationMinutes, currentDate()));
        std::cout << "Exercise logged successfully.\n";
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << "\n";
    }
}

void Calorix::viewDailySummary() {
    Trainee* trainee = dynamic_cast<Trainee*>(currentUser);
    if (!trainee) {
        std::cout << "Error: Only trainees can view daily summary.\n";
        return;
    }
    std::string today = currentDate();
    double totalCalories = 0, totalProtein = 0, totalCarbs = 0, totalFat = 0;
    double totalBurned = 0;

    for (const auto& fe : trainee->getFoodDiary()) {
        if (fe.getDate() == today) {
            totalCalories += fe.getTotalCalories();
            totalProtein += fe.getTotalProtein();
            totalCarbs += fe.getTotalCarbs();
            totalFat += fe.getTotalFat();
        }
    }

    for (const auto& ee : trainee->getExerciseDiary()) {
        if (ee.getDate() == today) {
            totalBurned += ee.getBurnedCalories();
        }
    }

    double netBalance = totalCalories - totalBurned;

    std::cout << "=== Daily Summary (" << today << ") ===\n";
    std::cout << "Calories consumed: " << totalCalories << " kcal\n";
    std::cout << "  Protein: " << totalProtein << "g\n";
    std::cout << "  Carbs: " << totalCarbs << "g\n";
    std::cout << "  Fat: " << totalFat << "g\n";
    std::cout << "Calories burned: " << totalBurned << " kcal\n";
    std::cout << "Net balance: " << netBalance << " kcal\n";
}

void Calorix::viewProgress() {
    Trainee* trainee = dynamic_cast<Trainee*>(currentUser);
    if (!trainee) {
        std::cout << "Error: Only trainees can view progress.\n";
        return;
    }
    FitnessGoal& goal = trainee->getGoals();
    if (goal.getTargetValue() == 0) {
        std::cout << "No goals set yet.\n";
        return;
    }
    double currentWeight = trainee->getProfile().getWeight();
    if (goal.getGoalType() == GoalType::WEIGHT_LOSS) {
        double remaining = currentWeight - goal.getTargetValue();
        if (remaining <= 0) {
            std::cout << "Congratulations! You have reached your goal weight!\n";
            goal.setIsAchieved(true);
        }
        else {
            std::cout << "You need to lose " << remaining << " kg more to reach your goal.\n";
        }
    }
    else if (goal.getGoalType() == GoalType::BULKING) {
        double remaining = goal.getTargetValue() - currentWeight;
        if (remaining <= 0) {
            std::cout << "Congratulations! You have reached your goal weight!\n";
            goal.setIsAchieved(true);
        }
        else {
            std::cout << "You need to gain " << remaining << " kg more to reach your goal.\n";
        }
    }
    else {
        std::cout << "Maintenance goal: keep your weight at " << goal.getTargetValue() << " kg.\n";
    }
    std::cout << "Deadline: " << goal.getDeadline() << "\n";
}

void Calorix::calculateBMI() {
    Trainee* trainee = dynamic_cast<Trainee*>(currentUser);
    if (!trainee) {
        std::cout << "Error: Only trainees can calculate BMI.\n";
        return;
    }
    double weight = trainee->getProfile().getWeight();
    double heightM = trainee->getProfile().getHeight() / 100.0;
    double bmi = weight / (heightM * heightM);
    std::cout << "Your BMI is: " << bmi << "\n";
    if (bmi < 18.5) std::cout << "Category: Underweight\n";
    else if (bmi < 25) std::cout << "Category: Normal weight\n";
    else if (bmi < 30) std::cout << "Category: Overweight\n";
    else std::cout << "Category: Obese\n";
}

void Calorix::calculateBMR() {
    Trainee* trainee = dynamic_cast<Trainee*>(currentUser);
    if (!trainee) {
        std::cout << "Error: Only trainees can calculate BMR.\n";
        return;
    }
    double weight = trainee->getProfile().getWeight();
    double height = trainee->getProfile().getHeight();
    int age = trainee->getProfile().getAge();
    Gender gender = trainee->getProfile().getGender();

    double bmr;
    if (gender == Gender::MALE) {
        bmr = 10 * weight + 6.25 * height - 5 * age + 5;
    }
    else {
        bmr = 10 * weight + 6.25 * height - 5 * age - 161;
    }
    std::cout << "Your BMR is: " << bmr << " kcal/day\n";
}

void Calorix::generateWorkoutPlan(int durationMinutes) {
    Trainee* trainee = dynamic_cast<Trainee*>(currentUser);
    if (!trainee) {
        std::cout << "Error: Only trainees can generate workout plans.\n";
        return;
    }
    if (exercises.empty()) {
        std::cout << "No exercises available in database.\n";
        return;
    }

    int n = exercises.size();
    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(durationMinutes + 1, 0));
    std::vector<std::vector<bool>> take(n + 1, std::vector<bool>(durationMinutes + 1, false));

    for (int i = 1; i <= n; ++i) {
        int time = 30;
        double value = (exercises[i - 1].getCaloriesBurnedPerHour() * time) / 60.0;

        for (int w = 0; w <= durationMinutes; ++w) {
            if (time <= w && dp[i - 1][w - time] + value > dp[i - 1][w]) {
                dp[i][w] = dp[i - 1][w - time] + value;
                take[i][w] = true;
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    std::vector<const Exercise*> selected;
    int w = durationMinutes;
    for (int i = n; i >= 1; --i) {
        if (take[i][w]) {
            selected.push_back(&exercises[i - 1]);
            w -= 30;
        }
    }

    std::cout << "=== Workout Plan (" << durationMinutes << " min) ===\n";
    double totalBurned = 0;
    for (auto it = selected.rbegin(); it != selected.rend(); ++it) {
        double burned = ((*it)->getCaloriesBurnedPerHour() * 30) / 60.0;
        totalBurned += burned;
        std::cout << "- " << (*it)->getName() << " (" << muscleGroupToString((*it)->getMuscleGroup())
            << ") - 30 min - " << burned << " kcal\n";
    }
    std::cout << "Total estimated burn: " << totalBurned << " kcal\n";
}

void Calorix::addToFavorites(const std::string& exerciseName) {
    Trainee* trainee = dynamic_cast<Trainee*>(currentUser);
    if (!trainee) {
        std::cout << "Error: Only trainees can add favorites.\n";
        return;
    }

    try {
        findExerciseByName(exerciseName);
        trainee->addFavoriteExercise(exerciseName);
        std::cout << "Added to favorites.\n";
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << "\n";
    }
}

void Calorix::viewFavorites() {
    Trainee* trainee = dynamic_cast<Trainee*>(currentUser);
    if (!trainee) {
        std::cout << "Error: Only trainees can view favorites.\n";
        return;
    }
    std::cout << "=== Favorite Exercises ===\n";
    for (const auto& fav : trainee->getFavoriteExercises()) {
        std::cout << "- " << fav << "\n";
    }
}