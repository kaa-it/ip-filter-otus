//
// Created by --- on 31.07.2023.
//

#ifndef IP_FILTER_UTILS_H
#define IP_FILTER_UTILS_H

#include <vector>
#include <string>

std::vector<std::string> split(const std::string &str, char d);

std::string join(const std::vector<std::string>& vec, char d);

#endif //IP_FILTER_UTILS_H
