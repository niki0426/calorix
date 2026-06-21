#pragma once
#include <string>

enum class ActivityLevel {
    SEDENTARY,
    LIGHT,
    MODERATE,
    ACTIVE,
    VERY_ACTIVE
};

enum class Gender {
    MALE,
    FEMALE
};

enum class GoalType {
    WEIGHT_LOSS,
    BULKING,
    MAINTENANCE
};

enum class MuscleGroup {
    CHEST,
    BACK,
    LEGS,
    SHOULDERS,
    ARMS,
    CORE,
    CARDIO
};

std::string activityLevelToString(ActivityLevel level);
ActivityLevel stringToActivityLevel(const std::string& str);

std::string genderToString(Gender gender);
Gender stringToGender(const std::string& str);

std::string goalTypeToString(GoalType goalType);
GoalType stringToGoalType(const std::string& str);

std::string muscleGroupToString(MuscleGroup muscleGroup);
MuscleGroup stringToMuscleGroup(const std::string& str);
