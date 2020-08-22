#include <string>
#include <iostream>
#include <string_view>


namespace String
{
    // replace “red” with “blue”
    void question_one()
    {
        std::string str{ "I saw a red car yesterday." };  

        str.replace(8, 3, "blue");
        
        std::cout << str << '\n'; // I saw a blue car yesterday.
    }

    void string_view()
    {
        std::string_view str{ "Trains are fast!" }; // is stored in the binary and ptr to it
 
        std::cout << str.length() << '\n'; // 16 
        std::cout << str.substr(0, str.find(' ')) << '\n'; // Trains
        std::cout << (str == "Trains are fast!") << '\n'; // 1
        
        // Since C++20
        std::cout << str.starts_with("Boats") << '\n'; // 0
        std::cout << str.ends_with("fast!") << '\n'; // 1
        
        std::cout << str << '\n'; // Trains are fast!
    }
}


