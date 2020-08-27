#include "effolkronium/random.hpp"
#include <iostream>
#include <array>
#include <algorithm> //std::sort
#include <iterator> //std::size
#include <cstring> // for strcpy


namespace ArraySample
{
    void question_one()
    {
        unsigned const int DAYS{365};
        float days_temp[DAYS]{};
        using Random = effolkronium::random_static;

        for(unsigned int i{1}; i <= DAYS; i++)
        {
            days_temp[i] = Random::get(-20.0, 40.0);
        };

        std::sort(std::begin(days_temp), std::end(days_temp));
        
        for (int day{ 1 }; day <= DAYS; ++day)
        {
            std::cout << days_temp[day] << '\t' << '\t' << '\t' << '\t';
    
            // If we've printed 5 numbers, start a new row
            if (day % 3 == 0)
                std::cout << '\n';
        }
    }

    namespace ANIMAL
    {
        enum name
        {
            chicken,
            dog,
            cat,
            elephant, 
            duck,
            snake,
            max_animals
        }; 
    }

    void question_two()
    {


        int animal_legs[ANIMAL::max_animals]{};
        int size = sizeof(animal_legs) / sizeof(animal_legs[0]);

        for(unsigned int count{0}; count < size; count++)
        {
            std::cout << count;
            switch (count)
            {
            case ANIMAL::duck:
            case ANIMAL::chicken:
                animal_legs[count] = 2;
                break;
            
            case ANIMAL::elephant:
            case ANIMAL::cat:
            case ANIMAL::dog:
                animal_legs[count] = 4;
                break;

            default:
                animal_legs[count] = 0;
                break;
            }

        }

        std::cout << "The animal has " << animal_legs[ANIMAL::elephant] << "\n";
        std::cout << "The animal has " << animal_legs[ANIMAL::snake] << "\n";

    }

    void copy_array()
    {
        char source[]{ "Copy this" }; //c-style string
        char dest[10]; // note that the length of dest is only 5 chars!
        strcpy(dest, source); // A runtime error will occur in debug mode
        std::cout << dest << '\n';
    }

    void allocate_dynamic_array()
    {
        std::cout << "enter a positive integer" << "\n";
        std::size_t length{};
        std::cin >> length;
    
        // use array new.  Note that length does not need to be constant!
        int *array{ new int[length]{} }; 
    
        std::cout << "I just allocated an array of integers of length " << length << '\n';
    
        array[0] = 5; // set element 0 to value 5
    
        delete[] array; // use array delete to deallocate array
    
        // we don't need to set array to nullptr/0 here because it's going to go out of scope 
        // immediately after this anyway

        //The length of dynamically allocated arrays has to be a type that’s 
        //convertible to std::size_t
        std::cout << "enter a positive integer" << "\n";
        int length2{};
        std::cin >> length2;
        int *array2{ new int[static_cast<std::size_t>(length2)]{} };

        delete[] array2;
    }

    void dynamic_sorted_list()
    {
        int max_names{};
        std::cout << "how many name do you want to store? " << "\n";
        std::cin >> max_names;

        // Ignore the line feed that was left by std::cin.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //pointer names to a new created string with casted max_names size
        std::string* names{
            new std::string[std::size_t(max_names)]{}
        };

        for (int i{0}; i < max_names; i++)
        {
            std::cout << "Enter name #" << i+1 << "\n";
            std::getline(std::cin, names[i]);
        }

        std::cout << names[1];

    }

    void two_dimensional_array()
    {
        int array[10][5];
        // int **array = new int*[10]; //dynamic allocate 10 int pointers
        // int **array = new int[10][5]; //wont work
        int (*array2)[5] = new int[10][5]; //works
        auto array3 = new int[10][5]; //better syntax! because will be a pointer so uses auto
    }

    void std_array()
    {
        std::array<int, 5> myArray{ 9, 7, 5, 3, 1 }; //must declare the length
        // c++17
        std::array myArray2{3,2,1,4,5}; //deduced to std::array<int, 5>

        myArray[10] = 3; // works as basic array, dont check the length
        // myArray.at(10) = 3; // better, because checks if is valid, if not throw an error

        std::cout << "length: " << myArray.size() << '\n';
        for (int element : myArray)
            std::cout << element << ' ';

        std::cout << '\n';

        std::sort(myArray.begin(), myArray.end()); // sort the array forwards

        for (int element : myArray)
            std::cout << element << ' ';
 
        std::cout << '\n';

        std::cout << "itinarator with an index \n";
        //the int itinarator in std::array is size_t, so the for must use size_t
        for (std::size_t i{ 0 }; i < myArray.size(); ++i)
            std::cout << i << "-" << myArray[i] << ' ';
        std::cout << '\n';

        

    }

    namespace StructArray
    {
        struct House
        {
            int number{};
            int stories{};
            int rooms_per_story{};
        };

        //to make a cleaner syntax
        struct Houses
        {
            House houses2[3]{};
        };

        void caller()
        {
            std::array<House, 3> houses{};

            houses[0] = { 13, 4, 30 };
            houses[1] = { 14, 3, 10 };
            houses[2] = { 15, 3, 40 };
        
            for (const auto& house : houses)
            {
                std::cout   << "House number "  << house.number
                            << " has "          << (house.stories * house.rooms_per_story)
                            << " rooms\n";
            };

            //to make a cleaner syntax on init
            // must use double {{}} because Houses is a two_dimensional_array
            Houses array{{
                {13, 4, 20},
                { 14, 3, 10 },
                { 15, 3, 40 }
            }};
            
            for (const auto& house : array.houses2)
            {
                std::cout   << "House number "  << house.number
                            << " has "          << (house.stories * house.rooms_per_story)
                            << " rooms\n";
            };
        }
    }

    namespace STD_Algorithms
    {
        void finder()
        {
            std::array arr{ 13, 90, 99, 5, 40, 80 };
 
            std::cout << "Enter a value to search for and replace with: ";  
            int search{};
            int replace{};
            std::cin >> search >> replace;
            
            // Input validation omitted
            
            // std::find returns an iterator pointing to the found element (or the end of the container)
            // we'll store it in a variable, using type inference to deduce the type of
            // the iterator (since we don't care)
            auto found{ std::find(arr.begin(), arr.end(), search) };
            
            // Algorithms that don't find what they were looking for return the end iterator.
            // We can access it by using the end() member function.
            if (found == arr.end())
            {
                std::cout << "Could not find " << search << '\n';
            }
            else
            {
                // Override the found element.
                *found = replace;
            }
            
            for (int i : arr)
            {
                std::cout << i << ' ';
            }
            
            std::cout << '\n';
        }

        bool contains(std::string_view array)
        {
            std::string_view item{"apple"};
            // std::string_view::find returns std::string_view::npos if it doesn't find
            // the substring. Otherwise it returns the index where the substring occurs
            // in str.
            return (array.find(item) != std::string_view::npos);
        }
    
        void find_if()
        {
            std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };
             // Scan our array to see if any elements contains using a callback function
            auto found{ std::find_if(arr.begin(), arr.end(), contains) };            
            if (found == arr.end())
                std::cout << "No nuts\n";
            else
                std::cout << "Found " << *found << '\n';
        }

        void count_if()
        {
            std::array<std::string_view, 5> arr{ "apple", "banana", "walnut", "lemon", "apple" };
            auto apples{ std::count_if(arr.begin(), arr.end(), contains) };
            std::cout << "Counted " << apples << " apple(s)\n";
        }

        bool greater(int a, int b)
        {
            // Order @a before @b if @a is greater than @b.
            return (a > b);
        }
        
        void sort_custom()
        {
            std::array arr{ 13, 90, 99, 5, 40, 80 };
 
            // Pass greater to std::sort
            // callback functions gets 2 params compared in greater(int,int)
            std::sort(arr.begin(), arr.end(), greater);
            
            for (int i : arr)
            {
                std::cout << i << ' ';
            }
            
            std::cout << '\n';
        }

        void double_number(int &i)
        {
            i *= 2;
        }

        void for_each()
        {
            std::array arr{1, 2, 3, 4};

            //using a callback function with a ref to change the itinarator value
            std::for_each(arr.begin(), arr.end(), double_number);
            // std::ranges::for_each(arr, doubleNumber); // Since C++20, we don't have to use begin() and end().

            for (int i : arr)
                std::cout << i << " ";

            std::cout << '\n';
        }
        
        void caller()
        {
            // finder();
            // find_if();
            // count_if();
            // sort_custom();
            for_each();
        }
    }

}