// #include "Math.h"
// #include "Constants.h"
// #include "Binaries.cpp"
// #include "Namespace.cpp"
// #include "String.cpp"
// #include "Enums.cpp"
// #include "Struct.cpp"
// #include "SwitchStatement.cpp"
// #include "IfStatement.cpp"
// #include "Random.cpp"
// #include "ArraySamples.cpp"
// #include "Pointers.cpp"
// #include "References.cpp"
// #include "Vectors.cpp"
// #include "Quiz.cpp"
// #include "playground.cpp"
// #include "Functions.cpp"
// #include "HeapAndStack.cpp"
// #include "Test.cpp"
// #include "CommandLine.cpp"
// #include "Lambdas.cpp"
// #include "Classes.cpp"
// #include "MonsterGenerator/main.cpp"
// #include "InitializerList.cpp"
// #include "Template.cpp"
// #include "TryCatch.cpp"
#include "SmartPointersAndMove.cpp"


#include "Timer.cpp"
#include <iostream>
#include <bitset>


void print_const();

// reference https://en.cppreference.com/w/

int main()
{
    Timer t;
    std::cout << "Starting a new program seconds\n\n";

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
    // Pointers::VoidPointers::caller();

    // ArraySample::dynamic_sorted_list();
    // ArraySample::std_array();
    // ArraySample::StructArray::caller();
    // ArraySample::STD_Algorithms::caller();

    // References::caller();
    // Vectors::caller();

    // Chapter6::QuestionOne::caller();
    // Chapter6::QuestionThree::caller();
    // Chapter6::QuestionFour::caller();
    // Chapter6::QuestionFive::caller();
    // Chapter6::QuestionSix::caller();
    // Chapter6::QuestionSeven::play_black_jack(Chapter6::QuestionSix::create_deck());

    // Chapter7::BinarySearch::caller();

    // Playground::caller();

    // Functions::caller();

    // TheStack::caller();

    // Test::caller();

    // Lambdas::caller();

    // ClassesBasic::SimpleStack::caller();
    // ClassesBasic::QuizBall::caller();
    // ClassesBasic::QuizRGBA::caller();
    // ClassesBasic::Destructor::caller();
    // ClassesBasic::Quiz3d::main();
    // ClassesBasic::AnonymousObjects::caller();

    // MonsterClass::main();

    // ClassesBasic::OverloadingOperators::caller();

    // InitializerList::caller();

    // Template::caller();
    // Template::templateClass();
    // Template::Quiz::questonTwoCaller();
    // Template::Quiz::questonThreeCaller();

    // TryCatch::caller();
    // TryCatch::Quiz::caller();

    SmartPointers::RValueRefs::main();    

    std::cout << "\nTime elapsed:" << t.elapsed() << " seconds\n";
    return EXIT_SUCCESS;
}

//using argument lines main
//argc = Arguments Counter
//argv = Arguments Values
// int main(int argc, char *argv[])
// {
//     CommandLine::caller(argc, argv);

//     return 0;
// }





// void print_const()
// {
//     std::cout << "value:" << constants::pi << "\tsize:" << sizeof(constants::pi)<<"\n";
//     std::cout << "value:" << constants::pi2 << "\tsize:" << sizeof(constants::pi2)<<"\n";
//     std::cout << "value:" << constants::days_per_week << "\tsize:" << sizeof(constants::days_per_week)<<"\n";
//     std::cout << "value:" << constants::days_per_week2 << "\tsize:" << sizeof(constants::days_per_week2)<<"\n";
// }
