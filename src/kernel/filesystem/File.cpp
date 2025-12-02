

#include "../../../include/fileSystem/File.hpp"




File::File(const std::string &Name, Directory *p):FSNode(Name,p){

}

std::string File::read() const {
    return content ;
}

void File::write(const std::string& data) {

    content = data ;
}

void File::append(const std::string& data) {

    content += data;
}

void File::clear() {

    content = "";
}

int File::getSize() const {

    return content.size();
}

