#include "file_manager.hpp"
#include "app_state.hpp"
#include <filesystem>
#include <system_error>
#include <fstream>

namespace fs = std::filesystem;

FileStatus create_file(const std::string& fileName)
{
    fs::path path = fs::path(get_path()) / fileName;
    std::error_code ec;

    bool exists = fs::exists(path, ec);

    if (ec)
    {
        if (ec == std::errc::permission_denied)
        {
            return PERMISSION_DENIED;
        }

        return UNKNOWN_ERROR;
    }

    if (exists)
    {
        return ALREADY_EXIST;
    }

    std::ofstream file(path);

    exists = fs::exists(path, ec);
    if (!exists)
    {
        return CANNOT_CREATE;
    }

    return SUCCESS;
}

FileStatus create_folder(const std::string& folderName)
{

}

FileStatus delete_file(const std::string& fileName)
{

}

FileStatus rename_file(const std::string& oldName, const std::string& newName)
{

}