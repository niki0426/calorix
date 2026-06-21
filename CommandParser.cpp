#include "CommandParser.h"
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "RegisterCommand.h"
#include "LoginCommand.h"
#include "LogoutCommand.h"
#include "HelpCommand.h"
#include "SetGoalsCommand.h"
#include "LogFoodCommand.h"
#include "LogExerciseCommand.h"
#include "ViewDailySummaryCommand.h"
#include "ViewProgressCommand.h"
#include "CalculateBMICommand.h"
#include "CalculateBMRCommand.h"
#include "GenerateWorkoutPlanCommand.h"
#include "AddToFavoritesCommand.h"
#include "ViewFavoritesCommand.h"
#include "BlockUserCommand.h"
#include "AddFoodCommand.h"
#include "AddExerciseCommand.h"
#include "UpdateFoodCommand.h"
#include "EndCommand.h"

std::unique_ptr<Command> CommandParser::parse(const std::string& input, Calorix& system, bool& running) {
    std::istringstream iss(input);
    std::string cmd;
    iss >> cmd;
    if (cmd.empty()) {
        return nullptr;
    }

    if (cmd == "register") {
        std::string username, password, gender;
        int age;
        double weight, height;
        iss >> username >> password >> age >> weight >> height >> gender;
        if (iss.fail()) {
            throw std::invalid_argument("Error: Invalid arguments for 'register'. Expected: register <username> <password> <age> <weight> <height> <gender>");
        }
        return std::make_unique<RegisterCommand>(system, username, password, age, weight, height, gender);
    }
    else if (cmd == "login") {
        std::string username, password;
        iss >> username >> password;
        if (iss.fail()) {
            throw std::invalid_argument("Error: Invalid arguments for 'login'. Expected: login <username> <password>");
        }
        return std::make_unique<LoginCommand>(system, username, password);
    }
    else if (cmd == "logout") {
        return std::make_unique<LogoutCommand>(system);
    }
    else if (cmd == "help") {
        return std::make_unique<HelpCommand>(system);
    }
    else if (cmd == "end") {
        return std::make_unique<EndCommand>(system, running);
    }
    else if (cmd == "set-goals" || cmd == "log-food" || cmd == "log-exercise" ||
        cmd == "view-daily-summary" || cmd == "view-progress" ||
        cmd == "calculate-bmi" || cmd == "calculate-bmr" ||
        cmd == "generate-workout-plan" || cmd == "add-to-favorites" ||
        cmd == "view-favorites") {

        User* user = system.getCurrentUser();
        if (!user) {
            throw std::invalid_argument("Error: You must be logged in to use this command.");
        }
        Trainee* trainee = dynamic_cast<Trainee*>(user);
        if (!trainee) {
            throw std::invalid_argument("Error: Access denied. This command is only available for Trainees.");
        }

        if (cmd == "set-goals") {
            std::string goalType, deadline;
            double target;
            iss >> goalType >> target >> deadline;
            if (iss.fail()) {
                throw std::invalid_argument("Error: Invalid arguments for 'set-goals'. Expected: set-goals <goal-type> <target-value> <deadline>");
            }
            return std::make_unique<SetGoalsCommand>(system, goalType, target, deadline);
        }
        else if (cmd == "log-food") {
            std::string foodName;
            double quantity;
            iss >> foodName >> quantity;
            if (iss.fail()) {
                throw std::invalid_argument("Error: Invalid arguments for 'log-food'. Expected: log-food <food-name> <quantity_grams>");
            }
            return std::make_unique<LogFoodCommand>(system, foodName, quantity);
        }
        else if (cmd == "log-exercise") {
            std::string exerciseName;
            int duration;
            iss >> exerciseName >> duration;
            if (iss.fail()) {
                throw std::invalid_argument("Error: Invalid arguments for 'log-exercise'. Expected: log-exercise <exercise-name> <duration_minutes>");
            }
            return std::make_unique<LogExerciseCommand>(system, exerciseName, duration);
        }
        else if (cmd == "view-daily-summary") {
            return std::make_unique<ViewDailySummaryCommand>(system);
        }
        else if (cmd == "view-progress") {
            return std::make_unique<ViewProgressCommand>(system);
        }
        else if (cmd == "calculate-bmi") {
            return std::make_unique<CalculateBMICommand>(system);
        }
        else if (cmd == "calculate-bmr") {
            return std::make_unique<CalculateBMRCommand>(system);
        }
        else if (cmd == "generate-workout-plan") {
            int duration;
            iss >> duration;
            if (iss.fail()) {
                throw std::invalid_argument("Error: Invalid arguments for 'generate-workout-plan'. Expected: generate-workout-plan <duration_minutes>");
            }
            return std::make_unique<GenerateWorkoutPlanCommand>(system, duration);
        }
        else if (cmd == "add-to-favorites") {
            std::string exerciseName;
            iss >> exerciseName;
            if (iss.fail()) {
                throw std::invalid_argument("Error: Invalid arguments for 'add-to-favorites'. Expected: add-to-favorites <exercise-name>");
            }
            return std::make_unique<AddToFavoritesCommand>(system, exerciseName);
        }
        else if (cmd == "view-favorites") {
            return std::make_unique<ViewFavoritesCommand>(system);
        }
    }
    else if (cmd == "block-user" || cmd == "add-food" || cmd == "add-exercise" || cmd == "update-food") {
        User* user = system.getCurrentUser();
        if (!user) {
            throw std::invalid_argument("Error: You must be logged in as Admin to use this command.");
        }
        Admin* admin = dynamic_cast<Admin*>(user);
        if (!admin) {
            throw std::invalid_argument("Error: Access denied. Admin rights required.");
        }

        if (cmd == "block-user") {
            std::string username;
            iss >> username;
            if (iss.fail()) {
                throw std::invalid_argument("Error: Invalid arguments for 'block-user'. Expected: block-user <username>");
            }
            return std::make_unique<BlockUserCommand>(system, username);
        }
        else if (cmd == "add-food") {
            std::string name;
            double calories, protein, carbs, fat;
            iss >> name >> calories >> protein >> carbs >> fat;
            if (iss.fail()) {
                throw std::invalid_argument("Error: Invalid arguments for 'add-food'. Expected: add-food <name> <calories> <protein> <carbs> <fat>");
            }
            return std::make_unique<AddFoodCommand>(system, name, calories, protein, carbs, fat);
        }
        else if (cmd == "add-exercise") {
            std::string name, muscleGroup;
            double calories;
            iss >> name >> calories >> muscleGroup;
            if (iss.fail()) {
                throw std::invalid_argument("Error: Invalid arguments for 'add-exercise'. Expected: add-exercise <name> <calories_burned_per_hour> <muscle-group>");
            }
            return std::make_unique<AddExerciseCommand>(system, name, calories, muscleGroup);
        }
        else if (cmd == "update-food") {
            std::string name;
            double calories;
            iss >> name >> calories;
            if (iss.fail()) {
                throw std::invalid_argument("Error: Invalid arguments for 'update-food'. Expected: update-food <food-name> <new-calories>");
            }
            return std::make_unique<UpdateFoodCommand>(system, name, calories);
        }
    }

    throw std::invalid_argument("Error: Unknown command '" + cmd + "'. Type 'help' to see available commands.");
}