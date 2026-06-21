#include "Trainee.h"
#include <algorithm>

Trainee::Trainee(const std::string& username, const std::string& password, const UserProfile& profile)
	: User(username, password, profile) {
}
Trainee::Trainee(int id, const std::string& username, const std::string& password, const UserProfile& profile)
	: User(username, password, profile) {
}
bool Trainee::isAdmin() const {
	return false; 
}
std::string Trainee::getType() const {
	return "Trainee"; 
}
std::vector<FoodEntry>& Trainee::getFoodDiary() {
	return foodDiary; 
}
std::vector<ExerciseEntry>& Trainee::getExerciseDiary() {
	return exerciseDiary; 
}
FitnessGoal& Trainee::getGoals() {
	return goals; 
}
const FitnessGoal& Trainee::getGoals() const {
	return goals; 
}
std::vector<std::string>& Trainee::getFavoriteExercises() {
	return favoriteExercises; 
}
void Trainee::setGoals(const FitnessGoal& goal) {
	goals = goal; 
}
void Trainee::addFoodEntry(const FoodEntry& foodEntry) {
	foodDiary.push_back(foodEntry); 
}
void Trainee::addExerciseEntry(const ExerciseEntry& exerciseEntry) {
	exerciseDiary.push_back(exerciseEntry); 
}

void Trainee::addFavoriteExercise(const std::string& name) {
	if (std::find(favoriteExercises.begin(), favoriteExercises.end(), name) == favoriteExercises.end()) {
		favoriteExercises.push_back(name);
	}
}
std::string Trainee::toFileString() const {
	std::string base = User::toFileString();
	std::string goalStr = goals.toFileString();
	std::string favStr;
	for (size_t i = 0; i < favoriteExercises.size(); ++i) {
		if (i > 0) favStr += ",";
		favStr += favoriteExercises[i];
	}
	return base + "|" + goalStr + "|" + favStr;
}