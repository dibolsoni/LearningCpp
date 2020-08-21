#include <string>
#include <iostream>

namespace String
{
    // replace “red” with “blue”
    void question_one()
    {
        std::string str{ "I saw a red car yesterday." };  

        str.replace(8, 3, "blue");
        
        std::cout << str << '\n'; // I saw a blue car yesterday.
    }
}


