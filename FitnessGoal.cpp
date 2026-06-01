#include "FitnessGoal.h"
#include <stdexcept>

FitnessGoal::FitnessGoal()
	: goalType(GoalType::BULKING), targetValue(0), startDate(""), deadline(""), isAchieved(0) {}

FitnessGoal::FitnessGoal(GoalType goalType, double targetValue, const std::string& startDate, const std::string& deadline, bool isAchieved)
	: goalType(goalType), targetValue(targetValue), startDate(startDate), deadline(deadline), isAchieved(isAchieved) {}

GoalType FitnessGoal::getGoalType() const
{
	return goalType;
}

double FitnessGoal::getTardetValue() const
{
	return targetValue;
}

const std::string& FitnessGoal::getStartDate() const
{
	return startDate;
}

const std::string& FitnessGoal::getDeadline() const
{
	return deadline;
}

bool FitnessGoal::getIsAchieved() const
{
	return isAchieved;
}

void FitnessGoal::setGoalType(GoalType newGoalType)
{
	goalType = newGoalType;
}

void FitnessGoal::setTargetValue(double newTargetValue)
{
	targetValue = newTargetValue;
}

void FitnessGoal::setStartDate(const std::string& newStartDate)
{
	startDate = newStartDate;
}

void FitnessGoal::setIsAchieved(bool newIsAchieved)
{
	isAchieved = newIsAchieved;
}

GoalType FitnessGoal::stringToGoalType(const std::string& str)
{
	if (str == "BULKING") return GoalType::BULKING;
	if (str == "MAINTENANCE") return GoalType::MAINTENANCE;
	if (str == "WEIGHT_LOSS") return GoalType::WEIGHT_LOSS;
	throw std::invalid_argument("Unknown goal type");
}

std::string FitnessGoal::goalTypeToString(GoalType gt)
{
	switch (gt)
	{
		case GoalType::BULKING: return "BULKING";
		case GoalType::MAINTENANCE: return "MAINTENANCE";
		case GoalType::WEIGHT_LOSS: return "WEIGHT_LOSS";
	}
	return "Unknown";
}
