








#include "../../../include/fileSystem/Directory.hpp"


Directory::Directory(const std::string &Name, Directory *p):FSNode(Name,p) {
}


void Directory::addChild(FSNode *child) {
    child->setParent(this);
    Children.push_back(child);
}


Directory::~Directory() {
    for (FSNode* child : Children) {
        delete child;
    }
    Children.clear();
}


std::vector<std::string> Directory::listContents() const {
    std::vector<std::string> result;
    for (FSNode* child : Children) {
        result.push_back(child->getName());
    }
    return result;
}


bool Directory::removeChild(const std::string& name) {
    for (auto it = Children.begin(); it != Children.end(); ++it) {
        if ((*it)->getName() == name) {
            delete *it;
            Children.erase(it);
            return true;
        }
    }
    return false;
}


FSNode* Directory::findChild(const std::string& name) const {
    for (FSNode* child : Children) {
        if (child->getName() == name) {
            return child;
        }
    }
    return nullptr;
}

// in future we will design it by recursive way to sum all files size by dfs or bfs
int Directory::getSize() const {
   return  Children.size();
}


std::vector<FSNode *> Directory::nodes() const {
    return Children;
}
