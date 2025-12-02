

#include "../../include/utils/StringUtils.hpp"


std::string StringUtils::trim(const std::string &str) {

    size_t first = str.find_first_not_of(" \t\n\r");
    if (std::string::npos == first) {
        return "";
    }

    size_t last = str.find_last_not_of(" \t\n\r");

    return str.substr(first, (last - first + 1));
}

std::vector<std::string> StringUtils::split(const std::string &str, char delimiter) {

    std::vector<std::string> elems;

    // we will trim the string Before send it with function
    // std :: string newString = trim(str);
    // int siz = str.length();

    std::string token;

    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] == delimiter) {
            if ((int)token.size())elems.push_back(token);
            token = "";
        }else {
            token += str[i];
        }
    }
    if ((int)token.size()) elems.push_back(token);
    return elems;

}
