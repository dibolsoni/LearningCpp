

#include <string>
#include <iostream>
#include <array>
#include <tuple>
#include <vector>



namespace ReturnTypes
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
        std::size_t getIndexOfLargestValue(const std::vector<int>& vector)
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
    
    void caller()
    {
        // QuestionOne::caller(); 
        // QuestionTwo::caller();
        // QuestionThree::caller();
        QuestionFour::caller();
    }
}