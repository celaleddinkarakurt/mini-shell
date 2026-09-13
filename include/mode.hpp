#ifndef MODE_HPP
#define MODE_HPP

#include "editor.hpp"
#include "image_viewer.hpp"
#include <variant>

enum class ModeType
{
    COMMAND,
    EDITOR,
    IMAGE
};

struct Mode
{
    ModeType type;
    std::variant<std::monostate, Editor, Image> data;
};

#endif