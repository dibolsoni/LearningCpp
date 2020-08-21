#include <iostream>

namespace IfStatement
{
    void init_statement()
    {
        std::string firstName{};
        std::string lastName{};
    
        std::cout << "First name: ";
        std::cin >> firstName;
    
        std::cout << "Last name: ";
        std::cin >> lastName;

        //only set full name to if statement
        if (std::string fullName{ firstName + ' ' + lastName }; fullName.length() > 20)
        {
            std::cout << '"' << fullName << "\"is too long!\n";
        }
        else
        {
            std::cout << "Your name is " << fullName << '\n';
        }
    }

    
}