#include <iostream>


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
    }
