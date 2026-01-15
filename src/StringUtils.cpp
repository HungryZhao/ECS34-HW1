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