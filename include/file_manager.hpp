#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <string>
#include <vector>

enum FileStatus
{
    SUCCESS,
    NOT_FOUND,
    ALREADY_EXIST,
    PERMISSION_DENIED,
    CANNOT_CREATE,
    UNKNOWN_ERROR
};

FileStatus create_file(const std::string& fileName);
FileStatus create_folder(const std::string& folderName);
FileStatus delete_file(const std::string& fileName);
FileStatus rename_file(const std::string& oldName, const std::string& newName);


#endif