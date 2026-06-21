#include "Food.h"
#include <sstream>
#include <vector>

int Food::nextId = 1;

Food::Food() : foodId(0), caloriesPer100g(0), proteinPer100g(0), carbsPer100g(0), fatPer100g(0) {}

Food::Food(const std::string& name, double calories, double protein, double carbs, double fat)
    : foodId(nextId++), name(name), caloriesPer100g(calories), proteinPer100g(protein), carbsPer100g(carbs), fatPer100g(fat) {
}

Food::Food(int id, const std::string& name, double calories, double protein, double carbs, double fat)
    : foodId(id), name(name), caloriesPer100g(calories), proteinPer100g(protein), carbsPer100g(carbs), fatPer100g(fat) {
    if (id >= nextId) nextId = id + 1;
}

int Food::getFoodId() const {
    return foodId; 
}
std::string Food::getName() const {
    return name; 
}
double Food::getCaloriesPer100g() const {
    return caloriesPer100g; 
}
double Food::getProteinPer100g() const {
    return proteinPer100g; 
}
double Food::getCarbsPer100g() const {
    return carbsPer100g; 
}
double Food::getFatPer100g() const {
    return fatPer100g; 
}

void Food::setCaloriesPer100g(double calories) {
    caloriesPer100g = calories; 
}

std::string Food::toFileString() const {
    return std::to_string(foodId) + "|" + name + "|" + std::to_string(caloriesPer100g) + "|"
        + std::to_string(proteinPer100g) + "|" + std::to_string(carbsPer100g) + "|" + std::to_string(fatPer100g);
}

Food Food::fromFileString(const std::string& str) {
    std::istringstream iss(str);
    std::string token;
    std::vector<std::string> parts;
    while (std::getline(iss, token, '|')) {
        parts.push_back(token);
    }
    if (parts.size() < 6) return Food();
    return Food(std::stoi(parts[0]), parts[1], std::stod(parts[2]), std::stod(parts[3]), std::stod(parts[4]), std::stod(parts[5]));
}