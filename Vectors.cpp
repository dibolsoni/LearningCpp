#include <iostream>

namespace Vectors 
{
    static int called{0};
    void printLength(const std::vector<int>& array)
    {
        std::cout << "Called:" << called++ << ". The length is: " << array.size() << '\n';
    }
    
    // vectors works as arrays but owns its memory management.
    // so it is more dynamic
    void basic()
    {
        // as with std::array, the type can be omitted since C++17
        std::vector array { 9, 7, 5, 3, 1 }; // deduced to std::vector<int, 5>
        array = { 9, 8, 7 }; // okay, array length is now 3
        printLength(array);
        array = { 0, 1, 2, 3, 4 }; // okay, array length is now 5
        printLength(array);
        array.resize(3); // okay, array length is now 3
        printLength(array);


        std::vector<int> array2{};
        array2 = { 0, 1, 2, 3, 4 }; // okay, array2 length = 5
        std::cout << "length: " << array2.size() << "  capacity: " << array2.capacity() << '\n';
        
        array2 = { 9, 8, 7 }; // okay, array2 length is now 3!
        std::cout << "length: " << array2.size() << "  capacity: " << array2.capacity() << '\n';
      
    }


    void caller()
    {
        std::cout << "vectors!" << "\n";

        basic();
    }
}