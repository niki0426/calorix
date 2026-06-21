#pragma once
#include <string>
#include "Enums.h"

class UserProfile {
private:
    int age;
    double weight;
    double height;
    Gender gender;
    ActivityLevel activityLevel;

public:
    UserProfile();
    UserProfile(int age, double weight, double height, Gender gender, ActivityLevel activityLevel);

    int getAge() const;
    double getWeight() const;
    double getHeight() const;
    Gender getGender() const;
    ActivityLevel getActivityLevel() const;

    void setAge(int age);
    void setWeight(double weight);
    void setHeight(double height);
    void setGender(Gender gender);
    void setActivityLevel(ActivityLevel activityLevel);

    std::string toString() const;
    static UserProfile fromString(const std::string& str);
};
