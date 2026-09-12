#include "command.hpp"
#include <iostream>
#include <sstream>
#include <vector>

Command parse_input(const std::string& input)
{
    std::string commandType;
    std::string word;
    std::vector<std::string> commands;

    Command cmd;

    std::stringstream ss(input);
    if (ss >> commandType)
    {
        while (ss >> word)
        {
            commands.push_back(word);
        }
    }

    if (commandType == "create")
    {
        cmd = { CREATE, commands};
    }
    else if (commandType == "open")
    {
        cmd = { OPEN, commands };
    }
    else if (commandType == "delete")
    {
        cmd = { DELETE, commands};
    }
    else if (commandType == "rename")
    {
        cmd = { RENAME, commands };
    }
    else if (commandType == "exit")
    {
        cmd = { EXIT, commands };
    }
    else
    {
        cmd = { UNKNOWN, commands};
    }

    return cmd;
}

std::optional<CommandResult> check_command(const Command& cmd)
{
    CommandResult cmdResult;

    switch (cmd.commandType)
    {
    case CREATE:
        if (cmd.commands.size() != 2)
        {
            cmdResult = { INVALID_ARGUMENT_COUNT, cmd };
        }
        else if (cmd.commands[0] != "file" || cmd.commands[0] != "folder")
        {
            cmdResult = { INVALID_ARGUMENT, cmd };
        }
        else{
            cmdResult = { OK, cmd};
        }

        break;
    case OPEN:
        if (cmd.commands.size() != 1)
        {
            cmdResult = { INVALID_ARGUMENT_COUNT, cmd };
        }
        else
        {
            cmdResult = { OK, cmd };
        }

        break;
    case DELETE:
        if (cmd.commands.size() != 1)
        {
            cmdResult = { INVALID_ARGUMENT_COUNT, cmd };
        }
        else
        {
            cmdResult = { OK, cmd };
        }

        break;
    case RENAME:
        if (cmd.commands.size() != 2)
        {
            cmdResult = { INVALID_ARGUMENT_COUNT, cmd };
        }
        else
        {
            cmdResult = { OK, cmd };
        }

        break;
    case EXIT:
        if (cmd.commands.size() != 0)
        {
            cmdResult = { INVALID_ARGUMENT_COUNT, cmd };
        }
        else
        {
            cmdResult = { OK, cmd };
        }

        break;
    default:
        cmdResult = { UNKNOWN_COMMAND, cmd};    

        break;
    }

    return cmdResult;
}

bool handle_command_result(const CommandResult& cmdResult)
{
    switch (cmdResult.status)
    {
    case OK:
        if (execute_command(cmdResult.cmd))
            return true;
        else
            return false;
    case UNKNOWN_COMMAND:
        return true;
    case INVALID_ARGUMENT_COUNT:
        return true;
    case INVALID_ARGUMENT:
        return true;
    default:
        break;
    }
}

bool execute_command(Command cmd)
{
    switch (cmd.commandType)
    {
    case CREATE:
        return true;
    case OPEN:
        return true;
    case DELETE:
        return true;
    case RENAME:
        return true;
    case EXIT:
        return false;
    case UNKNOWN:
        return true;
    default:
        break;
    }
}

bool run_command_cycle()
{
    std::string input;

    std::cout << "> ";
    std::getline(std::cin, input);

    Command cmd = parse_input(input);
    std::optional<CommandResult> cmdResult = check_command(cmd);

    if (handle_command_result(*cmdResult))
        return true;
    else
        return false;
}