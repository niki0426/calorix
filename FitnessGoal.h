#pragma once
#include <string>
#include "Enums.h"

class FitnessGoal {
private:
    GoalType goalType;
    double targetValue;
    std::string startDate;
    std::string deadline;
    bool isAchieved;

public:
    FitnessGoal();
    FitnessGoal(GoalType goalType, double targetValue, const std::string& startDate, const std::string& deadline);

    GoalType getGoalType() const;
    double getTargetValue() const;
    std::string getStartDate() const;
    std::string getDeadline() const;
    bool getIsAchieved() const;

    void setIsAchieved(bool value);

    std::string toFileString() const;
    static FitnessGoal fromFileString(const std::string& str);
};
