#include <array>
#include <vector>
#include <iostream>


namespace Playground
{
    void print_array(int *begin, int *end)
    {

        while(begin != end)
        {
            std::cout << *begin++ << "\n";
        }
    }

    void array_remove_item(int *begin, int *end, int item)
    {
        while(begin != end)
        {
            if (*begin == item)
            {
                // int* temp = begin - 1;
                std::cout << *begin;
                // temp = begin + 1;
                // std::cout << *temp;
            }
        }
    }


    
    // A function named max() that takes two doubles and returns the larger of the two.
    inline double max(const double &x, const double &y) { return x > y ?  x: y;}
    inline int max(const int &x, const int &y) { return x > y ?  x: y;}

    void swap(int &x, int &y)
    {
        int *temp{&x};
        x = y;
        y = *temp;
    }

    int& getLargestElement(int* begin, int* end, int length)
    {
        int largest{0};
        for(size_t i{0}; i < length; i++)
        {
            if (*(begin + i) > *(begin + largest))
                largest = i;
        }
        return *(begin + largest);
    }

    void setArrayByRef()
    {
        std::array<int, 5> array{1,3,5,10,2};
        int &largest = getLargestElement(array.begin(), array.end(), array.size());
        std::cout << largest  << '\n';
        largest = 12;    
        std::cout << largest  << '\n';  
        std::cout << getLargestElement(array.begin(), array.end(), array.size())  << '\n';
    }
    


    void caller()
    {
        setArrayByRef();
    }


}