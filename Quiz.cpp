#include <iostream>
#include <array>
#include <numeric> // std::reduce
#include <string_view>
#include <string>
#include <vector> 
#include <type_traits>
#include <iterator>
#include <cstdlib>
#include "effolkronium/random.hpp"
// #include "random.hpp"

// #define DEBUG 

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

        enum MenuOption{
            MENU_QUIT,
            MENU_STAND,
            MENU_HIT,
            MAX_MENU
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
        void print_deck(const std::vector<Card>& deck)
        {
            for (auto& card: deck)
            {
                print_card(card);
            }
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

    namespace QuestionSeven
    {   
        using Card = QuestionSix::Card;
        struct Player{
            std::string name;
            std::vector<Card> cards;
        };

        void print_cards(std::vector<Card> cards)
        {   
            for (const auto& card: cards)
            {
                QuestionSix::print_card(card);
            }
        }

        /**
         * get a random card from a game_deck
         * @returns Card
        */
        Card get_card(std::vector<Card>& deck)
        {
            using Random = effolkronium::random_static;
            std::size_t random_card_id = 
                static_cast<std::size_t>(
                    Random::get(0, static_cast<int>(deck.size())
                )
            );
            Card card = deck[random_card_id]; 
            deck.erase(deck.begin() + random_card_id);
            return card;
        }

        void get_cards_for_players(std::vector<Card>& deck, std::array<Player, 2>& players, size_t num_cards)
        {
        
            for (auto& player: players)
                for (size_t i{0}; i < num_cards; i++)
                {
                    if (player.name == players[i].name && num_cards > 1)
                        i++;
                    player.cards.push_back(get_card(deck));
                }
        }


        QuestionSix::MenuOption get_menu_option()
        {
            unsigned int menu_option = 3;
            std::cout << "The cards are on table. \n";
            std::cout << "What do you wanna to do?. \n";
            std::cout << "press 1 - to stand \n";
            std::cout << "press 2 - to hit \n";
            std::cout << "press 0 - to quit \n";
            std::cin >> menu_option;
            return static_cast<QuestionSix::MenuOption>(menu_option);
        }

        void action(QuestionSix::MenuOption menu_option, Player &player, std::vector<Card> &deck, bool& stand)
        {
            switch (menu_option)
            {
            case QuestionSix::MenuOption::MENU_STAND:
                std::cout << player.name << " choosed to stand. \n";
                stand = true;
                break;
            case QuestionSix::MenuOption::MENU_HIT:
                std::cout << player.name << " choosed to hit. \n";
                player.cards.push_back(get_card(deck));
                break; 
            case QuestionSix::MenuOption::MENU_QUIT:
                stand = true;
                return;

            
            default:
                std::cerr << "Type a valid menu option \n";
                break;
            }
            
        }

        unsigned int sum_card_values(std::vector<Card> cards)
        {
            unsigned int cards_value{0};
            unsigned int aces{0};
            for (auto& card : cards)
            {
                if (card.rank == QuestionSix::Cards::CARD_ACE)
                    aces += 10;
                cards_value += QuestionSix::getCardValue(card);
                if (cards_value > 21)
                    cards_value -= aces;
            }
            return cards_value;
        }

        QuestionSix::MenuOption get_ai_option(Player dealer)
        {
            unsigned int cards_value{sum_card_values(dealer.cards)};
            if (cards_value < 17)
                return QuestionSix::MenuOption::MENU_HIT;
            else 
                return QuestionSix::MenuOption::MENU_STAND;
        }


        void print_game(std::array<Player, 2>& players)
        {

            for(std::size_t i{0}; i < players.size(); i++)
            {
                std::cout << players[i].name << " has ";
                print_cards(players[i].cards);
                std::cout << " cards\ ";
                std::cout << " - the sum is: " << sum_card_values(players[i].cards) << '\n';
            }
        }

        bool play_black_jack(std::array<Card,52> deck)
        {
            std::vector<Card> game_deck(deck.begin(), deck.end());
            std::cout << "GAME STARTED" << '\n';
            
            std::array<Player,2> players{{
                {"Dealer", {}},
                {"Player", {}}
            }};
            std::cout << "deck size: " << game_deck.size() << '\n'; 
            QuestionSix::print_deck(game_deck);

            get_cards_for_players(game_deck, players, 2);

            bool player_stands = false;
            bool dealer_stands = false; 
            while(dealer_stands == false || player_stands == false)
            {
                system("clear");
                print_game(players);
                if (!player_stands)
                    action(get_menu_option(),players[1],game_deck, player_stands);
                if(sum_card_values(players[1].cards) > 21)
                {
                    print_game(players);
                    std::cout << players[1].name <<" did more then 21 points. \n";
                    std::cout << players[1].name <<" lose. \n";
                    return false;
                }
                action(get_ai_option(players[0]),players[0],game_deck, dealer_stands);
                if(sum_card_values(players[0].cards) > 21)
                {
                    print_game(players);
                    std::cout << players[0].name <<" did more then 21 points. \n";
                    std::cout << players[0].name <<" lose. \n";
                    return true;
                }

            }

            print_game(players);
            if (sum_card_values(players[0].cards) > sum_card_values(players[1].cards))
            {
                std::cout << players[0].name << " wins the game! \n";
                return false;
            }
            else
            {
                std::cout << players[1].name << "wins the game! \n";
                return true;       
            }
        }
    }
}

namespace Chapter7
{
    namespace BinarySearch
    {
        // array is the array to search over.
        // target is the value we're trying to determine exists or not.
        // min is the index of the lower bounds of the array we're searching.
        // max is the index of the upper bounds of the array we're searching.
        // binarySearch() should return the index of the target element if the target is found, -1 otherwise

        int binarySearch(const int *array, int target, int min, int max)
        {
            assert(array); // make sure array exists

            int mid = { min + ((max-min) / 2) };
            static int called{0};

            #ifdef DEBUG
            std::cout << called <<  " calling: " << '\n';
            std::cout << "target: " << target <<'\n';
            std::cout << "min: " << min << '\n'; 
            std::cout << "max: " << max << '\n';
            std::cout << "mid: " << mid << '\n';
            #endif

            if (min > max)
                return -1;

            called++;
            if (array[mid] > target)
            {
                binarySearch(array, target, min, mid - 1);
            }
            else 
            {
                binarySearch(array, target, mid + 1, max);
            }
        }
        
        void caller()
        {
            std::array<int, 9> array{ 3, 6, 7, 9, 12, 15, 18, 21, 24 };
            int target = 10;
            std::cout << binarySearch(array.begin(), target, 0, array.size()) << "\n";
        }
    }
}

namespace Chapter15
{
    
}