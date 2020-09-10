#ifndef COW_H
#define COW_H

#include "Animal.h"

class Cow: public Animal
{
public:
    Cow(const std::string& name)
        : Animal(name)
    {
    }
 
    const char* speak() const override { return "Moo"; }
};


#endif