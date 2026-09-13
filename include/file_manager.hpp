#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <string>
#include <vector>

enum FileStatus
{
    SUCCESS,
    NOT_FOUND,
    ALREADY_EXISTS,
    PERMISSION_DENIED,
    CANNOT_CREATE,
    UNKNOWN_ERROR
};

FileStatus create_file(const std::string& fileName);
FileStatus create_folder(const std::string& folderName);
FileStatus delete_path(const std::string& pathName);
FileStatus rename_path(const std::string& oldName, const std::string& newName);


#endif