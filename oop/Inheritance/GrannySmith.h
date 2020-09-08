#ifndef GRANNYSMITH_H
#define GRANNYSMITH_H

#include "Apple.h"

#include <string_view>

class GrannySmith: public Apple
{
public:
    GrannySmith(std::string_view name, std::string_view color, double fiber)
    : Apple{name, color, fiber}
    {}

    inline void print() const {std::cout << "GrannySmith(" << this->getName() << ", " << this->getColor() << ", " << this->getFiber() << ")\n"; }
};



#endif