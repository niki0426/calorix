#include "Exercise.h"
#include <stdexcept>

int Exercise::nextExerciseId = 1;

Exercise::Exercise()
	:name(""), caloriesBurnedPerHour(0), muscleGroup(MuscleGroup::CHEST) {}

Exercise::Exercise(const std::string& name, double caloriesBurnedPerHour, MuscleGroup muscleGroup)
	:exerciseId(nextExerciseId++), name(name), caloriesBurnedPerHour(caloriesBurnedPerHour), muscleGroup(muscleGroup) {}

int Exercise::getExerciseId() const
{
	return exerciseId;
}

const std::string& Exercise::getName() const
{
	return name;
}

double Exercise::getCaloriesBurnedPerHour() const
{
	return caloriesBurnedPerHour;
}

MuscleGroup Exercise::getMuscleGroup() const
{
	return muscleGroup;
}

void Exercise::setName(const std::string newName)
{
	name = newName;
}

void Exercise::setCaloriesBurnedPerHour(double newCaloriesBurnedPerHour)
{
	if (newCaloriesBurnedPerHour < 0) throw std::invalid_argument("Calories cannot be negative");
	caloriesBurnedPerHour = newCaloriesBurnedPerHour;
}

void Exercise::setMuscleGroup(MuscleGroup newMuscleGroup)
{
	muscleGroup = newMuscleGroup;
}

MuscleGroup Exercise::stringToMuscleGroup(const std::string& str)
{
	if (str == "CHEST") return MuscleGroup::CHEST;
	if (str == "BACK") return MuscleGroup::BACK;
	if (str == "SHOULDERS") return MuscleGroup::SHOULDERS;
	if (str == "ARMS") return MuscleGroup::ARMS;
	if (str == "CORE") return MuscleGroup::CORE;
	if (str == "LEGS") return MuscleGroup::LEGS;
	if (str == "CARDIO") return MuscleGroup::CARDIO;

	throw std::invalid_argument("Unknown muscle group");
}

std::string Exercise::muscleGroupToString(MuscleGroup muscleGroup)
{
	switch (muscleGroup)
	{
		case MuscleGroup::CHEST: return "CHEST";
		case MuscleGroup::BACK: return "BACK";
		case MuscleGroup::SHOULDERS: return "SHOULDERS";
		case MuscleGroup::ARMS: return "ARMS";
		case MuscleGroup::CORE: return "CORE";
		case MuscleGroup::LEGS: return "LEGS";
		case MuscleGroup::CARDIO: return "CARDIO";	
	}
	return "Unknown";
}
