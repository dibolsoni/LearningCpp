#include <iostream>
#include <vector>
#include <array>


namespace TheHeap
{
    void basic()
    {
        // In C++, when you use the new operator to allocate memory, 
        // this memory is allocated in the application’s heap segment.
        int *ptr = new int; // ptr is assigned 4 bytes in the heap
        int *array = new int[10]; // array is assigned 40 bytes in the heap

        // ptr1 and ptr2 may not have sequential addresses
        int *ptr1 = new int;
        int *ptr2 = new int;
        // Remember that deleting a pointer does not delete the variable,

        std::cout << " ptr:#" << ptr << " array:#" << array <<  " ptr1:#" << ptr1 <<  " ptr2:#" << ptr2 << '\n';



    }

    void caller()
    {
        basic();
    }
}

namespace TheStack
{
    //stacks works as a pile. Last-In, First-Out
    int foo(int x)
    {
        // b
        return x;
    } // foo is popped off the call stack here
    
    void basic()
    {
        // a
        foo(5); // foo is pushed on the call stack here
        // c
        // stack:
        // a:
        // main()
        // b:
        // foo() (including parameter x)
        // main()
        // c:
        // main()
    }

    // allocating more then the stacks can support with a fixed number of 10000000
    void stackOverflow()
    {
        int stack[10000000];
        std::cout << "hi";
    }

    // allocating more then the stacks can support with a infinite loop
    void stackOverflow2()
    {
        stackOverflow2();
    }

    // to minimize the stackOverflow, it it used a memoization algorithms
    int fibonacci(int count)
    {
        // We'll use a static std::vector to cache calculated results
        static std::vector<int> results{ 0, 1 };
    
        // If we've already seen this count, then use the cache'd result
        if (count < static_cast<int>(std::size(results)))
            return results[count];
        else
        {
            // Otherwise calculate the new result and add it
            results.push_back(fibonacci(count - 1) + fibonacci(count - 2));
            return results[count];
        }
    }
    

    void caller()
    {
        basic();
        // stackOverflow2(); // error: Segmentation fault (core dumped)

        for (int count = 0; count < 13; ++count)
		    std::cout << fibonacci(count) << " ";
    }



}