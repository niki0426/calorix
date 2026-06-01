#pragma once
#include <string>
enum class MuscleGroup {
	CHEST,
	BACK,
	SHOULDERS,
	ARMS,
	CORE,
	LEGS,
	CARDIO
};

class Exercise {
private:
	static int nextExerciseId;
	int exerciseId;
	std::string name;
	double caloriesBurnedPerHour;
	MuscleGroup muscleGroup;
public:
	Exercise();
	Exercise(const std::string& name, double caloriesBurnedPerHour, MuscleGroup muscleGroup);

	int getExerciseId() const;
	const std::string& getName() const;
	double getCaloriesBurnedPerHour() const;
	MuscleGroup getMuscleGroup() const;

	void setName(const std::string newName);
	void setCaloriesBurnedPerHour(double newCaloriesBurnedPerHour);
	void setMuscleGroup(MuscleGroup newMuscleGroup);

	static MuscleGroup stringToMuscleGroup(const std::string& str);
	static std::string muscleGroupToString(MuscleGroup muscleGroup);
};
