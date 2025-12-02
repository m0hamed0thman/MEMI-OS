#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <string>
#include <vector>

class StringUtils {
public:

    // split the string and return it in string vector
    static std::vector<std::string> split(const std::string& str, char delimiter);

    // remove all spaces from back and front

    static std::string trim(const std::string& str);
};

#endif