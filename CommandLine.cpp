#include <iostream>
#include <sstream> // for std::stringstream
#include <string>

namespace CommandLine
{
    void getIntArg(int &argc, char *argv[])
    {
        if (argc <= 1)
        {
            // On some operating systems, argv[0] can end up as an empty string instead of the program's name.
            // We'll conditionalize our response on whether argv[0] is empty or not.
            if (argv[0])
                std::cout << "Usage: " << argv[0] << " <number>" << '\n';
            else
                std::cout << "Usage: <program name> <number>" << '\n';
        }
    
        std::stringstream convert{ argv[1] }; // set up a stringstream variable named convert, initialized with the input from argv[1]
    
        int myint{};
        if (!(convert >> myint)) // do the conversion
            myint = 0; // if conversion fails, set myint to a default value
    
        std::cout << "Got integer: " << myint << '\n';
    }
    
    void caller(int &argc, char *argv[])
    {  
        std::cout << "There are " << argc << " arguments:\n";
    
        // Loop through each argument and print its number and value
        for (int count{ 0 }; count < argc; ++count)
        {
            std::cout << count << ' ' << argv[count] << '\n';
        }

        getIntArg(argc, argv);
        
    }
}