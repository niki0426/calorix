#pragma once
#include "User.h"
#include "FoodEntry.h"
#include "ExerciseEntry.h"
#include "FitnessGoal.h"
#include <vector>

class Trainee: public User {
private:
	std::vector<FoodEntry> foodDiary;
	std::vector<ExerciseEntry> exerciseDiary;
	FitnessGoal goals;
	std::vector<Exercise> favoriteExercises;
public:
	Trainee();
	Trainee(const std::string name, const std::string& password, const UserProfile& profile);

	const std::vector<FoodEntry>& getFoodDiary() const;
	const std::vector<ExerciseEntry>& getExerciseEntry() const;
	const FitnessGoal& getGoals() const;
	const std::vector<Exercise> getFavoriteExercises() const;

	void setGoals(GoalType goalType, double targetValue, const std::string& startDate, const std::string& deadline);

	void logFood(const Food& food, double quantityGrams);
	void logExercise(const Exercise& exercise, double durationMinutes);

	void viewDailySummary();
	void viewProgress();

	double calculateBMI() const;
	double calculateBMR() const;
	void generateWorkoutPlan(double durationMinutes, const std::vector<Exercise*>& allExercises) const;
	void addToFavorites(Exercise* exercise);
	void viewFavorites();

	void help() const override;
	void print() const override;


};
