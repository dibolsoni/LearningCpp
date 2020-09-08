#ifndef APPLE_H
#define APPLE_H

#include "Fruit.h"

#include <string_view>
#include <iostream>

class Apple: public Fruit
{
private:
    const double a_fiber{};
public:
    Apple(std::string_view name, std::string_view color, double fiber)
        : Fruit{name, color}, a_fiber{fiber}
    {}

    inline double getFiber() const {return a_fiber;}

    inline void print() const;

};  

#endif