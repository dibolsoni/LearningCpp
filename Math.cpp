#include <iostream>
#include <array>
#include "Math.h"

int Math::sum(int n, int n2) 
{
    return n + n2;
};

int Math::sum_array(int nums[10]) 
{
    int total;
    for (int i = 0; i < sizeof(nums)/sizeof(nums[0]) ; i++)
    {
        total += nums[i];
    }
    return total;    
};

void Math::print_sum()
{
    int n { sum(1, 2) };
    int n2;
    // int nums  = {10,2, 6,4,6,7,7,10};
    // int total_array = sum_array(nums);


    std::cout << "hello world \n";
    std::cout << "default sum is: " << n << "\n";
    std::cout << "type two numbers to n: \n";
    std::cin >> n;
    std::cin >> n2;  
    std::cout << "the new n is: " << sum(n,n2) << "\n";
    // std::cout << "the sum of nums in array is: " << total_array << "\n";
};

static void Math::increment_decrement()
{
    int x{ 5 };
    int y{ 5 };
    std::cout << x << " " << y << '\n';
    std::cout << ++x << " " << --y << '\n'; // prefix = inc x then return x
    std::cout << x << " " << y << '\n';
    std::cout << x++ << " " << y-- << '\n'; // postfix = copy x, inc copy of x, return copy
    std::cout << x << " " << y << '\n';
};

static void Math::xor_operand() 
{
    bool a = true;
    bool b = false;
    if (a != b) 
    {
        std::cout >> "the symbol for xor operand is the same as diff(!=) " >> "\n";
        std::cout >> "so in order to be a xor operand, must expression must be a boolean" >> "\n";
        std::cout >> "(true != false) is a xor operand" >> "\n";
    }
};

static void Math::converts()
{
    {
        int i {100};
        i = i / 0.25; //converting with loss of data
        std::cout << "value: " << i;
    }

    {
        int i {100};
        i = static_cast<int>(i / 0.25); //converting without loss of data
        std::cout << "value: " << i;
    }


}