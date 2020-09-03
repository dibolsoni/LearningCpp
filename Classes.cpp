#include <iostream>
#include <array>
#include <vector>
#include <cassert>
#include <cstdint>




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

    namespace QuizBall
    {
        class Ball
        {
        private:
            std::string m_color;
            float m_radius;
        public:
            Ball(){m_color = "black"; m_radius = 10.0f;};
            Ball(std::string color){m_color = color; m_radius = 10.0f;};
            Ball(float radius){m_color = "black"; m_radius = radius;};
            Ball(std::string color, float radius){m_color = "black"; m_radius = radius;};


            void print()
            {
                std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
            }
        };

        void caller()
        {
            Ball def{};
            def.print();
        
            Ball blue{ "blue" };
            blue.print();
            
            Ball twenty{ 20.0 };
            twenty.print();
            
            Ball blueTwenty{ "blue", 20.0 };
            blueTwenty.print();
        }
    }

    namespace QuizRGBA
    {
        class RGBA
        {
            std::uint_fast8_t m_red;
            std::uint_fast8_t m_green;
            std::uint_fast8_t m_blue;
            std::uint_fast8_t m_alpha;
        public:
            RGBA(std::uint_fast8_t red=0, std::uint_fast8_t green=0, std::uint_fast8_t blue=0, std::uint_fast8_t alpha=255)
                : m_red{red}, m_green{green}, m_blue{blue}, m_alpha{alpha}
            {}
            
            inline void print()
            {
                std::cout << "r=" << static_cast<int>(m_red) << " g=" << static_cast<int>(m_green) << " b=" << static_cast<int>(m_blue) << " a=" << static_cast<int>(m_alpha) << '\n';
            }
        };

        void caller()
        {
            RGBA teal{ 0, 127, 127 };
	        teal.print();
        }
    }

    namespace ChainningConstructor
    {
         
        class Employee
        {
        private:
            int m_id{};
            std::string m_name{};
        
        public:
            Employee(int id=0, const std::string &name=""):
                m_id{ id }, m_name{ name }
            {
                std::cout << "Employee " << m_name << " created.\n";
            }
        
            // Use a delegating constructor to minimize redundant code
            Employee(const std::string &name) : Employee{ 0, name }
            { }
        };
    }

    namespace Destructor
    {
        class IntArray
        {
        private:
            int *m_array{};
            int m_length{};
        
        public:
            IntArray(int length) // constructor
            {
                assert(length > 0);
        
                this->m_array = new int[static_cast<std::size_t>(length)]{};
                this->m_length = length;
            }
        
            ~IntArray() // destructor
            {
                // Dynamically delete the array we allocated earlier
                delete[] m_array;
            }
        
            void setValue(int index, int value) { m_array[index] = value; }
            int getValue(int index) { return m_array[index]; }
        
            int getLength() { return m_length; }
        };

        void caller()
        {
            IntArray ar(10); // allocate 10 integers
            for (int count{ 0 }; count < ar.getLength(); ++count)
                ar.setValue(count, count+1);
        
            std::cout << "The value of element 5 is: " << ar.getValue(5) << '\n';
                }
    }

    namespace ChainningFunctions
    {
        class Calc
        {
        private:
            int m_value;
        
        public:
            Calc() { m_value = 0; }
        
            Calc& add(int value) { m_value += value; return *this; }
            Calc& sub(int value) { m_value -= value; return *this; }
            Calc& mult(int value) { m_value *= value; return *this; }
        
            int getValue() { return m_value; }
        };
        
        void caller()
        {
            Calc calc;
            //now u can call like this:
            calc.add(5).sub(3).mult(4);
        
            std::cout << calc.getValue() << '\n';
        }
    }
    
    // namespace ConstClasses
    // {
    //     class Something
    //     {
    //     public:
    //         static int s_idGenerator;
    //         int m_id;
    //         int m_value;
        
    //         Something(): m_value{0} {m_id = s_idGenerator++; }
        
    //         void resetValue() { m_value = 0; }
    //         void setValue(int value) { m_value = value; }
        
    //         int getValue() const {return m_value;}; // note addition of const keyword here
    //     };

    //     void caller()
    //     {
    //         const Something something{};
    //         std::cout << something.getValue() << '\n'; // now works because getValue() is a const function
    //     }
    // }

    namespace Quiz3d
    {
        class Vector3d
        {
        private:
            double m_x{};
            double m_y{};
            double m_z{};
        
        public:
            Vector3d(double x = 0.0, double y = 0.0, double z = 0.0)
                : m_x{x}, m_y{y}, m_z{z}
            {
        
            }
        
            void print() const
            {
                std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
            }

            friend class Point3d;   
        };
        
        class Point3d
        {
        private:
            double m_x{};
            double m_y{};
            double m_z{};
        
        public:
            Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
                : m_x{x}, m_y{y}, m_z{z}
            {
        
            }
        
            void print() const
            {
                std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
            }
        
            void moveByVector(const Vector3d &v)
            {
                this->m_x += v.m_x;
                this->m_y += v.m_y;
                this->m_z += v.m_z;
            }
        };
        
        int main()
        {
            Point3d p{1.0, 2.0, 3.0};
            Vector3d v{2.0, 2.0, -3.0};
        
            p.print();
            p.moveByVector(v);
            p.print();
        
            return 0;
        }
    }

    namespace AnonymousObjects
    {
        class Cents
        {
        private:
            int m_cents{};

        public:
            Cents(int cents) {m_cents = cents;}

            int getCents() const {return m_cents;}
        };

        void print(const Cents &cents)
        {
            std::cout << cents.getCents() << " cents \n";
        }

        Cents add(const Cents &c1, const Cents &c2)
        {
            // List initialization looks at the return type of the function
            // and creates the correct object accordingly.
            return { c1.getCents() + c2.getCents() }; // return anonymous Cents value
        }

        void caller()
        {
            Cents cents1{ 6 };
            Cents cents2{ 8 };
            print(Cents{6});
            std::cout << "I have " << add(cents1, cents2).getCents() << " cents.\n"; // print anonymous Cents value
            //now calling with anonymous objs also:
            std::cout << "I have " << add(Cents{2}, Cents{10}).getCents() << " cents.\n"; // print anonymous Cents value
        }
    }

    namespace OverloadingOperators
    {
        class Fraction
        {
            int numerator{};
            int denominator{};

            public:
            Fraction(){reducer();}
            Fraction(int num, int den)
                :numerator{num}, denominator{den}
            {reducer();}


            static int gcd(int a, int b)
            {
                // std::cout << "a:" << a << "b:" << b << '\n';
                return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
            }

            void reducer()
            {
                if (numerator != 0 && denominator != 0)
                {
                    int gcd{ Fraction::gcd(numerator, denominator) };
                    numerator /= gcd;
                    denominator /= gcd;
                }
            }

            Fraction operator+(int n)
            {
                return Fraction{this->numerator + (this->denominator * n), this->denominator};
            }

            friend Fraction operator*(const int n, const Fraction f)
            {
                int num = f.numerator * n;
                return { num, f.denominator };
            }

            friend Fraction operator*(const Fraction f, const int n)
            {
                int num = f.numerator * n;
                return { num, f.denominator };
            }

            friend Fraction operator*(const Fraction fx, const Fraction fy)
            {
                int num = fx.numerator * fx.numerator;
                int den = fx.denominator * fx.denominator;
                return { num, den };
            }


            void print() const
            {
                std::cout << numerator << "/" << denominator << '\n';
            }

            //using << custom operand
            friend void operator<<(std::ostream &out, const Fraction &f)
            {
                out << f.numerator << "/" << f.denominator << '\n';
            }

            //using >> to custom in operand
            friend void operator>>(std::istream &in, Fraction &f)
            {
                in >> f.numerator;
                in >> f.denominator;
            }
        };

        void caller()
        {
            Fraction f1{2, 5};
            f1.print();
        
            Fraction f2{3, 8};
            f2.print();
        
            Fraction f3{ f1 * f2 };
            f3.print();
        
            Fraction f4{ f1 * 2 };
            f4.print();
        
            Fraction f5{ 2 * f2 };
            f5.print();
        
            Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
            f6.print();
            std::cout << f6;

            std::cout << "Type a numerator and denominator. numbers only separed by a space";
            Fraction f7;
            std::cin >> f7;
            f7.print();

            f6 = f6 + 10;
            f6.print();

        }
    }


}