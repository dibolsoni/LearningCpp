#include <iostream>
#include <iterator>

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
    
    void caller()
    {
        int n{5};
        std::cout << n << '\n';
        changeN(n); //use ref of n to change it
        std::cout << n << '\n';

        int nums[4]{1,2,3,4};
        print_elements(nums);

        reference_as_shortcut();


    }
}