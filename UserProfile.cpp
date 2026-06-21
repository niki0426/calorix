#include "UserProfile.h"
#include <sstream>
#include <vector>

UserProfile::UserProfile()
	: age(0), weight(0), height(0), gender(Gender::MALE), activityLevel(ActivityLevel::SEDENTARY) {
}

UserProfile::UserProfile(int age, double weight, double height, Gender gender, ActivityLevel activityLevel)
	: age(age), weight(weight), height(height), gender(gender), activityLevel(activityLevel) {
}

int UserProfile::getAge() const {
	return age;
}
double UserProfile::getWeight() const {
	return weight;
}
double UserProfile::getHeight() const {
	return height;
}
Gender UserProfile::getGender() const {
	return gender;
}
ActivityLevel UserProfile::getActivityLevel() const {
	return activityLevel;
}

void UserProfile::setAge(int a) {
	age = a; 
}
void UserProfile::setWeight(double w) {
	weight = w; 
}
void UserProfile::setHeight(double h) {
	height = h; 
}
void UserProfile::setGender(Gender g) {
	gender = g; 
}
void UserProfile::setActivityLevel(ActivityLevel al) {
	activityLevel = al; 
}

std::string UserProfile::toString() const {
	return std::to_string(age) + "|" + std::to_string(weight) + "|" + std::to_string(height) + "|"
		+ genderToString(gender) + "|" + activityLevelToString(activityLevel);
}

UserProfile UserProfile::fromString(const std::string& str) {
	std::istringstream iss(str);
	std::string token;
	std::vector<std::string> parts;
	while (std::getline(iss, token, '|')) {
		parts.push_back(token);
	}
	if (parts.size() < 5) return UserProfile();
	return UserProfile(std::stoi(parts[0]), std::stod(parts[1]), std::stod(parts[2]),
		stringToGender(parts[3]), stringToActivityLevel(parts[4]));
}