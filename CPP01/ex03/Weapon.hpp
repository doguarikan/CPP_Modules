#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
    std::string type;

    public:
        std::string &getType();
        void setType(std::string type);
        Weapon(std::string type);
} ;

#endif