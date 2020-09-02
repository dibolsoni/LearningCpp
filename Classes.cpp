#include <iostream>
#include <array>
#include <vector>
#include <cassert>




namespace ClassesBasic
{
    namespace SimpleStack
    {
        class Stack
        {
        private:
            std::array<int,10> stack;
            unsigned short int size;
        public:
            inline void reset() {size = 0;};
            inline void push(int value) {stack[size++] = value;}
            void pop()
            {
                assert(stack[size] && "stack is empty");
                size--;
            }
            void print()
            {
                std::cout << "(";
                for(size_t i{0}; i < size; i++)
                {
                    std::cout << " " << stack[i] ;
                }
                std::cout << " ) \n";
            }
        };

        void caller()
        {
            Stack stack;
            stack.reset();
        
            stack.print();
        
            stack.push(5);
            stack.push(3);
            stack.push(8);
            stack.print();
        
            stack.pop();
            stack.print();
        
            stack.pop();
            stack.pop();
        
            stack.print();
        }
    }
}