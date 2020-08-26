#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <string_view>

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

        std::cout << "size of int: " << sizeof(value) << '\n';
        std::cout << "size of ref int: " << sizeof(ref) <<'\n';

        //using & on a ref returns an adress of it
        std::cout << &value << '\n';//print adress
        std::cout << &ref << '\n';//print adress
    }

    void changeN(int &ref)
    {
        ref = 6;
    }

    void print_elements(int (&arr)[4])
    {
        int length{ static_cast<int>(std::size(arr) )};

        for (int i{ 0 }; i < length; i++)
            std::cout << arr[i] << '\n';
    }

    void reference_as_shortcut()
    {
        struct Something
        {
            int value1;
            float value2;
        };

        struct Other
        {
            Something something;
            int other_value;
        };

        Other other;

        //using ref to replace other.something.value1;
        int &ref{ other.something.value1 };
        ref = 5;

        std::cout << ref << '\n';
        
    }

    void reference_vs_pointers() 
    {
        //If a given task can be solved with either a reference or a pointer, the reference 
        // should generally be preferred. Pointers should only be used in situations where 
        // references are not sufficient (such as dynamically allocating memory).
        int value { 5 };
        int *const ptr( &value );
        int &ref{ value };

        *ptr = 5;
        // as the same as
        ref = 5;
    }

    void const_references()
    {
        //works as pointers
        //but now u can init const ref with a r-value like:
        int value{ 5 };
        const int& ref_number { 6 };

        const int& ref_value{value};
        value = 6; // okay, value is non-const;
        // ref = 7;// error: ref is const;
    }

/* params as refs:
a) char is a fundamental type, it should be passed by value.

b) std::string has to create a copy of the string whenever it is copied. Pass it by const 
reference.

c) unsigned long is a fundamental type, it should be passed by value.

d) bool is a fundamental type, it should be passed by value.

e) Enumerators (Of enum and enum class) are named integers. They are based on a fundamental 
type (Usually `int`) and should be passed by value.

f) Position is a custom type and should be passed by const reference.

g) Although Player only contains a single int in it’s current state, which would make it fast to pass by value, more members will be added in the future. We don’t want to update every use of Player when that happens, so we pass it by const reference.

h) double is a fundamental type, it should be passed by value.

i) ArrayView only has 2 member variables and no new members will be added in the future. 
The size of ArrayView will be usually be 16 bytes on 64 bit systems. Although this size 
isn’t ideal for the processor, it’s still faster to copy ArrayView than passing it by const 
reference. The type of the array doesn’t matter, because all pointers have the same size. 
This is also how std::string_view works. In that case, ArrayView::array would be a const char*. 
Passing ArrayView by const reference wouldn’t be wrong either, because if in doubt, const 
reference is the way to go. 
*/

    void member_selection()
    {
        struct Person
        {
            int age{};
            double weight{};
        };
        Person person{};
        
        // Member selection using pointer to struct
        Person *ptr{ &person };
        (*ptr).age= 5;
        //as same above but better
        ptr->age = 5;
    }

    void for_each_by_refs()
    {
        //foreach syntax uses ':'
        std::string array[]{ "peter", "likes", "frozen", "yogurt" };
        for(auto element : array)
            std::cout << element << '\n';

        //now using refs (better perfomance because dont copy the element)
        for(auto &element : array)
            std::cout << element << ' ';

        //prefer const foreach for readyonly elements or custom type as struct, objects, classes, etc
        for(const auto &element : array)
            std::cout << element << ' ';

        // int sumArray(const int array[]) // array is a pointer
        // {
        //     int sum{ 0 };
        
        //     for (auto number : array) // compile error, the size of array isn't known
        //     {
        //         sum += number;
        //     }
        
        //     return sum;   
        // };
    }

    void for_each_non_arrays()
    {
        std::vector fibonacci{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 }; // note use of std::vector here rather than a fixed array
        // Before C++17
        // std::vector<int> fibonacci{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    
        for (auto number : fibonacci)
        {
            std::cout << number << ' ';
        }
    
        std::cout << '\n';
    }

    void for_each_with_key_value()
    {
        //only works in C++20+
        std::string names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily" }; // Names of the students
        constexpr int scores[]{ 84, 92, 76, 81, 56 };
        int maxScore{ 0 };
    
        for (int i{ 0 }; auto score : scores) // i is the index of the current element
        {
            if (score > maxScore)
            {
                std::cout << names[i] << " beat the previous best score of " << maxScore << " by " << (score - maxScore) << " points!\n";
                maxScore = score;
            }
            
            ++i;
        }
    
        std::cout << "The best score was " << maxScore << '\n';
    }

    namespace Question_one
    {
        bool hasName()
        {
            constexpr std::string_view names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };
	
            std::cout << "Enter a name: ";
            std::string username{};
            std::cin >> username;
        
            bool found{ false };
        
            for (auto name : names)
            {
                if (name == username)
                {
                    found = true;
                    break;
                }
            }
        
            if (found)
                std::cout << username << " was found.\n";
            else
                std::cout << username << " was not found.\n";
        }

        void caller()
        {
            hasName();
        }
    }
    
    void caller()
    {
        basic();
        int n{5};
        std::cout << n << '\n';
        changeN(n); //use ref of n to change it
        std::cout << n << '\n';

        int nums[4]{1,2,3,4};
        print_elements(nums);

        Question_one::caller();
    }


}