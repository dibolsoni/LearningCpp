#include <iostream>
#include <string>

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

    namespace question_two 
    {
        enum Animal
        {
            ANIMAL_PIG,
            ANIMAL_CHICKEN,
            ANIMAL_GOAT,
            ANIMAL_CAT,
            ANIMAL_DOG,
            ANIMAL_OSTRICH
        };

        std::string getAnimalName(Animal animal)
        {
            switch (animal)
            {
            case ANIMAL_PIG:
                return "pig";
            case ANIMAL_CHICKEN:
                return "chicken";
            case ANIMAL_GOAT:
                return "goat";
            case ANIMAL_CAT:
                return "cat"; 
            case ANIMAL_DOG:
                return "dog"; 
            case ANIMAL_OSTRICH:
                return "ostrich";
          
            default:
                std::cout << "type a valid animal as: pig, chicken, goat, cat, dog, ostrich \n";
                break;
            };

        }

        void printNumOfLegs(Animal animal)
        {
            switch (animal)
            {
            case ANIMAL_DOG:
            case ANIMAL_CAT:
            case ANIMAL_GOAT:
            case ANIMAL_PIG:
                std::cout << "A " << getAnimalName(animal) << " has 4 legs \n";
                break;
            case ANIMAL_OSTRICH:
            case ANIMAL_CHICKEN:
                std::cout << "A " << getAnimalName(animal) << " has 2 legs \n";
                break;
            default: 
                std::cout << "invalid animal \n";
                break;
            }

        }

        void printNumOfLegsCaller()
        {
            printNumOfLegs(ANIMAL_CAT);
            printNumOfLegs(ANIMAL_CHICKEN);
        }


        

    }


}