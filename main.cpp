#include "Math.h"
#include "Constants.h"
#include "Binaries.cpp"
#include "Namespace.cpp"
#include "String.cpp"
#include "Enums.cpp"
#include "Struct.cpp"
#include "SwitchStatement.cpp"
#include "IfStatement.cpp"
#include "Random.cpp"
#include "ArraySamples.cpp"
#include "Pointers.cpp"
#include "References.cpp"
#include <iostream>
#include <bitset>

void print_const(); 

// reference https://en.cppreference.com/w/

int main()
{

    // Math::print_sum();
    // bit_masks();
    //bit_mask_exercise();
    //binaries_count(10);
    // Math::converts();

    // Namespace::question_one();
    // Namespace::question_two();
    // Namespace::question_three();

    // String::string_view();

    // Enum::getEnum();

    // Struct::question_one();
    // Struct::question_two();

    //IfStatement::init_statement();
    
    // int result = SwitchStatement::question_one_calculate(4,2,'p');
    // std::cout << "result is " << result << "\n";

    // SwitchStatement::question_two::printNumOfLegsCaller();

    // Random::randomUsingEffolkronium();

    // ArraySample::copy_array();

    // Pointers::print_address_and_value();
    // Pointers::getVowels();
    // Pointers::itinarating_an_array();
    // Pointers::Question_two::caller();

    // ArraySample::dynamic_sorted_list();

    References::caller();

    return EXIT_SUCCESS; 
}





void print_const() 
{
    std::cout << "value:" << constants::pi << "\tsize:" << sizeof(constants::pi)<<"\n";
    std::cout << "value:" << constants::pi2 << "\tsize:" << sizeof(constants::pi2)<<"\n";
    std::cout << "value:" << constants::days_per_week << "\tsize:" << sizeof(constants::days_per_week)<<"\n";
    std::cout << "value:" << constants::days_per_week2 << "\tsize:" << sizeof(constants::days_per_week2)<<"\n";
}