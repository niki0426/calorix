#pragma once
#include <string>
#include "Exercise.h"

class ExerciseEntry {
private:
    static int nextId;
    int entryId;
    const Exercise* exercise;
    int durationMinutes;
    std::string date;

public:
    ExerciseEntry();
    ExerciseEntry(const Exercise* exercise, int durationMinutes, const std::string& date);
    ExerciseEntry(int id, const Exercise* exercise, int durationMinutes, const std::string& date);

    int getEntryId() const;
    const Exercise* getExercise() const;
    int getDurationMinutes() const;
    std::string getDate() const;

    double getBurnedCalories() const;

    std::string toFileString() const;
};
