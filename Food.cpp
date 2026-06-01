#include "Food.h"
#include <stdexcept>
#include <iostream>

int Food::nextFoodId = 1;

Food::Food() 
	: foodId(nextFoodId++), name(""), caloriesPer100g(0), proteinPer100g(0), carbsPer100g(0), fatPer100g(0) {}

Food::Food(const std::string name, double caloriesPer100g, double proteinPer100g, double carbsPer100g, double fatPer100g)
	: foodId(nextFoodId++), name(name), caloriesPer100g(caloriesPer100g), proteinPer100g(proteinPer100g), carbsPer100g(carbsPer100g), fatPer100g(fatPer100g) {}

int Food::getFoodId() const
{
	return foodId;
}

const std::string& Food::getName() const
{
	return name;
}

double Food::getCaloriesPer100g() const
{
	return caloriesPer100g;
}

double Food::getProteinPer100g() const
{
	return proteinPer100g;
}

double Food::getCarbsPer100g() const
{
	return carbsPer100g;
}

double Food::getFatPer100g() const
{
	return fatPer100g;
}

void Food::setName(const std::string& newName)
{
	name = newName;
}

void Food::setCaloriesPer100g(double newCaloriesPer100g)
{
	if (newCaloriesPer100g < 0) throw std::invalid_argument("Calories cannot be negative");
	caloriesPer100g = newCaloriesPer100g;
}

void Food::setProteinPer100g(double newProteinPer100g)
{
	if (newProteinPer100g < 0) throw std::invalid_argument("Protein cannot be negative");
	proteinPer100g = newProteinPer100g;
}

void Food::setCarbsPer100g(double newCarbsPer100g)
{
	if (newCarbsPer100g< 0) throw std::invalid_argument("Carbs cannot be negative");
	carbsPer100g = newCarbsPer100g;
}

void Food::setFatPer100g(double newFatPer100g)
{
	if (newFatPer100g < 0) throw std::invalid_argument("Fat cannot be negative");
	fatPer100g = newFatPer100g;
}

void Food::print() const
{
	std::cout << "Id: " << foodId << " Name: " << name 
		<< " Calories: " << caloriesPer100g << " g Protein: " << proteinPer100g << " g Carbs: " << carbsPer100g << " g Fat: " << fatPer100g;
}
