#include "ExerciseEntry.h"
#include <stdexcept>

int ExerciseEntry::nextEntryId = 1;

ExerciseEntry::ExerciseEntry(const Exercise& exercise, double durationMinutes, const std::string date)
	:entryId(nextEntryId++), exercise(exercise), durationMinutes(durationMinutes), date(date) {}

ExerciseEntry::ExerciseEntry(const ExerciseEntry& otherExerciseEntry)
	:entryId(otherExerciseEntry.entryId), exercise(otherExerciseEntry.exercise), durationMinutes(otherExerciseEntry.durationMinutes), date(otherExerciseEntry.date) {}

ExerciseEntry& ExerciseEntry::operator=(const ExerciseEntry& otherExerciseEntry)
{
	if (this != &otherExerciseEntry)
	{
		if (&exercise != &otherExerciseEntry.exercise)
		{
			throw std::logic_error("Cannot reassing");
		}
		durationMinutes = otherExerciseEntry.durationMinutes;
		date = otherExerciseEntry.date;
	}
}

int ExerciseEntry::getEntryId() const
{
	return entryId;
}

const Exercise& ExerciseEntry::getExercise() const
{
	return exercise;
}

double ExerciseEntry::getDurationMinutes() const
{
	return durationMinutes;
}

const std::string ExerciseEntry::getDate() const
{
	return date;
}
