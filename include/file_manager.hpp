#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <string>
#include <vector>

void create_file(const std::string& fileName);
std::vector<std::string> open_file(const std::string& fileName);
void delete_file(const std::string& fileName);
void rename_file(const std::string& oldName, const std::string& newName);

#endif