//
// Created by LiMXin-PC on 2023/3/30.
//

#include <others/Animal.h>

namespace others {

    void Cat::speak(std::ostream &os) const {
        os << "Meow~";
    }

    void Dog::speak(std::ostream &os) const {
        os << "Wang!";
    }

}
