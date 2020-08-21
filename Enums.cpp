#include <iostream>


namespace Enum 
{
    void getEnum() 
    {
        enum Color
        {
            COLOR_BLACK, // assigned 0
            COLOR_RED, // assigned 1
            COLOR_BLUE, // assigned 2
            COLOR_GREEN, // assigned 3
            COLOR_WHITE, // assigned 4
            COLOR_CYAN, // assigned 5
            COLOR_YELLOW, // assigned 6
            COLOR_MAGENTA // assigned 7
        };

        int input_color;
        std::cin >> input_color;
        //in order to set the enum, first get the int value then cast it to EnumType
        Color color { static_cast<Color>(input_color)};
        std::cout << "color is " << color << "\n";
    }

    void enum_class() 
    {
        enum class Color // "enum class" defines this as a scoped enumeration instead of a standard enumeration
        {
            red, // red is inside the scope of Color
            blue
        };
    
        enum class Fruit
        {
            banana, // banana is inside the scope of Fruit
            apple
        };
    
        Color color{ Color::red }; // note: red is not directly accessible any more, we have to use Color::red
        Fruit fruit{ Fruit::banana }; // note: banana is not directly accessible any more, we have to use Fruit::banana
        
        // if (color == fruit) // compile error here, as the compiler doesn't know how to compare different types Color and Fruit
        //     std::cout << "color and fruit are equal\n";
        // else
        //     std::cout << "color and fruit are not equal\n";
    }

    //Define an enumerated type to choose between the following monster races: 
    //orcs, goblins, trolls, ogres, and skeletons.
    void question_one() 
    {
        enum Monsters : int
        {
            MONSTER_ORC,
            MONSTER_GLOBIN,
            MONSTER_TROLL,
            MONSTER_OGRE,
            MONSTER_SKELETON
        };

        Monsters troll {MONSTER_TROLL};
    }
}