#include "lib.h"
#include "utils.h"

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <functional>

using namespace std::literals;

using ip_t = std::vector<std::string>;
using pred_t = std::function<bool (const ip_t&)>;

namespace std {

    std::ostream &operator<<(std::ostream &out, const ip_t &ip) {
        std::for_each(ip.begin(), ip.end(), [&](auto s) {
            out << " "s << s;
        });

        return out;
    }

}

bool sort_ip(const ip_t &ip1, const ip_t &ip2) {
    assert(ip1.size() == ip2.size());

    for (size_t i = 0; i < ip1.size(); i++) {
        auto left = std::stoul(ip1[i]);
        auto right = std::stoul(ip2[i]);
        if (left > right) {
            return true;
        } else if (left < right) {
            return false;
        }
    }

    return false;
}

std::vector<ip_t> filter(const std::vector<ip_t>& pool, pred_t pred)
{
    std::vector<ip_t> res;

    std::copy_if(pool.cbegin(), pool.cend(), std::back_inserter(res), std::move(pred));

    return res;
}

int main(int, char**) {
    std::cout << "Version: " << version() << std::endl;

    try
    {
        std::vector<ip_t> ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            auto v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

        auto out = std::ostream_iterator<std::vector<std::string>>(std::cout, "\n");

        std::sort(ip_pool.begin(), ip_pool.end(), sort_ip);

        std::copy(ip_pool.cbegin(), ip_pool.cend(), out);

        auto ip_by_one = filter(ip_pool, [](const ip_t& ip) {
            return std::stoul(ip[0]) == 1;
        });

        std::copy(ip_by_one.cbegin(), ip_by_one.cend(), out);

        auto ip_by_46_70 = filter(ip_pool, [](const ip_t& ip) {
            return std::stoul(ip[0]) == 46 && std::stoul(ip[1]) == 70;
        });

        std::copy(ip_by_46_70.cbegin(), ip_by_46_70.cend(), out);

        auto ip_with_46 = filter(ip_pool, [](const ip_t& ip) {
           return std::find(ip.cbegin(), ip.cend(), "46") != ip.cend();
        });

        std::copy(ip_with_46.cbegin(), ip_with_46.cend(), out);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
