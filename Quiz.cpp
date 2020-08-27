#include <iostream>
#include <array>
#include <numeric> // std::reduce
#include <string_view>
#include <string>
#include <vector> 

namespace Chapter6
{
    void print_array(const std::vector<int>& array)
    {
        for(auto& item : array)
            std::cout << item << " ";
    }
    namespace QuestionOne
    {
        enum BackpackType{
            ITEM_HEALTH_POTIONS,
            ITEM_TORCHES,
            ITEM_ARROWS,
            ITEM_MAX_ITEMS
        };
        using inventory_type = std::array<int, BackpackType::ITEM_MAX_ITEMS>;

        int count_total_backpack(const inventory_type& items)
        {
            return std::reduce(items.begin(), items.end()); //sum items
        }

        void caller()
        {
            inventory_type items{ 2, 5, 10 };
 
            std::cout << "The player has " << count_total_backpack(items) << " item(s) in total.\n";
 
            // We can access individual items using the enumerators:
            std::cout << "The player has " << items[BackpackType::ITEM_TORCHES] << " torch(es)\n";
        }
    }

    namespace QuestionTwo
    {
        struct Student{
            std::string name;
            unsigned int grade;
        };
        bool higherScore(Student a, Student b)
        {
            return a.grade > b.grade;
        }

        void get_students()
        {

            std::vector<Student> students(3);           
            // std::array<Student,3> students{};
            int i{1};
            for(auto& student : students)
            {
                std::cout << "type the name of student #" << i << ": \n";
                std::cin >> student.name;
                std::cout << "type the grade of student #" << i << ": \n";
                std::cin >> student.grade;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                i++;
            }; 

            std::sort(students.begin(), students.end(), higherScore);

            for (auto& student : students)
            {
                std::cout << student.name << " has " << student.grade << " score\n";
            }

        }




    }
}