#ifndef FRUIT_H
#define FRUIT_H

#include <string_view>

class Fruit
{
private:
    std::string_view f_name{};
    std::string_view f_color{};

public:
    Fruit(std::string_view name, std::string_view color)
        : f_name{name}, f_color{color}
    {}

    inline std::string_view getName() const {return this->f_name;}
    inline std::string_view getColor() const {return this->f_color;}


};

#endif