#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <vector>

enum CommandTypes
{
    CREATE,
    OPEN,
    DELETE,
    RENAME,
    IMAGE,
    EXIT,
    UNKNOWN
};

enum CommandStatus
{
    OK,
    UNKNOWN_COMMAND,
    INVALID_ARGUMENT_COUNT,
    INVALID_ARGUMENT
};

typedef struct
{
    CommandTypes commandType;
    std::vector<std::string> commands;
} Command;

typedef struct 
{
    CommandStatus status;
    Command cmd;
} CommandResult;


Command parse_input(const std::string& input);
CommandResult check_command(const Command& cmd);
bool handle_command_result(const CommandResult& cmdResult);
bool execute_command(const Command& cmd);
bool run_command_cycle();

#endif