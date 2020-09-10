#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <utility>
 
class Animal
{
protected:
    std::string m_name;
 
    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    // Animal(const std::string& name)
    //     : m_name{ name }
    // {
    // }
 
public:
    // because of pure virtual function speak(), now animal ia abstract class,
    // so the constructor must be public
    Animal(const std::string& name)
        : m_name(name)
    {}


    std::string getName() const { return m_name; }
    // this will allow to create a children without speak setted
    // virtual const char* speak() const { return "???"; }
    // this requires a speak() implementation
    virtual const char* speak() const = 0;
    
    virtual ~Animal() = default;
};

#endif