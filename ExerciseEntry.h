#pragma once
#include "Exercise.h"

class ExerciseEntry {
private:
	static int nextEntryId;
	int entryId;
	const Exercise& exercise;
	double durationMinutes;
	std::string date;
public:
	ExerciseEntry(const Exercise& exercise, double durationMinutes, const std::string date);

	ExerciseEntry(const ExerciseEntry& otherExerciseEntry);
	ExerciseEntry& operator =(const ExerciseEntry& otherExerciseEntry);

	int getEntryId() const;
	const Exercise& getExercise() const;
	double getDurationMinutes() const;
	const std::string getDate() const;
};
