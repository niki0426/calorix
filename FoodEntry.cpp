#include "FoodEntry.h"

int FoodEntry::nextId = 1;

FoodEntry::FoodEntry() : entryId(0), food(nullptr), quantityGrams(0) {}

FoodEntry::FoodEntry(const Food* food, double quantity, const std::string& date)
    : entryId(nextId++), food(food), quantityGrams(quantity), date(date) {
}

FoodEntry::FoodEntry(int id, const Food* food, double quantity, const std::string& date)
    : entryId(id), food(food), quantityGrams(quantity), date(date) {
    if (id >= nextId) nextId = id + 1;
}

int FoodEntry::getEntryId() const {
    return entryId; 
}
const Food* FoodEntry::getFood() const {
    return food; 
}
double FoodEntry::getQuantityGrams() const {
    return quantityGrams; 
}
std::string FoodEntry::getDate() const {
    return date; 
}
double FoodEntry::getTotalCalories() const {
    if (!food) return 0;
    return (food->getCaloriesPer100g() * quantityGrams) / 100.0;
}

double FoodEntry::getTotalProtein() const {
    if (!food) return 0;
    return (food->getProteinPer100g() * quantityGrams) / 100.0;
}

double FoodEntry::getTotalCarbs() const {
    if (!food) return 0;
    return (food->getCarbsPer100g() * quantityGrams) / 100.0;
}

double FoodEntry::getTotalFat() const {
    if (!food) return 0;
    return (food->getFatPer100g() * quantityGrams) / 100.0;
}

std::string FoodEntry::toFileString() const {
    return std::to_string(entryId) + "|" + (food ? std::to_string(food->getFoodId()) : "0") + "|"
        + std::to_string(quantityGrams) + "|" + date;
}