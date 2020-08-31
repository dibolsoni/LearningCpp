#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <vector>
#include <string_view>
#include <functional>
#include <cassert>
#include "effolkronium/random.hpp"

// #define DEBUG 

// lambdas aka annonimous functions () => in js.

namespace Lambdas
{
    struct Student
    {
        std::string name;
        unsigned short int score;
    };
    
    void basic()
    {
        std::array<Student, 8> arr{
            { 
                { "Albert", 3 },
                { "Ben", 5 },
                { "Christine", 2 },
                { "Dan", 8 }, // Dan has the most points (8).
                { "Enchilada", 4 },
                { "Francis", 1 },
                { "Greg", 3 },
                { "Hagrid", 5 } 
            }
        };

        //syntax
        // []() is the basic symbol to create a lambda
        // [](int a) //basic with an params
        // [](int a) -> int // with params and return type( '-> int' ) specified 
        // int b;
        // [b](int a) -> int // b is passed into the lambda with a clone(same name and value of b)
        // [&b](int a) -> int // b is passed into the lambda with a ref

        // custom sort using lambdas functions
        std::sort(
            arr.begin(), 
            arr.end(), 
            [](Student a, Student b) -> bool {
                return a.score > b.score;
            }
        );

        std::cout << arr[0].name << " has the best score \n";
    }

    namespace QuestionTwo
    {
        struct Season
        {
            std::string_view name{};
            double averageTemperature{};
        };

        void caller()
        {
            std::array<Season, 4> seasons{
                { 
                    { "Spring", 285.0 },
                    { "Summer", 296.0 },
                    { "Fall", 288.0 },
                    { "Winter", 263.0 } 
                }
            };
        
            std::sort(
                seasons.begin(), 
                seasons.end(),
                [](Season a, Season b) -> bool {
                    return a.averageTemperature < b.averageTemperature;
                } 
            );
            
            for (const auto& season : seasons)
            {
                std::cout << season.name << '\n';
            }
        }
    }

    namespace CaptureLambdaWithRef
    {
        struct Car
        {
            std::string make{};
            std::string model{};
        };

        void caller()
        {
            std::array<Car, 3> cars{ { 
                { "Volkswagen", "Golf" },
                { "Toyota", "Corolla" },
                { "Honda", "Civic" } 
            } };
 
            int comparisons{ 0 };
            
            std::sort(cars.begin(), cars.end(),
                // Capture @comparisons by reference.
                [&comparisons](const auto& a, const auto& b) {
                // We captured comparisons by reference. We can modify it without "mutable".
                ++comparisons;
            
                // Sort the cars by their make.
                return (a.make < b.make);
            });
            
            std::cout << "Comparisons: " << comparisons << '\n';
            
            for (const auto& car : cars)
            {
                std::cout << car.make << ' ' << car.model << '\n';
            }
        }
    }

    namespace LambdaWithCallbackFunctions
    {
        void invoke(const std::function<void(void)> &fn)
        {
            fn();
        }
        
        void caller()
        {
            int i{ 0 };
        
            // Increments and prints its local copy of @i.
            auto count{ [i]() mutable {
            std::cout << ++i << '\n';
            } };
        
            invoke(count); //will copy the state from count, so will not change
            // std::ref(count) ensures count is treated like a reference
            // thus, anything that tries to copy count will actually copy the reference
            // ensuring that only one count exists
            invoke(std::ref(count));
            invoke(std::ref(count));
            invoke(std::ref(count));

        }
    }

    namespace LambdaCaptures
    {
        namespace QuestionOne
        {
            int i{};
            static int j{};
            
            int getValue()
            {
                return 0;
            }
            
            void caller()
            {
                int a{};
                constexpr int b{};
                static int c{};
                static constexpr int d{};
                const int e{};
                const int f{ getValue() };
                static const int g{}; 
                static const int h{ getValue() }; 
            
            [=](){
                // Try to use the variables without explicitly capturing them.
                a;//No. a has automatic storage duration.
                b;
                c;
                d;
                e;
                f;//No. f‘s value depends on getValue, which might require the program to run.
                g;
                h;
                i;
                j;
            }();
            }
        }

        namespace QuestionTwo
        {
            struct NumbersGame
            {
                unsigned short int start{};
                unsigned short int count{};
                std::vector<unsigned int> base_numbers;
                std::vector<unsigned int> numbers;
            };


            void generateNumbers(NumbersGame &ng, const unsigned int &random_multiplier)
            {
                std::cout << "Start where? \n";
                std::cin >> ng.start;
                std::cout << "How many? \n";
                std::cin >> ng.count;
                
                // add the square * random multiplier to the numbers
                for (size_t i{ng.start}; i < (ng.start + ng.count); i++)
                {
                    
                    ng.numbers.push_back((i * i) * random_multiplier);
                    #ifdef DEBUG
                    std::cout << "base number:" << i << '\n';
                    std::cout << "square : "<< (i * i) << '\n';
                    std::cout << "random multi: "<< random_multiplier << '\n';
                    std::cout << "pushing number:" << (i * i) * random_multiplier << '\n';
                    std::cout << "######################\n";
                    #endif
                }
                std::cout << "I generated " << ng.count << " square numbers. Do you know what each number is after multiplying it by " << random_multiplier << "?\n";

            }

            void print_numbers(const NumbersGame &ng)
            {
                for(auto& n : ng.numbers)
                {   
                    std::cout << n << " ";
                }
                std::cout << "\n";
            }

            bool game_loop(NumbersGame &ng)
            {

                while (ng.numbers.size() > 0)
                {
                    unsigned int input;
                    std::cin >> input;
                    auto found{std::find(ng.numbers.begin(), ng.numbers.end(), input)};
                    if (found == ng.numbers.end())
                    {
                    std::cout << "Nooo!! You almost got it. ";
                    //get the itirator position
                    auto closest = std::min_element(
                        ng.numbers.begin(),
                        ng.numbers.end(),
                        [](const int& a, const int& b){
                            return a < b;
                        }
                    );
                    //set itirator position number;
                    size_t num_pos = std::distance(ng.numbers.begin(), closest);
                    std::cout << "Next time, try: " << ng.numbers[num_pos] << '\n';
                        return false;
                    }
                    ng.numbers.erase(found);
                    std::cout << "Nice! " << ng.numbers.size() << " numbers left. \n";
                }
            }

            void caller()
            {
                using Random = effolkronium::random_static;
                unsigned int random_multiplier = Random::get(2,4);
                NumbersGame ng{};
                generateNumbers(ng, random_multiplier);

                print_numbers(ng);

                game_loop(ng);


            }


        }
    }

    void caller()
    {
        // basic();
        // QuestionTwo::caller();
        // CaptureLambdaWithRef::caller();
        // LambdaWithCallbackFunctions::caller();
        LambdaCaptures::QuestionTwo::caller();
    }
}