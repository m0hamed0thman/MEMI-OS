








#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP
#include "Directory.hpp"
#include "File.hpp"
#include <string>


class FileSystem {
private:

    Directory* root;
    Directory* currentDirectory;
    void saveRecursive(FSNode* node, std::ofstream& file, int level);
    const std::string DISK_PATH = "data/fs_image/systemFile.img";
public:

     FileSystem();
    ~FileSystem();

    void saveState();
    void loadState();

    // read the file and return his content
    std::string readFile(const std::string& name) const;

    // update the file and return the new content
    std::string writeFile(const std::string& name, const std::string& content);

    // Delete all content of the file
    std::string cleanFile(const std::string& name);

    // Rewrite all the content int the file with a new content
    std::string reWriteFile(const std::string& name, const std::string& content);

    std::string ls() const;

    std::string mkdir(const std::string& name);

    std::string touch(const std::string& name);

    std::string cd(const std::string& path);

    std::string pwd() const;
};
#endif

