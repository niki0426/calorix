#include "ExerciseEntry.h"

int ExerciseEntry::nextId = 1;

ExerciseEntry::ExerciseEntry() : entryId(0), exercise(nullptr), durationMinutes(0) {}

ExerciseEntry::ExerciseEntry(const Exercise* exercise, int duration, const std::string& date)
    : entryId(nextId++), exercise(exercise), durationMinutes(duration), date(date) {
}

ExerciseEntry::ExerciseEntry(int id, const Exercise* exercise, int duration, const std::string& date)
    : entryId(id), exercise(exercise), durationMinutes(duration), date(date) {
    if (id >= nextId) nextId = id + 1;
}

int ExerciseEntry::getEntryId() const {
    return entryId; 
}
const Exercise* ExerciseEntry::getExercise() const {
    return exercise; 
}
int ExerciseEntry::getDurationMinutes() const {
    return durationMinutes; 
}
std::string ExerciseEntry::getDate() const {
    return date; 
}
double ExerciseEntry::getBurnedCalories() const {
    if (!exercise) return 0;
    return (exercise->getCaloriesBurnedPerHour() * durationMinutes) / 60.0;
}

std::string ExerciseEntry::toFileString() const {
    return std::to_string(entryId) + "|" + (exercise ? std::to_string(exercise->getExerciseId()) : "0") + "|"
        + std::to_string(durationMinutes) + "|" + date;
}