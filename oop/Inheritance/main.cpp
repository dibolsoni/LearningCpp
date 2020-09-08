#include "Apple.h"
#include "Apple.cpp"


#include <iostream>
#include <string_view>

int main()
{
    const Apple a{ "Red delicious", "red", 4.2 };
	a.print();
 
	// const Banana b{ "Cavendish", "yellow" };
	// std::cout << b << '\n';

    return 0;
}
