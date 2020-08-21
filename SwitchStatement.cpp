#include <iostream>

namespace SwitchStatement
{
    // void basic_switch()
    // {
    //     switch (1)
    //     {
    //         int a; // okay, declaration is allowed before the case labels
    //         int b{ 5 }; // illegal, initialization is not allowed before the case labels
        
    //         case 1:
    //             int y; // okay, declaration is allowed within a case
    //             y = 4; // okay, this is an assignment
    //             break;
        
    //         case 2:
    //             y = 5; // okay, y was declared above, so we can use it here too
    //             break;
        
    //         case 3:
    //             int z{ 4 }; // illegal, initialization is not allowed within a case
    //             break;
    //         case 4:
    //         { // note addition of block here
    //             int x{ 4 }; // okay, variables can be initialized inside a block inside a case
    //             std::cout << x;
    //             break;
    //         }                    
    //         default:
    //             std::cout << "default case\n";
    //             break;
    //     }
    // }

    int question_one_calculate(int x, int y, char oper)
    {
        
        switch (oper)
        {
        //using ' to get the char value correctly
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        
        default:
            std::cout << "you return a invalid operator" << "\n";
            return false;
        }
    }


}