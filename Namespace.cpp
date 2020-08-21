#include "Constants.h"
#include <iostream>


namespace Namespace {
    bool passOrFail()
    {
        static int counter {1};
        if (counter++ > 3)
            return false;
        return true;
    }

    // Fix the following program:
    void question_one() 
    {
        std::cout << "Enter a positive number: ";
        int num{};
        std::cin >> num;
    
    
        if (num < 0)
        {  //fixed
            std::cout << "Negative number entered.  Making positive.\n";
            num = -num;
        }  //fixed
        std::cout << "You entered: " << num;

    }

    //Write a file named constants.h that makes the following program run  
    void question_two()
    {
        std::cout << "How many students are in your class? ";
        int students{};
        std::cin >> students;
    
    
        if (students > constants::max_class_size)
            std::cout << "There are too many students in this class";
        else
            std::cout << "This class isn't too large";
    }

    //Complete the following program by writing the passOrFail() function, 
    //which should return true for the first 3 calls, and false thereafter.
    void question_three()
    {
        std::cout << "User #1: " << (passOrFail() ? "Pass" : "Fail") << '\n';
        std::cout << "User #2: " << (passOrFail() ? "Pass" : "Fail") << '\n';
        std::cout << "User #3: " << (passOrFail() ? "Pass" : "Fail") << '\n';
        std::cout << "User #4: " << (passOrFail() ? "Pass" : "Fail") << '\n';
        std::cout << "User #5: " << (passOrFail() ? "Pass" : "Fail") << '\n';
    }
}

