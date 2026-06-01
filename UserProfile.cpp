#include "UserProfile.h"

UserProfile::UserProfile() 
	: age(0), weight(0), height(0),
	gender(Gender::MALE), activityLevel(ActivityLevel::SEDENTARY) {}

UserProfile::UserProfile(int age, int weight, int height, Gender gender, ActivityLevel activityLevel)
	: age(age), weight(weight), height(height),
	gender(gender), activityLevel(activityLevel) {}

int UserProfile::getAge() const
{
	return age;
}

int UserProfile::getWeight() const
{
	return weight;
}

int UserProfile::getHeight() const
{
	return height;
}

Gender UserProfile::getGender() const
{
	return gender;
}

ActivityLevel UserProfile::getActivityLevel() const
{
	return activityLevel;
}

void UserProfile::setGender(Gender newGender)
{
	gender = newGender;
}

void UserProfile::setActivityLevel(ActivityLevel newActivityLevel)
{
	activityLevel = newActivityLevel;
}
