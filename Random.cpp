#include "effolkronium/random.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

//#define DEBUG

namespace Random
{
    unsigned int PRNG()
    {
        // our initial starting seed is 5323
        static  unsigned int seed{ 5223 };

        // Take the current seed and generate a new value from it
        // Due to our use of large constants and overflow, it would be
        // hard for someone to casually predict what the next number is
        // going to be from the previous one.
        seed = 8253729 * seed + 2396403;
        #ifdef DEBUG
            std::cout << "print inside PRNG " << seed << "\n";
        #endif
    
        // Take the seed andreturn a value between 0 and 32767
        return seed % 32768;
    }

    void PRNG_Caller()
    {
        for(int count{1}; count <= 100; ++count)
        {
            std::cout << PRNG() << "\t";

            //if we've printed 5 numbers, start new row
            if (count % 5 == 0)
                std::cout << "\n";
        }
    }

    void libRandom()
    {
        std::srand(5323); // set initial seed value to 5323
    
        // Print 100 random numbers
        for (int count{ 1 }; count <= 100; ++count)
        {
            std::cout << std::rand() << '\t';
    
            // If we've printed 5 numbers, start a new row
            if (count % 5 == 0)
                std::cout << '\n';
        }
    }

    void libRandomTime()
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    
        for (int count{ 1 }; count <= 100; ++count)
        {
            std::cout << std::rand() << '\t';
    
            // If we've printed 5 numbers, start a new row
            if (count % 5 == 0)
                std::cout << '\n';
        }
    }

    // Generate a random number between min and max (inclusive)
    // Assumes std::srand() has already been called
    // Assumes max - min <= RAND_MAX(32767)
    // return between 0 and 1 exclusive
    int getRandomNumber(int min, int max)
    {
        static constexpr double fraction { 1.0 / (RAND_MAX + 1.0) };  // static used for efficiency, so we only calculate this value once
        // evenly distribute the random number across our range
        return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
    }


    void randomUsingEffolkronium()
    {
        // get base random alias which is auto seeded and has static API and internal state
        using Random = effolkronium::random_static;

        for (int count{ 1 }; count <= 100; ++count)
        {
            std::cout << Random::get(1,count) << '\t';
    
            // If we've printed 5 numbers, start a new row
            if (count % 5 == 0)
                std::cout << '\n';
        }

    }





    
}