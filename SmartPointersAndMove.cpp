#include <iostream>


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
}
