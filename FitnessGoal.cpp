#include "FitnessGoal.h"
#include <sstream>
#include <vector>

FitnessGoal::FitnessGoal() : goalType(GoalType::MAINTENANCE), targetValue(0), isAchieved(false) {}

FitnessGoal::FitnessGoal(GoalType goalType, double targetValue, const std::string& startDate, const std::string& deadline)
    : goalType(goalType), targetValue(targetValue), startDate(startDate), deadline(deadline), isAchieved(false) {
}

GoalType FitnessGoal::getGoalType() const {
    return goalType;
}
double FitnessGoal::getTargetValue() const {
    return targetValue;
}
std::string FitnessGoal::getStartDate() const {
    return startDate;
}
std::string FitnessGoal::getDeadline() const {
    return deadline;
}
bool FitnessGoal::getIsAchieved() const {
    return isAchieved; 
}

void FitnessGoal::setIsAchieved(bool val) { isAchieved = val; }

std::string FitnessGoal::toFileString() const {
    return goalTypeToString(goalType) + "|" + std::to_string(targetValue) + "|" + startDate + "|" + deadline + "|" + (isAchieved ? "1" : "0");
}

FitnessGoal FitnessGoal::fromFileString(const std::string& str) {
    std::istringstream iss(str);
    std::string token;
    std::vector<std::string> parts;
    while (std::getline(iss, token, '|')) {
        parts.push_back(token);
    }
    if (parts.size() < 5) return FitnessGoal();
    FitnessGoal fitnessGoal(stringToGoalType(parts[0]), std::stod(parts[1]), parts[2], parts[3]);
    fitnessGoal.setIsAchieved(parts[4] == "1");
    return fitnessGoal;
}