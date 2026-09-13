#include "command.hpp"
#include "file_manager.hpp"
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
    else if (commandType == "image")
    {
        cmd = { IMAGE, commands };
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

CommandResult check_command(const Command& cmd)
{
    CommandResult cmdResult;

    switch (cmd.commandType)
    {
    case CREATE:
        if (cmd.commands.size() != 2)
        {
            cmdResult = { INVALID_ARGUMENT_COUNT, cmd };
        }
        else if (cmd.commands[0] != "file" && cmd.commands[0] != "folder")
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
    case IMAGE:
        if (cmd.commands.size() != 1)
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
        return execute_command(cmdResult.cmd);
    case UNKNOWN_COMMAND:
        std::cout << "Unknown command.\n";
        return true;
    case INVALID_ARGUMENT_COUNT:
        std::cout << "Invalid argument count: " << cmdResult.cmd.commands.size() << '\n';
        return true;
    case INVALID_ARGUMENT:
        std::cout << "Invalid argument: '" << cmdResult.cmd.commands[0] << "'\n";
        return true;
    default:
        return true;;
    }
}

bool execute_command(const Command& cmd)
{
    FileStatus result;

    switch (cmd.commandType)
    {
    case CREATE:
        if (cmd.commands[0] == "file")
        {
            result = create_file(cmd.commands[1]);
        }
        else if (cmd.commands[0] == "folder")
        {
            result = create_folder(cmd.commands[1]);
        }

        switch (result)
        {
        case SUCCESS:
            std::cout << "Successfully created!\n";
            break;
        case ALREADY_EXISTS:
            std::cout << "'" << cmd.commands[1] << "' is already exists.\n";
            break;
        case PERMISSION_DENIED:
            std::cout << "Permission denied.\n";
            break;
        case CANNOT_CREATE:
            std::cout << "'" << cmd.commands[1] <<"' is cannot created.\n";
            break;
        default:
            std::cout << "An error occured.\n";
            break;
        }

        return true;
    case OPEN:
        return true;
    case DELETE:
        result = delete_path(cmd.commands[0]);

        switch (result)
        {
        case SUCCESS:
            std::cout << "Successfully deleted!\n";
            break;
        case NOT_FOUND:
            std::cout << "'" << cmd.commands[0] << "' is not found.\n";
            break;
        case PERMISSION_DENIED:
            std::cout << "Permission denied.\n";
            break;
        default:
            std::cout << "An error occured.\n";
            break;
        }

        return true;
    case RENAME:
        result = rename_path(cmd.commands[0], cmd.commands[1]);

        switch (result)
        {
        case SUCCESS:
            std::cout << "Successfully changed!\n";
            break;
        case NOT_FOUND:
            std::cout << "'" << cmd.commands[0] << "' is not found.\n";
            break;
        case ALREADY_EXISTS:
            std::cout << "'" << cmd.commands[1] << "' is already exists.\n";
            break;
        case PERMISSION_DENIED:
            std::cout << "Permission denied.\n";
            break;
        default:
            std::cout << "An error occured.\n";
            break;
        }

        return true;
    case IMAGE:
            

        return true;
    case EXIT:
        return false;
    default:
        return true;
    }
}

bool run_command_cycle()
{
    std::string input;

    std::cout << "irm> ";
    std::getline(std::cin, input);

    Command cmd = parse_input(input);
    CommandResult cmdResult = check_command(cmd);

    return handle_command_result(cmdResult);
}