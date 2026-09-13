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
    CANNOT_OPEN,
    UNKNOWN_ERROR
};

typedef struct 
{
    FileStatus status;
    std::vector<std::string> content;
} FileReadResult;


FileStatus create_file(const std::string& fileName);
FileStatus create_folder(const std::string& folderName);
FileStatus delete_path(const std::string& pathName);
FileStatus rename_path(const std::string& oldName, const std::string& newName);
FileReadResult read_file(const std::string& fileName);

#endif