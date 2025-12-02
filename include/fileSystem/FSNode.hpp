#ifndef FSNODE_HPP
#define FSNODE_HPP

#include <string>


class Directory;
class FSNode {
protected:
    std::string name;
    Directory* parent; /* to get my father folder */

public:
    FSNode(std::string Name, Directory* p = nullptr) : name(Name), parent(p) {}

    // if we deleted the parent then it will delete all children
    // Becareful from memory leck
    virtual ~FSNode() = default;


    std::string getName() const { return name; }
    Directory* getParent() const { return parent; }
    void setParent(Directory* p) { parent = p; }


    // Don't look at me, look at my child! (I have no implementation, they do)
    virtual bool isDirectory() const = 0;
    virtual int getSize() const = 0;
};

#endif