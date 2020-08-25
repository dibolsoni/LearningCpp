#include <iostream>

namespace References
{
    void basic()
    {
        int value{5};
        int &ref{value}; //reference to a var value

        value = 6;//value is now 6
        // works as a alias of value
        ref = 7;//value is now 7

        std::cout << value << '\n'; //print 7
        ++ref;
        std::cout << value << '\n';//print 8

    }
}