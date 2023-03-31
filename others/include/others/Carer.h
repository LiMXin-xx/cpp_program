//
// Created by LiMXin-PC on 2023/3/30.
//

#ifndef CPP_PROGRAM_CARER_H
#define CPP_PROGRAM_CARER_H
#pragma once

#include <string>

namespace others {

    struct Animal;

    struct Carer {
        std::string care(Animal *a) const;
    };

}

#endif //CPP_PROGRAM_CARER_H
