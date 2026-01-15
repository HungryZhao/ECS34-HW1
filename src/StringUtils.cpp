#include "StringUtils.h"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    const ssize_t n = static_cast<ssize_t>(str.size());

    // Pend == 0 -> include end of str
    if (end == 0) {
        end = n;
    }

    // - indices
    if (start < 0) {
        start += n;
    }
    if (end < 0) {
        end += n;
    }

    // [0, n]
    if (start < 0){
        start = 0;
    }
    if (end < 0){
        end = 0;
    }
    if (start > n){
        start = n;
    }
    if (end > n){
        end = n;
    }

    if (end <= start) {
        return "";
    }

    return str.substr(static_cast<size_t>(start), static_cast<size_t>(end - start));
}

std::string Capitalize(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string Upper(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string Lower(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string LStrip(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string RStrip(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string Strip(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    // Replace code here
    return "";
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    // Replace code here
    return {};
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    // Replace code here
    return "";
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    // Replace code here
    return "";
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};