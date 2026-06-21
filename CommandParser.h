#pragma once
#include <memory>
#include <string>
#include "Command.h"
#include "Calorix.h"

class CommandParser {
public:
    static std::unique_ptr<Command> parse(const std::string& input, Calorix& system, bool& running);
};
