#include <iostream>
#include <iterator> // for std::begin and std::end
#include <cstddef> // for std::nullptr_t
#include <algorithm> // count_if, begin, end
// best pratice

// When declaring a pointer variable, put the asterisk next to the variable name.
// int *num;

// When declaring a function, put the asterisk of a pointer return value next to the type.
// int* doSomething();

// nullptr_t => is used to set params from a function => void doSome(std::nullptr_t pointer)

namespace Pointers
{
    void print_address_and_value()
    {
        int x{ 5 };
        // int *ptr{ 5 }; error: cant covert prt of int to int
        std::cout << x << '\n';
        std::cout << &x << '\n';
        std::cout << *(&x) << '\n';
        int value{ 5 };

        std::cout << &value; // prints address of value
        std::cout << value; // prints contents of value
        
        int *ptr{ &value }; // ptr points to value
        std::cout << ptr; // prints address held in ptr, which is &value
        std::cout << *ptr; // dereference ptr (get the value that ptr is pointing to)

        int value2{ 45 };
        int *ptr2{ &value2 }; // declare a pointer and initialize with address of value
        // *ptr = &value; // error:So this line says, “retrieve the value that ptr is 
        // pointing to (an integer), and overwrite it with the address of value (an address).

        //pointer of pointer
        int *ptr_x{&x};
        int **ptr_ptr_x{&ptr_x};
        std::cout << *ptr_ptr_x << '\n';
        std::cout << **ptr_ptr_x << '\n'; // first dereference to get pointer to int, second dereference to get int value
    }

    void deferencing_an_array()
    {
        int array[5]{ 9, 7, 5, 3, 1 };
 
        // dereferencing an array returns the first element (element 0)
        std::cout << *array; // will print 9!
        
        char name[]{ "Jason" }; // C-style string (also an array)
        std::cout << *name << '\n'; // will print 'J'
    }

    void arithmetic_on_pointers()
    {
        // Note that ptr + 1 does not return the memory address after ptr, but the 
        // memory address of the next object of the type that ptr points to.
        int value{ 7 };
        int *ptr{ &value };

        std::cout << ptr << '\n';
        std::cout << *ptr+1 << '\n';
        std::cout << *ptr+2 << '\n';
        std::cout << *ptr+3 << '\n';

        // array works as same
        int array []{ 9, 7, 5, 3, 1 };
 
        std::cout << &array[1] << '\n'; // print memory address of array element 1
        std::cout << array+1 << '\n'; // print memory address of array pointer + 1 
        // array[n] is the same as *(array + n), where n is an integer
        std::cout << array[1] << '\n'; // prints 7
        std::cout << *(array+1) << '\n'; // prints 7 (note the parenthesis required here)
    }

    bool isVowel(char ch)
    {
        switch (ch)
        {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            return true;
        default:
            return false;
        }
    }

    void getVowels()
    {
        char text[]{"Decebe"};

        int arrayLength{ static_cast<int>(sizeof(text) / sizeof(text[0])) };
        int numVowels{ 0 };
        
        for (char *ptr{ text }; ptr < (text + arrayLength); ++ptr)
        {
            if (isVowel(*ptr))
            {
            ++numVowels;
            }
        }
        std::cout << text << " has " << numVowels << " vowels.\n";

        // using count_if
        auto numVowels2{ 
            std::count_if(
                std::begin(text), 
                std::end(text), 
                isVowel
            ) 
        };        
        std::cout << text << " has " << numVowels2 << " vowels.\n";
    }

    void itinarating_an_array()
    {
        int arr[]{ 1,2,3 };

        std::cout << 2[arr] << '\n';
        //as same as
        std::cout << *(arr + 2) << '\n';
        //and
        std::cout << *(2 + arr) << '\n';

    }

    namespace Question_two
    {
        int *find(int *begin, int *end, int target)
        {
            while (end != begin)
            {
                if(*begin++ == target)
                {
                    return begin;
                }
            }
            return end;   
            
        }
        int caller()
        {
            int arr[] { 2, 5, 4, 10, 8, 20, 16, 40 };
            //search 
            int *found { find(std::begin(arr), std::end(arr), 230) };
            if (found != std::end(arr))
                std::cout << "founded at " << found << "\n";
            else
                std::cout <<  "not found " << "\n";
        }
    }

    void c_style_pointers()
    {
        int nArray[5]{ 9, 7, 5, 3, 1 };
        char cArray[]{ "Hello!" };
        const char *name{ "Alex" };
    
        std::cout << nArray << '\n'; // nArray will decay to type int*
        std::cout << cArray << '\n'; // cArray will decay to type char*
        std::cout << name << '\n'; // name is already type char*

        char c{ 'Q' }; //PRINTED Q╠╠╠╠╜╡4;¿■A   
        // Well, it assumed &c (which has type char*) was a string. So it printed the ‘Q’, and 
        // then kept going. Next in memory was a bunch of garbage. 
        std::cout << &c;
    }

    void const_pointers()
    {
        const int number{5};
        // int *ptr_number{number} //compile error: must be const also
        const int *ptr_number{&number}; //ok
        int n{5};
        const int *ptr_n{&n};//still ok, the ptr will point as a const
        n = 2;//ok
        //*ptr_n = 3// error: pointer is a const
    }

    namespace VoidPointers
    {
        enum class Type
        {
            INT,
            FLOAT,
            CSTRING
        };

        void print_value(void *ptr, Type type)
        {
            switch (type)
            {
            case Type::INT:
                std::cout << *static_cast<int*>(ptr) << "\n";
                break;
            case Type::FLOAT:
                std::cout << *static_cast<float*>(ptr) << "\n";;
                break;
            case Type::CSTRING:
            // std::cout knows to treat char* as a C-style string
            // if we were to dereference the result, then we'd just 
            // print the single char that ptr is pointing to
                std::cout << static_cast<char*>(ptr) << "\n";
                break;
            
            };
        }

        void caller()
        {
            int nValue{ 5 };
            float fValue{ 7.5f };
            char szValue[]{ "Mollie" };

            print_value(&nValue, Type::INT);
            print_value(&fValue, Type::FLOAT);
            print_value(szValue, Type::CSTRING);
        }
    }

    


}