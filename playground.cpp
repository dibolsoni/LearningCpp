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


    void caller()
    {
        std::array<int, 3> array{1,2,3};
        print_array(array.begin(), array.end());
        // array_remove_item(array.begin(), array.end(), 1);
        print_array(array.begin(), array.end());

        std::vector<int> vector{1,2,3,4,5};

        vector.erase(vector.begin());
    }


}