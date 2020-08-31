

#include <string>
#include <iostream>
#include <array>
#include <tuple>
#include <vector>
#include <functional>


namespace Functions
{
    namespace QuestionOne
    {
        // use const because the value will not change
        unsigned int sumTo(const unsigned int n)
        {
            unsigned int total{0};
            for (unsigned int i{1}; i <= n; i++ )
                total += i;
            return total;
        }

        void caller()
        {
            unsigned int num;
            std::cout << "type a nmber: ";
            std::cin >> num;
            std::cout << "the sum is: " << sumTo(num) << '\n';
        }
    }

    namespace QuestionTwo
    {
        struct Employee
        {
            std::string name;
            int age;
        };
        
        inline void printEmployeeName(const Employee &employee)
        {
            std::cout << "hello " << employee.name  << ". \n";
        };

        void caller()
        {
            Employee emp{"jonas", 10};
            printEmployeeName(emp);
        }
    }

    namespace QuestionThree
    {
        std::pair<int,int> minmax(const int a, const int b)
        {
            std::pair<int,int> temp{};
            if (a > b)
                temp = {b, a};
            else 
                temp = {a, b};
            return temp;
        }

        void caller()
        {
            std::cout << "the " << std::get<0>(minmax(10,20)) 
            << " is less then " << std::get<1>(minmax(10,20)) 
            << '\n';
        }
    }

    namespace QuestionFour
    {
        std::size_t getIndexOfLargestValue(const std::vector<int> vector)
        {
            std::size_t temp{0};
            for (std::size_t i{0}; i < vector.size(); i++)
            {
                if (vector[i] > vector[temp])
                {
                    temp = i;
                }
            }
            return temp;           
        };

        void caller()
        {
            std::vector<int> ns{1,2,3,4,5,20,1,2,3};
            std::cout << "the index is: " << getIndexOfLargestValue(ns) << '\n';
        };

    }

    namespace PointersFunctions
    {
        int foo()
        {
            int n{0};
            for (int i{1}; i < 10; i++)
                n+=i;
            return n;
        }

        long int foo(long int length)
        {
            long int n{0};
            for (int i{1}; i <= length; i++)
                n+=i;
            return n;
        }
        
        int goo()
        {
            return 6;
        }
        
        void caller()
        {
            int (*fcnPtr)(){ &foo }; // fcnPtr points to function foo
            std::cout << "fcnPtr pointing to foo: " << fcnPtr() 
            << "memory address: " << reinterpret_cast<void*>(fcnPtr) << 
            "size foo:" << sizeof(foo() ) << "ptr:" << sizeof(fcnPtr()) << '\n';
            fcnPtr = &goo; // fcnPtr now points to function goo
            std::cout << "fcnPtr pointing to goo: " << fcnPtr() 
            << "memory address: " << reinterpret_cast<void*>(fcnPtr) << 
            "size foo:" << sizeof(foo() ) << "ptr:" << sizeof(fcnPtr()) << '\n';

            long int (*fcnPtr2)(long int){ &foo }; // Initialize fcnPtr with function foo
            std::cout << "fcnPtr2 pointing to foo: " << fcnPtr2(100) 
            << "memory address: " << reinterpret_cast<void*>(fcnPtr2) << 
            "size foo:" << sizeof(foo() ) << "ptr:" << sizeof(fcnPtr2(5)) << '\n';
            
        }
                
    }

    namespace FunctionAsParameters
    {
        // Note our user-defined comparison is the third parameter
        // can be equivalently written as:
        // void selectionSort(int *array, int size, bool comparisonFcn(int, int))
        void selectionSort(int *array, int size, bool (*comparisonFcn)(int, int))
        {
            // Step through each element of the array
            for (int startIndex{ 0 }; startIndex < (size - 1); ++startIndex)
            {
                // bestIndex is the index of the smallest/largest element we've encountered so far.
                int bestIndex{ startIndex };
        
                // Look for smallest/largest element remaining in the array (starting at startIndex+1)
                for (int currentIndex{ startIndex + 1 }; currentIndex < size; ++currentIndex)
                {
                    // If the current element is smaller/larger than our previously found smallest
                    if (comparisonFcn(array[bestIndex], array[currentIndex])) // COMPARISON DONE HERE
                    {
                        // This is the new smallest/largest number for this iteration
                        bestIndex = currentIndex;
                    }
                }
        
                // Swap our start element with our smallest/largest element
                std::swap(array[startIndex], array[bestIndex]);
            }
        }

        bool ascending(int x, int y)
        {
            return x > y; // swap if the first element is greater than the second
        }
        
        // Here is a comparison function that sorts in descending order
        bool descending(int x, int y)
        {
            return x < y; // swap if the second element is greater than the first
        }
        
        // This function prints out the values in the array
        void printArray(int *array, int size)
        {
            for (int index{ 0 }; index < size; ++index)
            {
                std::cout << array[index] << ' ';
            }
            
            std::cout << '\n';
        }

        bool evensFirst(int x, int y)
        {
            // if x is even and y is odd, x goes first (no swap needed)
            if ((x % 2 == 0) && !(y % 2 == 0))
                return false;
        
            // if x is odd and y is even, y goes first (swap needed)
            if (!(x % 2 == 0) && (y % 2 == 0))
                return true;
        
                // otherwise sort in ascending order
            return ascending(x, y);
        }

        

        void caller()
        {
            int array[9]{ 3, 7, 9, 5, 6, 1, 8, 2, 4 };
 
            // Sort the array in descending order using the descending() function
            selectionSort(array, 9, descending);
            printArray(array, 9);
        
            // Sort the array in ascending order using the ascending() function
            selectionSort(array, 9, ascending);
            printArray(array, 9);

            // Sort the array in evens first order using the evensFirst() function
            selectionSort(array, 9, evensFirst);
            printArray(array, 9);

            //using alias to be more readable 
            // using validateFcnRaw = bool(*)(int, int); // type alias to raw function pointer
            // using validateFcn = std::function<bool(int, int)>; // type alias to std::function
        }


    }

    namespace FunctionParamsCalculator
    {
        struct Calculator{
            int n;
            int m;
            char oper;
        };

        // using alias to validates a pointer of function
        // same as: using arithmeticFcn = int(*)(int,int)
        using arithmeticFcn = std::function<int(int, int)>;

        Calculator getInputs(Calculator &c) 
        {
            std::cout << "type a number: ";
            std::cin >> c.n;
            do
            {   
                std::cout << "Enter an operation ('+', '-', '*', '/'): ";
                std::cin >> c.oper;
            }
            while (c.oper!='+' && c.oper!='-' && c.oper!='*' && c.oper!='/');
            std::cout << "type a number: ";
            std::cin >> c.m;
            return c;
        };

        inline int add(int n, int m) {return n + m;};
        inline int subtract(int n, int m) {return n - m;};
        inline int multiply(int n, int m) {return n * m;};
        inline int divide(int n, int m) {return n / m;};

        arithmeticFcn getArithmeticFunction(char oper)
        {
            switch (oper)
            {
            default:
            case '+': return add;
            case '-': return subtract;
            case '*': return multiply;
            case '/': return divide;
            }
        }

        void caller()
        {
            //sets n, m and operator
            Calculator c{getInputs(c)};

            //fcnPtr will pointer to apropriate operation function, then it will do it
            arithmeticFcn fcnPtr{ getArithmeticFunction(c.oper) };
            std::cout << c.n << ' ' << c.oper << ' ' << c.m << " = " << fcnPtr(c.n, c.m) << '\n';
            

        }
    }
    
    void caller()
    {
        // QuestionOne::caller(); 
        // QuestionTwo::caller();
        // QuestionThree::caller();
        // QuestionFour::caller();

        // FunctionAsParameters::caller();

        FunctionParamsCalculator::caller();
    }
}