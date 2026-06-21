#pragma once
#include <string>
#include "Enums.h"

class Exercise {
private:
    static int nextId;
    int exerciseId;
    std::string name;
    double caloriesBurnedPerHour;
    MuscleGroup muscleGroup;

public:
    Exercise();
    Exercise(const std::string& name, double caloriesBurnedPerHour, MuscleGroup muscleGroup);
    Exercise(int id, const std::string& name, double caloriesBurnedPerHour, MuscleGroup muscleGroup);

    int getExerciseId() const;
    std::string getName() const;
    double getCaloriesBurnedPerHour() const;
    MuscleGroup getMuscleGroup() const;

    std::string toFileString() const;
    static Exercise fromFileString(const std::string& str);
};
