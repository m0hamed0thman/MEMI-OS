
#ifndef
#include "../../include/fileSystem/FSNode.hpp"

class Directory;
class File : public FSNode {
protected:
    std :: string content;
    public:

    File(const std::string & Name, Directory* p = nullptr);

    std::string read()const;
    void write(const std::string& data);
    void append(const std::string& data);
    void clear();

    bool isDirectory() const override{return false;} ;
    int getSize() const override ;
};