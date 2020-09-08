#include "Apple.h"
#include "Apple.cpp"
#include "GrannySmith.h"


#include <iostream>
#include <string_view>

int main()
{
    const Apple a{ "Red delicious", "red", 4.2 };
	a.print();
    GrannySmith c{"Granny Smith", "green", 4.3};
	// const Banana b{ "Cavendish", "yellow" };
	// std::cout << b << '\n';

    a.print();
	c.print();

    return 0;
}
