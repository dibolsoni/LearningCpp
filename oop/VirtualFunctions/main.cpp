// #include "Cow.h"
// #include "Cat.h"
// #include "Dog.h"
#include "VirtualClass.cpp"
// #include "WithoutVirtualClass.cpp"
#include <iostream>


// int main()
// {
//     Cow cow{"Betsy"};
//     std::cout << cow.getName() << " says " << cow.speak() << '\n';

//     Cat cat{"Cat"};
//     std::cout << cat.getName() << " says " << cat.speak() << '\n';

//     Dog dog{"Dog"};
//     std::cout << dog.getName() << " says " << dog.speak() << '\n';

//     return 0;
// }

int main()
{
    Copier copier(1, 2, 3);
    PoweredDevice &ref_pd{copier};

    std::cout << copier.c_name << "\n";
    std::cout << ref_pd.p_name << "\n";

 
    return 0;
}