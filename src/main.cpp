#include <iostream>
#include <optional>
#include "command.hpp"

int main(void)
{
    std::cout << "\x1b[3J\x1b[2J\x1b[H" << std::flush;

    bool running = true;
    while (running)
    {
        running = run_command_cycle();
    }
    
    return 0;
}