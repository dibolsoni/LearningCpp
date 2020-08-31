#include <iostream>
#include <string>
#include <limits>
#include <cassert> // for assert()
#include <cmath> // std::sqrt

namespace Test
{
    void WithoutAssert()
    {
        std::string hello{ "Hello, world!" };
        int index;
    
        do
        {
            std::cout << "Enter an index: ";
            std::cin >> index;
    
            //handle case where user entered a non-integer
            if (std::cin.fail())
            {
                std::cin.clear(); // reset any error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
                index = -1; // ensure index has an invalid value so the loop doesn't terminate
                continue; // this continue may seem extraneous, but it explicitly signals an intent to terminate this loop iteration...
            }
    
            // ...just in case we added more stuff here later
    
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any remaining characters in the input buffer
    
        } while (index < 0 || index >= static_cast<int>(hello.size())); // handle case where user entered an out of range integer
    
        std::cout << "Letter #" << index << " is " << hello[index] << '\n';
    }

    namespace Assert
    {
        double calculateTimeUntilObjectHitsGround(double initialHeight, double gravity)
        {
            // assert(gravity > 0.0); // The object won't reach the ground unless there is positive gravity.
            // assert more descritive
            assert(gravity > 0.0 && "the gravity must be positive");
            if (initialHeight <= 0.0)
            {
                // The object is already on the ground. Or buried.
                return 0.0;
            }
            
            return std::sqrt((2.0 * initialHeight) / gravity);
        }

        // static_assert runs in compile_time, assert runs in runtime
        void StaticAssert()
        {
            // static_assert(sizeof(long) == 4, "long must be 8 bytes"); // error
            static_assert(sizeof(int) == 4, "int must be 4 bytes");

        }

        void caller()
        {
            std::cout << "Took " << calculateTimeUntilObjectHitsGround(100.0, -9.8) << " second(s)\n";
        }
    }

    void caller()
    {
        // WithoutAssert();
        // Assert::caller();
        Assert::StaticAssert();
    }
}