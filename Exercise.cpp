#include "Exercise.h"
#include <sstream>
#include <vector>

int Exercise::nextId = 1;

Exercise::Exercise() : exerciseId(0), caloriesBurnedPerHour(0), muscleGroup(MuscleGroup::CARDIO) {}

Exercise::Exercise(const std::string& name, double calPerHour, MuscleGroup muscleGroup)
    : exerciseId(nextId++), name(name), caloriesBurnedPerHour(calPerHour), muscleGroup(muscleGroup) {
}

Exercise::Exercise(int id, const std::string& name, double calPerHour, MuscleGroup muscleGroup)
    : exerciseId(id), name(name), caloriesBurnedPerHour(calPerHour), muscleGroup(muscleGroup) {
    if (id >= nextId) nextId = id + 1;
}

int Exercise::getExerciseId() const {
    return exerciseId; 
}
std::string Exercise::getName() const {
    return name; 
}
double Exercise::getCaloriesBurnedPerHour() const {
    return caloriesBurnedPerHour; 
}
MuscleGroup Exercise::getMuscleGroup() const {
    return muscleGroup; 
}

std::string Exercise::toFileString() const {
    return std::to_string(exerciseId) + "|" + name + "|" + std::to_string(caloriesBurnedPerHour) + "|" + muscleGroupToString(muscleGroup);
}

Exercise Exercise::fromFileString(const std::string& str) {
    std::istringstream iss(str);
    std::string token;
    std::vector<std::string> parts;
    while (std::getline(iss, token, '|')) {
        parts.push_back(token);
    }
    if (parts.size() < 4) return Exercise();
    return Exercise(std::stoi(parts[0]), parts[1], std::stod(parts[2]), stringToMuscleGroup(parts[3]));
}