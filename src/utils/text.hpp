#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>

/** Transform usigned character array to a string
 * 
 * @param a     character array to transform
*/
inline std::string to_string(const unsigned char* a) {
    return std::string( reinterpret_cast< char const* >(a) );
}

/** Return as string striped of starting and end quotes
 * 
 * @param text      text to check
 * @return          string between the first and last quote
*/
inline std::string strip_quotes(const std::string& text) {
    int a = text.find("'") + 1;
    int b = text.find_last_of("'");
    return text.substr(a, b-a);
}

/** Count number of quotes in a string
 * 
 * @param text      text to check
 * @return          number of quotes
*/
inline int count_quotes(const std::string& text) {
    return std::count(text.begin(), text.end(), '\'');
}

/** Strip new line characters from a string
 * 
 * @param text      string to filter
 * @return          string without new line characters
*/
inline std::string strip(std::string text) {
    text.erase(std::remove_if(text.begin(), text.end(),
    [](char& c) {
        return (c == '\n' || c == '\r');
    }), text.end());
    return text;
}

/** Split a string by a delimiter
 * 
 * @param str       copy of the original string
 * @param delim     delimiter to split by
 * @return          vector with split parts
*/
inline std::vector<std::string> split(std::string str, std::string delim) {
    size_t pos_start = 0, pos_end, delim_len = delim.length();
    std::string token;
    std::vector<std::string> result;

    while ((pos_end = str.find(delim, pos_start)) != std::string::npos) {
        token = str.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        result.push_back(token);
    }
    result.push_back(str.substr(pos_start));
    return result;
}
