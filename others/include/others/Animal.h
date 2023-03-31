//
// Created by LiMXin-PC on 2023/3/30.
//

#ifndef CPP_PROGRAM_ANIMAL_H
#define CPP_PROGRAM_ANIMAL_H
#pragma once
#include<ostream>

namespace others {
    struct Animal {
        virtual void speak(std::ostream &os) const = 0;

        virtual ~Animal() = default;
    };
    struct Cat : Animal {
        virtual void speak(std::ostream &os) const override;
    };
    struct Dog :  Animal {
        virtual void speak(std::ostream &os) const override;
    };
}


#endif //CPP_PROGRAM_ANIMAL_H
