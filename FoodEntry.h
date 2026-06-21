#pragma once
#include <string>
#include "Food.h"

class FoodEntry {
private:
    static int nextId;
    int entryId;
    const Food* food;
    double quantityGrams;
    std::string date;

public:
    FoodEntry();
    FoodEntry(const Food* food, double quantityGrams, const std::string& date);
    FoodEntry(int id, const Food* food, double quantityGrams, const std::string& date);

    int getEntryId() const;
    const Food* getFood() const;
    double getQuantityGrams() const;
    std::string getDate() const;

    double getTotalCalories() const;
    double getTotalProtein() const;
    double getTotalCarbs() const;
    double getTotalFat() const;

    std::string toFileString() const;
};
