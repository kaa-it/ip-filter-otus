//
// Created by --- on 31.07.2023.
//

#include "utils.h"

#include <sstream>

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

std::string join(const std::vector<std::string>& vec, char d)
{
    std::ostringstream out;
    size_t size = vec.size();

    for (auto i = 0; i < size; i++) {
        out << vec[i];

        if (i != size - 1 && !vec[i].empty()) {
            out << d;
        }
    }

    return out.str();
}