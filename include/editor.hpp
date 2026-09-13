#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <string>
#include <vector>

struct Cursor
{
    size_t row;
    size_t col;    
};

struct Editor
{
    Cursor cursor;
    std::vector<std::string> buffer;
};

#endif