#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog: public Animal
{
public:
    Dog(const std::string& name)
        : Animal{ name }
    {
    }
 
    const char* speak() const override { return "Woof"; }
};

#endif