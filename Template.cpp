#include <iostream>
#include <cassert>
#include <string>


namespace Template
{
    // without template
    // int max(int x, int y)
    // {
    //     return (x > y) ? x : y;
    // }
    // double max(double x, double y)
    // {
    //     return (x > y) ? x : y;
    // }

    // with template
    template <typename T>
    const T& max(const T& x, const T& y)
    {
        return (x > y) ? x : y;
    }
	
    class Cents
    {
    private:
        int m_cents;
    public:
        Cents(int cents)
            : m_cents{ cents }
        {
        }

        inline int getCents() const {return m_cents;}

        //must overload the operator > to work with templates    
        friend bool operator>(const Cents &c1, const Cents &c2)
        {
            return (c1.m_cents > c2.m_cents);
        }
    };

    int caller()
    {
        int i = max(3, 7);
        std::cout << i << '\n';

        double d = max(3.14, 7.33);
        std::cout << d << '\n';

        char c = max('a', '6');
        std::cout << c << '\n';

        Cents cents = max(Cents{1}, Cents{3});
        std::cout << cents.getCents() << '\n';

        return 0;
    }

    template <class T>
    class Array
    {
    private:
        int a_length{};
        T* a_data{};

    public:
        Array(int length)
        {
            assert(length > 0);
            // allocating memory
            a_data = new T[length]{};
            a_length = length;
        }

        //Not allowing copies to be created
        Array(const Array&) = delete;
        Array& operator=(const Array&) = delete;

        ~Array()
        {
            delete[] a_data;
        }

        void Erase()
        {
            delete[] a_data;
            a_data = nullptr;
            a_length = 0;
        }

        T& operator[](size_t index)
        {
            assert(index >= 0 && index < a_length);
            return a_data[index];
        }

        inline int getLength() const {return a_length;}
    };
 
    int templateClass()
    {
        Array<int> intArray(12);
        Array<double> doubleArray(12);
    
        for (int count{ 0 }; count < intArray.getLength(); ++count)
        {
            intArray[count] = count;
            doubleArray[count] = count + 0.5;
        }
    
        for (int count{ intArray.getLength() - 1 }; count >= 0; --count)
            std::cout << intArray[count] << '\t' << doubleArray[count] << '\n';
    
        return 0;
    }

    namespace Quiz
    {
        template<class T_FIRST, class T_SECOND>
        class Pair
        {
            T_FIRST p_first{};
            T_SECOND p_second{};
        public:
            Pair(const T_FIRST& first, const T_SECOND& second)
                : p_first{first}, p_second{second}
            {}

            inline const T_FIRST& first() const {return p_first;}
            inline const T_SECOND& second() const {return p_second;}
        };

        // void questonOneCaller()
        // {
        //     Pair1<int> p1(5, 8);
        //     std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
        
        //     const Pair1<double> p2(2.3, 4.5);
        //     std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
        
        // }

        template <class T_SECOND>
        class StringPair: public Pair<std::string, T_SECOND>
        {
            public:
            StringPair(const std::string& str, const T_SECOND& second)
                : Pair<std::string, T_SECOND>(str, second)
            {}

        };

        
        void questonTwoCaller()
        {
            Pair<int, double> p1(5, 6.7);
            std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
        
            const Pair<double, int> p2(2.3, 4);
            std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
        
        }

        void questonThreeCaller()
        {
            StringPair<int> svp("Hello", 5);
	        std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
        
        }
    }

}
