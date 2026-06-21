#include "Enums.h"
#include <stdexcept>
#include <string>

std::string activityLevelToString(ActivityLevel level) {
    switch (level) {
    case ActivityLevel::SEDENTARY: return "SEDENTARY";
    case ActivityLevel::LIGHT: return "LIGHT";
    case ActivityLevel::MODERATE: return "MODERATE";
    case ActivityLevel::ACTIVE: return "ACTIVE";
    case ActivityLevel::VERY_ACTIVE: return "VERY_ACTIVE";
    }
    return "UNKNOWN";
}

ActivityLevel stringToActivityLevel(const std::string& str) {
    if (str == "SEDENTARY") return ActivityLevel::SEDENTARY;
    if (str == "LIGHT") return ActivityLevel::LIGHT;
    if (str == "MODERATE") return ActivityLevel::MODERATE;
    if (str == "ACTIVE") return ActivityLevel::ACTIVE;
    if (str == "VERY_ACTIVE") return ActivityLevel::VERY_ACTIVE;

    throw std::invalid_argument("Error: Invalid activity level '" + str + "'. Expected uppercase: SEDENTARY, LIGHT, MODERATE, ACTIVE, VERY_ACTIVE");
}

std::string genderToString(Gender gender) {
    return (gender == Gender::MALE) ? "MALE" : "FEMALE";
}

Gender stringToGender(const std::string& str) {
    if (str == "MALE") return Gender::MALE;
    if (str == "FEMALE") return Gender::FEMALE;

    throw std::invalid_argument("Error: Invalid gender '" + str + "'. Expected uppercase: MALE, FEMALE");
}

std::string goalTypeToString(GoalType goalType) {
    switch (goalType) {
    case GoalType::WEIGHT_LOSS: return "WEIGHT_LOSS";
    case GoalType::BULKING: return "BULKING";
    case GoalType::MAINTENANCE: return "MAINTENANCE";
    }
    return "UNKNOWN";
}

GoalType stringToGoalType(const std::string& str) {
    if (str == "WEIGHT_LOSS") return GoalType::WEIGHT_LOSS;
    if (str == "BULKING") return GoalType::BULKING;
    if (str == "MAINTENANCE") return GoalType::MAINTENANCE;

    throw std::invalid_argument("Error: Invalid goal type '" + str + "'. Expected uppercase: WEIGHT_LOSS, BULKING, MAINTENANCE");
}

std::string muscleGroupToString(MuscleGroup muscleGroup) {
    switch (muscleGroup) {
    case MuscleGroup::CHEST: return "CHEST";
    case MuscleGroup::BACK: return "BACK";
    case MuscleGroup::LEGS: return "LEGS";
    case MuscleGroup::SHOULDERS: return "SHOULDERS";
    case MuscleGroup::ARMS: return "ARMS";
    case MuscleGroup::CORE: return "CORE";
    case MuscleGroup::CARDIO: return "CARDIO";
    }
    return "UNKNOWN";
}

MuscleGroup stringToMuscleGroup(const std::string& str) {
    if (str == "CHEST") return MuscleGroup::CHEST;
    if (str == "BACK") return MuscleGroup::BACK;
    if (str == "LEGS") return MuscleGroup::LEGS;
    if (str == "SHOULDERS") return MuscleGroup::SHOULDERS;
    if (str == "ARMS") return MuscleGroup::ARMS;
    if (str == "CORE") return MuscleGroup::CORE;
    if (str == "CARDIO") return MuscleGroup::CARDIO;

    throw std::invalid_argument("Error: Invalid muscle group '" + str + "'. Expected uppercase: CHEST, BACK, LEGS, SHOULDERS, ARMS, CORE, CARDIO");
}