#ifndef CAT_H
#define CAT_H

#include "Animal.h"


class Cat: public Animal
{
public:
    Cat(const std::string& name)
        : Animal{ name }
    {
    }
 
    const char* speak() const override { return "Meow"; }
};


#endif