#pragma once
#include <string>

class Food {
private:
    static int nextId;
    int foodId;
    std::string name;
    double caloriesPer100g;
    double proteinPer100g;
    double carbsPer100g;
    double fatPer100g;

public:
    Food();
    Food(const std::string& name, double caloriesPer100g, double proteinPer100g, double carbsPer100g, double fatPer100g);
    Food(int id, const std::string& name, double caloriesPer100g, double proteinPer100g, double carbsPer100g, double fatPer100g);

    int getFoodId() const;
    std::string getName() const;
    double getCaloriesPer100g() const;
    double getProteinPer100g() const;
    double getCarbsPer100g() const;
    double getFatPer100g() const;

    void setCaloriesPer100g(double c);

    std::string toFileString() const;
    static Food fromFileString(const std::string& str);
};
