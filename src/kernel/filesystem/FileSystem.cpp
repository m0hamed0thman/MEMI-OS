

#include "../../../include/fileSystem/FileSystem.hpp"
#include "../../../include/kernel/logging/Logger.hpp"

FileSystem::FileSystem():root(nullptr),currentDirectory(nullptr) {

}

FileSystem::~FileSystem() {
    if (root) {
        delete root;
    }
}

void FileSystem::init() {
    root = new Directory("root",nullptr);
    currentDirectory = root;
}

std::string FileSystem::ls() const {
    std::string result;

    for (std::string  obj : currentDirectory->listContents()) {
        result+=obj;
        result+="\n";
    }
    return result;
}

std::string FileSystem::mkdir(const std::string& name) {

    if (currentDirectory->findChild(name) != nullptr) {
        return "Error: Directory '" + name + "' already exists.";
    }

    Directory* newDir = new Directory(name, currentDirectory);
    currentDirectory->addChild(newDir);
    return "Directory created: " + name;

}

std::string FileSystem::touch(const std::string& name) {

    if (currentDirectory->findChild(name) != nullptr) {
        return "Error: File '" + name + "' already exists.";
    }


    File* newFile = new File(name, currentDirectory);
    currentDirectory->addChild(newFile);
    return "File created: " + name;
}

std::string FileSystem::cd(const std::string& name) {
    if (name == "..") {
        if (currentDirectory->getParent() != nullptr) {
            currentDirectory = currentDirectory->getParent();
            return "Changed directory to ..";
        }
        return "Error: Already at root.";
    }

    FSNode* temp = currentDirectory->findChild(name);

    if (temp == nullptr) {
        return "Error: '" + name + "' does not exist.";
    }


    if (temp->isDirectory()) {
        currentDirectory = static_cast<Directory*>(temp);
        return "Changed directory to " + name;
    } else {
        return "Error: '" + name + "' is a file, not a directory.";
    }
}

std::string getpth(Directory* dir) {
    if (dir == nullptr) {
        return "";
    }
    return getpth(dir->getParent())+'/' + dir->getName();
}
std::string FileSystem::pwd() const {

    Directory* dir = currentDirectory;
    return getpth(dir);

}




