#pragma once
enum class Gender {
	MALE,
	FEMALE
};
enum class ActivityLevel {
	SEDENTARY, 
	LIGHT,
	MODERATE, 
	ACTIVE, 
	VERY_ACTIVE
};
class UserProfile {
private:
	int age;
	int weight;
	int height;
	Gender gender;
	ActivityLevel activityLevel;
public:
	UserProfile();
	UserProfile(int age, int weight, int height, Gender gender, ActivityLevel activityLevel);
	
	int getAge() const;
	int getWeight() const;
	int getHeight() const;
	Gender getGender() const;
	ActivityLevel getActivityLevel() const;

	void setAge(int newAge);
	void setWeight(int newWeight);
	void setHeight(int newHeight);
	void setGender(Gender newGender);
	void setActivityLevel(ActivityLevel newActivityLevel);

	void print() const;
};
