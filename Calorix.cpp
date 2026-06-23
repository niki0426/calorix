#include <iostream>
#include <string>
#include "Calorix.h"
#include "CommandParser.h"

int main()
{
    try {
        Calorix system;
        system.ensureAdminExists();

        std::cout << "Welcome to Calorix - Fitness & Nutrition Tracking System\n";
        std::cout << "Type 'help' for available commands.\n";

        bool running = true;
        std::string input;

        while (running) {
            std::cout << "- ";
            std::getline(std::cin, input);
            if (input.empty()) continue;

            try {
                auto cmd = CommandParser::parse(input, system, running);
                if (cmd) {
                    cmd->execute();
                }
            }
            catch (const std::runtime_error& e) {
                std::cout << e.what() << "\n";
            }
            catch (const std::exception& e) {
                std::cout << "Unexpected error: " << e.what() << "\n";
            }
        }
    }
    catch (const std::exception& e) {
        std::cout << "Fatal error during startup: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
