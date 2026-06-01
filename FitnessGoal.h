#pragma once
#include <string>
enum class GoalType {
	WEIGHT_LOSS,
	BULKING,
	MAINTENANCE
};
class FitnessGoal {
private:
	GoalType goalType;
	double targetValue;
	std::string startDate;
	std::string deadline;
	bool isAchieved;
public:
	FitnessGoal();
	FitnessGoal(GoalType goalType, double targetValue, const std::string& startDate, const std::string& deadline, bool isAchieved);

	GoalType getGoalType() const;
	double getTardetValue() const;
	const std::string& getStartDate() const;
	const std::string& getDeadline() const;
	bool getIsAchieved() const;

	void setGoalType(GoalType newGoalType);
	void setTargetValue(double newTargetValue);
	void setStartDate(const std::string& newStartDate);
	void setStartDate(const std::string& newDeadline);
	void setIsAchieved(bool newIsAchieved);

	static GoalType stringToGoalType(const std::string& str);
	static std::string goalTypeToString(GoalType gt);
};
