








#ifndef FILE_HPP
#define FILE_HPP
#include <string>
#include "FSNode.hpp"

class Directory;
class File : public FSNode {
private:
    std :: string content;
public:

    File(const std::string & Name, Directory* p = nullptr);

    std::string read()const;
    // change the content of file
    void write(const std::string& data);
    // add one line in the file
    void append(const std::string& data);
    // clear file data
    void clear();

    bool isDirectory() const override{return false;}

    int getSize() const override ;
};
#endif

