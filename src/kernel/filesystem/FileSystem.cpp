








#include "../../../include/fileSystem/FileSystem.hpp"

#include <iostream>

#include "../../../include/kernel/logging/Logger.hpp"


FileSystem::FileSystem(){
    root = new Directory("root",nullptr);
    currentDirectory = root;
}


FileSystem::~FileSystem() {
    if (root) {
        delete root;
    }
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


std::string getPath(Directory* dir) {
    if (dir == nullptr) {
        return "";
    }
    return getPath(dir->getParent())+'/' + dir->getName();
}


std::string FileSystem::pwd() const {
    Directory* dir = currentDirectory;
    return getPath(dir);

}


std::string FileSystem::readFile(const std::string &name) const {
    FSNode* temp = currentDirectory->findChild(name);
    if (temp == nullptr) {
        return "Error: File '" + name + "' does not exist.";
    }else if (temp->isDirectory()) {
        return "Error: File '" + name + "' is a directory.";
    }
    File* file = static_cast<File*>(temp);
    return file->read();
}


std::string FileSystem::writeFile(const std::string &name, const std::string& content) {
    FSNode* temp = currentDirectory->findChild(name);
    if (temp == nullptr) {
        return "Error: File '" + name + "' does not exist.";
    }else if (temp->isDirectory()) {
        return "Error: File '" + name + "' is a directory.";
    }
    File* file = static_cast<File*>(temp);
    file->append(content);
    return file->read();
}


std::string FileSystem::cleanFile(const std::string &name) {
    FSNode* temp = currentDirectory->findChild(name);
    if (temp == nullptr) {
        return "Error: File '" + name + "' does not exist.";
    }else if (temp->isDirectory()) {
        return "Error: File '" + name + "' is a directory.";
    }
    File* file = static_cast<File*>(temp);
    file->clear();
    return "File is Clear Now: " + name;
}


std::string FileSystem::reWriteFile(const std::string &name, const std::string& content) {
    FSNode* temp = currentDirectory->findChild(name);
    if (temp == nullptr) {
        return "Error: File '" + name + "' does not exist.";
    }else if (temp->isDirectory()) {
        return "Error: File '" + name + "' is a directory.";
    }
    File* file = static_cast<File*>(temp);
    file->write(content);
    return file->read();
}


void FileSystem::saveState() {
    std::ofstream file(DISK_PATH);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open disk image for saving.\n";
        return;
    }
    if (root) {
        saveRecursive(root, file, 0);
    }
    file.close();
    std::cout << "System state saved to " << DISK_PATH << "\n";
}


void FileSystem::saveRecursive(FSNode* node, std::ofstream& file, int level) {
    std::string indent(level * 4, ' ');
    if (node->isDirectory()) {
        file << indent << "D " << node->getName() << " {\n";
        Directory* dir = static_cast<Directory*>(node);
        for (auto child : dir->nodes()) {
            saveRecursive(child, file, level + 1);
        }
        file << indent << "}\n";
    } else {
        File* f = static_cast<File*>(node);
        file << indent << "F " << f->getName() << " \"" << f->read() << "\"\n";
    }
}

