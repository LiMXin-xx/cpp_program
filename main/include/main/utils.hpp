//
// Created by LiMXin-PC on 2023/3/30.
//

#ifndef CPP_PROGRAM_UTILS_HPP
#define CPP_PROGRAM_UTILS_HPP

#pragma once

#include <string>
#include <cctype>

namespace start_main {

    static std::string alluppercase(std::string s) {
        std::string ret;
        for (char c: s) {
            ret.push_back(std::toupper(c));
        }
        return ret;
    }

}


#endif //CPP_PROGRAM_UTILS_HPP
