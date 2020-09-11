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

    int caller()
    {
        int i = max(3, 7);
        std::cout << i << '\n';

        double d = max(3.14, 7.33);
        std::cout << d << '\n';

        char c = max('a', '6');
        std::cout << c << '\n';

        return 0;
    }
}
