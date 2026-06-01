#include "FoodEntry.h"
#include <stdexcept>

int FoodEntry::nextEntryId = 1;

FoodEntry::FoodEntry(const Food& food, double quantityGrams, const std::string& date)
	:entryId(nextEntryId++), food(food), quantityGrams(quantityGrams), date(date) {}

FoodEntry::FoodEntry(const FoodEntry& otherFood)
	:entryId(otherFood.entryId), food(otherFood.food), quantityGrams(otherFood.quantityGrams), date(otherFood.date) {}

FoodEntry& FoodEntry::operator=(const FoodEntry& otherFood)
{
	if (this != &otherFood)
	{
		if (&food != &otherFood.food)
		{
			throw std::logic_error("Cannot reassing");
		}
		quantityGrams = otherFood.quantityGrams;
		date = otherFood.date;
	}
	return *this;
}

int FoodEntry::getEntryId() const
{
	return entryId;
}

const Food& FoodEntry::getFood() const
{
	return food;
}

double FoodEntry::getQuantityGrams() const
{
	return quantityGrams;
}

const std::string& FoodEntry::getDate() const
{
	return date;
}
