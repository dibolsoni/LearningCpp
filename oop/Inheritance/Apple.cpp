#include "Apple.h"

#include <iostream>

inline void Apple::print() const 
{
    std::cout << "Apple(" << this->getName() << ", " << this->getColor() << ", " << this->getFiber() << ")\n";
}
