#include <iostream>
#include <array>
#include <numeric> // std::reduce
#include <string_view>
#include <string>
#include <vector> 
#include <type_traits>
#include <iterator>

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

        void caller()
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

    namespace QuestionThree
    {
        void swap(int& a, int& b)
        {
            const int temp{a};
            a = b;
            b = temp;
        }

        void caller()
        {
            int a{1};
            int b{2};
            std::cout << "before: " << a << "-" << b << '\n';
            swap(a,b);
            std::cout << "after: " << a << "-" << b << '\n';

        }
    }

    namespace QuestionFour
    {
        void print_c_string(const char* str)
        {
            while(*str)
                std::cout << *str++ << '\n';
            
        }
        void caller()
        {
            print_c_string("Hello World!");
            std::cout<< '\n';
        }
    }

    namespace QuestionSix
    {
        enum Cards{
            CARD_2,
            CARD_3,
            CARD_4,
            CARD_5,
            CARD_6,
            CARD_7,
            CARD_8,
            CARD_9,
            CARD_10,
            CARD_JACK,
            CARD_QUEEN,
            CARD_KING,
            CARD_ACE,
            CARDS_MAX
        };

        enum Suits{
            SUIT_CLUBS,
            SUIT_DIAMONDS,
            SUIT_HEARTS,
            SUIT_SPADES,
            SUITS_MAX
        };

        struct Card{
            Cards rank;
            Suits suit;
        };



        void print_card(const Card& card)
        {

            switch (card.rank)
            {
            case CARD_2:
                std::cout << "2";
                break;
            case CARD_3:
                std::cout << "3";
                break;
            case CARD_4:
                std::cout << "4";
                break;
            case CARD_5:
                std::cout << "5";
                break;
            case CARD_6:
                std::cout << "6";
                break;
            case CARD_7:
                std::cout << "7";
                break;
            case CARD_8:
                std::cout << "8";
                break;
            case CARD_9:
                std::cout << "9";
                break;
            case CARD_10:
                std::cout << "10";
                break;
            case CARD_JACK:
                std::cout << "J";
                break;
            case CARD_QUEEN:
                std::cout << "Q";
                break;
            case CARD_KING:
                std::cout << "K";
                break;
            case CARD_ACE:
                std::cout << "A";
                break;
            };

            switch (card.suit)
            {
            case SUIT_CLUBS:
                std::cout << "C";
                break;
            case SUIT_DIAMONDS:
                std::cout << "D";
                break;
            case SUIT_HEARTS:
                std::cout << "H";
                break;
            case SUIT_SPADES:
                std::cout << "S";
                break;
            };

            std::cout << " ";
        }

        std::array<Card, 52> create_deck()
        {
            std::array<Card, 52> deck{};
            std::size_t count{0};
            for (std::size_t i{0}; i < Suits::SUITS_MAX; i++ )
            {
                for(std::size_t j{0}; j < Cards::CARDS_MAX; j++)
                {
                    deck[count].rank = static_cast<Cards>(j);
                    deck[count].suit = static_cast<Suits>(i);
                    std::cout << i << j << " ";
                    count++;
                    
                };
                std::cout << "\n";
                // print_card(deck[i]);

            };


            return deck;
        }

        void print_deck(const std::array<Card, 52>& deck)
        {
                for(auto& card: deck)
                    print_card(card);

                std::cout << '\n';
        }

        int getCardValue(const Card& card)
        {
            switch (card.rank)
            {
            case Cards::CARD_JACK:
            case Cards::CARD_QUEEN:
            case Cards::CARD_KING:
                return 10;
                break;
            case Cards::CARD_ACE:
                return 11;
                break;
            
            default:
                return 2;
                break;
            }
        }

        void caller()
        {
            std::array<Card, 52> deck{create_deck()};
            print_deck(deck);

            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(deck.begin(),deck.end(),g);
            print_deck(deck);

            print_card(deck[5]);
            std::cout << " worth: " << getCardValue(deck[5]);
            std::cout << '\n';
        }
    }
}