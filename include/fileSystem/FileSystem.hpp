#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include "Directory.hpp"
#include "File.hpp"
#include <string>

class FileSystem {
private:
    Directory* root;
    Directory* currentDirectory;

public:

    FileSystem();
    ~FileSystem();

    // Initialization
    // void init();


    std::string ls() const;


    std::string mkdir(const std::string& name);


    std::string touch(const std::string& name);


    std::string cd(const std::string& path);


    std::string pwd() const;
};

#endif