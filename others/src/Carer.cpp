//
// Created by LiMXin-PC on 2023/3/30.
//

#include <others//Carer.h>
#include <others//Animal.h>
#include <sstream>

namespace others {

    std::string Carer::care(Animal *a) const {
        std::ostringstream ss;
        a->speak(ss);
        return ss.str();
    }

}
