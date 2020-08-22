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
}