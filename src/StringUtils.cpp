#include "StringUtils.h"
#include <cctype>

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
	if (str.empty()) {
		return "";
	}

	std::string result = str;
	for (size_t i = 0; i < result.size(); ++i) {
		result[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(result[i])));
	}
	result[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(result[0])));
	return result;
}

std::string Upper(const std::string &str) noexcept{
	std::string result = str;
	for (size_t i = 0; i < result.size(); ++i) {
		result[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(result[i])));
	}
	return result;
}

std::string Lower(const std::string &str) noexcept{
	std::string result = str;
	for (size_t i = 0; i < result.size(); ++i) {
		result[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(result[i])));
	}
	return result;
}

std::string LStrip(const std::string &str) noexcept{
    
    
    if (str.empty()) {
        return "";
    }

    size_t i = 0;
    while (i < str.size() && std::isspace(static_cast<unsigned char>(str[i]))) {
        ++i;
    }
    return str.substr(i);
}

std::string RStrip(const std::string &str) noexcept{


    if (str.empty()) {
        return "";
    }

    
    size_t j = str.size();
    while (j > 0 && std::isspace(static_cast<unsigned char>(str[j - 1]))) {
        --j;
    }
    return str.substr(0, j);
}

std::string Strip(const std::string &str) noexcept{
    return RStrip(LStrip(str));
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    const int len = static_cast<int>(str.size());

    if (width <= len) {
        return str;
    }


    std::string result = str;

    const int total_pad = width - len;
    const int left_pad = total_pad / 2;
    const int right_pad = total_pad - left_pad;

    result = std::string(static_cast<size_t>(left_pad), fill) + str + std::string(static_cast<size_t>(right_pad), fill);

    return result;
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    const int len = static_cast<int>(str.size());

    if (width <= len) {
        return str;
    }
    
    std::string result = str;
    const int pad = width - len;
    result += std::string(static_cast<size_t>(pad), fill);
    return result;
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    const int len = static_cast<int>(str.size());

    if (width <= len) {
        return str;
    }

    std::string result = str;
    const int pad = width - len;
    result = std::string(static_cast<size_t>(pad), fill) + str;

    return result;
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    
    if (old.empty()) {
        std::string result;
        result.reserve(str.size() + rep.size() * (str.size() + 1));
        result += rep;


        for (size_t i = 0; i < str.size(); ++i) {
            result += str[i];
            result += rep;
        }
        return result;
    }

    std::string result;
    result.reserve(str.size());

    size_t pos = 0;


    while (true) {
        const size_t found = str.find(old, pos);
        if (found == std::string::npos) {
            result.append(str, pos, std::string::npos);
            break;
        }


        result.append(str, pos, found - pos);
        result += rep;
        pos = found + old.size();
    }
    return result;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    std::vector<std::string> parts;

    if (splt.empty()) {
        size_t i = 0;
        while (i < str.size()) {

            while (i < str.size() && std::isspace(static_cast<unsigned char>(str[i]))) {
                ++i;
            }

            if (i >= str.size()) {
                break;
            }

            const size_t start = i;
            while (i < str.size() && !std::isspace(static_cast<unsigned char>(str[i]))) {
                ++i;
            }
            
            parts.push_back(str.substr(start, i - start));
        }
        return parts;
    }



    size_t pos = 0;
    while (true) {
        const size_t found = str.find(splt, pos);
        if (found == std::string::npos) {


            parts.push_back(str.substr(pos));
            break;
        }
        parts.push_back(str.substr(pos, found - pos));
        pos = found + splt.size();
    }
    return parts;
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    if (vect.empty()) {
        return "";
    }

    std::string result = vect[0];
    for (size_t i = 1; i < vect.size(); ++i) {
        result += str;
        result += vect[i];
    }
    return result;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    if (tabsize <= 0) {
        tabsize = 0;
    }

    std::string result;
    result.reserve(str.size());

    int col = 0;
    for (size_t i = 0; i < str.size(); ++i) {

        const char ch = str[i];
        if (ch == '\t') {
            if (tabsize == 0) {
                continue;
            }



            const int spaces = tabsize - (col % tabsize);

            result.append(static_cast<size_t>(spaces), ' ');
            col += spaces;
            continue;
        }





        result += ch;
        if (ch == '\n' || ch == '\r') {
            col = 0;
        } else {
            ++col;
        }

    }

    return result;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};