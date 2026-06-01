#pragma once
#include "Food.h"

class FoodEntry {
private:
	static int nextEntryId;
	int entryId;
	const Food& food;
	double quantityGrams;
	std::string date;
public:
	FoodEntry(const Food& food, double quantityGrams, const std::string&  date);

	FoodEntry(const FoodEntry& otherFood);
	FoodEntry& operator = (const FoodEntry& otherFood);

	int getEntryId() const;
	const Food& getFood() const;
	double getQuantityGrams() const;
	const std::string& getDate() const;
};
