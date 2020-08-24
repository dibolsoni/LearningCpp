#include "effolkronium/random.hpp"
#include <iostream>
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
}