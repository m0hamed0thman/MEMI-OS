








#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP
#include <vector>
#include <string>
#include "FSNode.hpp"

class Directory : public FSNode {
protected:
    std :: vector <FSNode*> Children;
public:

    Directory(const std::string & Name, Directory *p);
    ~Directory();

    FSNode* findChild(const std::string& name) const ;

    bool removeChild(const std::string& name);

    void addChild(FSNode * child);

    std :: vector <std::string> listContents()const;

    std :: vector <FSNode*> nodes()const;

    bool isDirectory() const override{return true;} ;
    int getSize() const override ;
};
#endif

