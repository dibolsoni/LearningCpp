#include <iostream>
#include <string>
#include <vector>
#include <utility> // For std::pair, std::make_pair, std::move, std::move_if_noexcept
#include <stdexcept> // std::runtime_error
#include <string_view>
#include <memory>   
        

namespace SmartPointers
{
    namespace AutoPtr
    {
        template<class T>
        class Auto_ptr2
        {
            T* m_ptr;
        public:
            Auto_ptr2(T* ptr=nullptr)
                :m_ptr(ptr)
            {
            }
            
            ~Auto_ptr2()
            {
                delete m_ptr;
            }
        
            // A copy constructor that implements move semantics
            Auto_ptr2(Auto_ptr2& a) // note: not const
            {
                m_ptr = a.m_ptr; // transfer our dumb pointer from the source to our local object
                a.m_ptr = nullptr; // make sure the source no longer owns the pointer
            }
            
            // An assignment operator that implements move semantics
            Auto_ptr2& operator=(Auto_ptr2& a) // note: not const
            {
                if (&a == this)
                    return *this;
        
                delete m_ptr; // make sure we deallocate any pointer the destination is already holding first
                m_ptr = a.m_ptr; // then transfer our dumb pointer from the source to the local object
                a.m_ptr = nullptr; // make sure the source no longer owns the pointer
                return *this;
            }
        
            T& operator*() const { return *m_ptr; }
            T* operator->() const { return m_ptr; }
            bool isNull() const { return m_ptr == nullptr;  }
        };
        
        class Resource
        {
        public:
            Resource() { std::cout << "Resource acquired\n"; }
            ~Resource() { std::cout << "Resource destroyed\n"; }
        };
        
        void caller()
        {
            Auto_ptr2<Resource> res1(new Resource);
            Auto_ptr2<Resource> res2; // Start as nullptr
        
            std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
            std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
        
            res2 = res1; // res2 assumes ownership, res1 is set to null
        
            std::cout << "Ownership transferred\n";
        
            std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
            std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
        
        }
    }

    namespace RValueRefs
    {
        class Fraction
        {
        private:
            int m_numerator;
            int m_denominator;
        
        public:
            Fraction(int numerator = 0, int denominator = 1) :
                m_numerator{ numerator }, m_denominator{ denominator }
            {
            }
        
            friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
            {
                out << f1.m_numerator << '/' << f1.m_denominator;
                return out;
            }
        };

        void fun(const int &lref) // l-value arguments will select this function
        {
            std::cout << "l-value reference to const\n";
        }
        
        void fun(int &&rref) // r-value arguments will select this function
        {
            std::cout << "r-value reference\n";
        }
        
        void main()
        {
            auto &&rref{ Fraction{ 3, 5 } }; // r-value reference to temporary Fraction
            
            // f1 of operator<< binds to the temporary, no copies are created.
            std::cout << rref << '\n';

            int x{ 5 };
            fun(x); // l-value argument calls l-value version of function
            fun(5); // r-value argument calls r-value version of function

            // l-value references
            int &ref1{ x }; // A
            // int &ref2{ 5 }; // B // Won't compile
        
            const int &ref3{ x }; // C
            const int &ref4{ 5 }; // D
        
            // r-value references
            // int &&ref5{ x }; // E // Won't compile
            int &&ref6{ 5 }; // F
        
            // const int &&ref7{ x }; // G // Won't compile
            const int &&ref8{ 5 }; // H
        }
    }

    namespace StdMove
    {
        void caller()
        {
            std::vector<std::string> v;
            std::string str = "Knock";
        
            std::cout << "Copying str\n";
            v.push_back(str); // calls l-value version of push_back, which copies str into the array element
            
            std::cout << "str: " << str << '\n';
            std::cout << "vector: " << v[0] << '\n';
        
            std::cout << "\nMoving str\n";
        
            v.push_back(std::move(str)); // calls r-value version of push_back, which moves str into the array element
            
            std::cout << "str: " << str << '\n';
            std::cout << "vector:" << v[0] << ' ' << v[1] << '\n';
        }
    }

    namespace MoveAndCopyClass
    {
        template<class T>
        class MoveClass
        {
        private:
            T* m_resource{};

        public:
            MoveClass() = default;

            MoveClass(T resource)
                : m_resource{new T{resource}}
            {}

            // copy constructor
            MoveClass(const MoveClass& that)
            {
                //deep copy
                if (that.m_resource != nullptr)
                    m_resource = new T{*that.m_resource};
            }

            // move constructor
            // move source value owner to class
            MoveClass(MoveClass&& that)
                : m_resource { that.m_resource }
            {
                //resets source value
                that.m_resource = nullptr;
            }

            ~MoveClass()
            {
                std::cout << "Destroying " << *this << '\n';
                delete m_resource;
            }

            friend std::ostream& operator<<(std::ostream& out, const MoveClass& move_class)
            {
                out << "MoveClass(";

                if (move_class.m_resource == nullptr)
                    out << "empty";
                else
                    out << *move_class.m_resource;

                out << ")\n";

                return out;
            }

        };

        class CopyClass
        {
        public:
            bool m_throw{};
            
            CopyClass() = default;
            
            // Copy constructor throws an exception when copying from a CopyClass object where its m_throw is 'true'
            CopyClass(const CopyClass& that)
                : m_throw{ that.m_throw }
            {
                if (m_throw)
                {
                throw std::runtime_error{ "abort!" };
                }
            }
        };

        void caller()
        {
              // We can make a std::pair without any problems:
            std::pair my_pair{ MoveClass{ 13 }, CopyClass{} };
            
            std::cout << "my_pair.first: " << my_pair.first << '\n';
            
            // But the problem arises when we try to move that pair into another pair.
            try
            {
                my_pair.second.m_throw = true; // To trigger copy constructor exception
            
                // The following line will throw an exception
                // std::pair moved_pair{ std::move(my_pair) }; // after throw an error, source still be reseted(value wasnt returned)
                std::pair moved_pair{std::move_if_noexcept(my_pair)}; // because of throw an error, source value is returned
            
                std::cout << "moved pair exists\n"; // Never prints
            }
            catch (const std::exception& ex)
            {
                std::cerr << "Error found: " << ex.what() << '\n';
            }
            
            std::cout << "my_pair.first: " << my_pair.first << '\n';
        }


    }

    namespace MakeUnique
    {
        class Fraction
        {
        private:
            int m_numerator{ 0 };
            int m_denominator{ 1 };
        
        public:
            Fraction(int numerator = 0, int denominator = 1) :
                m_numerator{ numerator }, m_denominator{ denominator }
            {
            }
        
            friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
            {
                out << f1.m_numerator << '/' << f1.m_denominator;
                return out;
            }
        };

        std::unique_ptr<Fraction> createFraction(const int&& num, const int&& den)
        {
            return std::make_unique<Fraction>(num, den);
        }
        
        //use std::make_unique() instead of creating std::unique_ptr and using new yourself
        void caller()
        {
            // Create a single dynamically allocated Fraction with numerator 3 and denominator 5
            // We can also use automatic type deduction to good effect here
            auto f1{ std::make_unique<Fraction>(3, 5) };
            std::cout << *f1 << '\n';
        
            // Create a dynamically allocated array of Fractions of length 4
            auto f2{ std::make_unique<Fraction[]>(4) };
            std::cout << f2[0] << '\n';

            auto f3{createFraction(2,3)};
            std::cout << *f3 << '\n';
        }
    }

}
