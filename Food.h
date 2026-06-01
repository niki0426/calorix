#pragma once
#include <string>

class Food {
private:
	static int nextFoodId;

	int foodId;
	std::string name;
	double caloriesPer100g;
	double proteinPer100g;
	double carbsPer100g;
	double fatPer100g;
public:
	Food();
	Food(const std::string name, double caloriesPer100g, double proteinPer100g, double carbsPer100g, double fatPer100g);

	int getFoodId() const;
	const std::string& getName() const;
	double getCaloriesPer100g() const;
	double getProteinPer100g() const;
	double getCarbsPer100g() const;
	double getFatPer100g() const;

	void setName(const std::string& newName);
	void setCaloriesPer100g(double newCaloriesPer100g);
	void setProteinPer100g(double newProteinPer100g);
	void setCarbsPer100g(double newCarbsPer100g);
	void setFatPer100g(double newFatPer100g);

	void print() const;
};
