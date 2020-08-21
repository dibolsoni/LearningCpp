#include <iostream>

#define DEBUG

namespace Struct
{
    void nested_struct()
    {
        struct Employee
        {
            short id;
            int age;
            double wage;
        };
        
        struct Company
        {
            Employee CEO; // Employee is a struct within the Company struct
            int numberOfEmployees;
        };
        
        Company myCompany{{ 1, 42, 60000.0 }, 5 };
    }

    void question_one()
    {
        /*
        You are running a website, and you are trying to keep track of how much money you make per
        day from advertising. Declare an advertising struct that keeps track of how many ads 
        you’ve shown to readers, what percentage of ads were clicked on by users, and how much
        you earned on average from each ad that was clicked. Read in values for each of these 
        fields from the user. Pass the advertising struct to a function that prints each of the 
        values, and then calculates how much you made for that day (multiply all 3 fields together).
        */
        struct adsPerDay 
        {
            int total_count;
            float percent_clicks;
            float amount_money_per_clicks;
        } user;

        std::cout << "\n total:";
        std::cin >> user.total_count;
        std::cout << "\n percent of clicks:";
        std::cin >> user.percent_clicks;
        std::cout << "\n amount erned per click:";
        std::cin >> user.amount_money_per_clicks;

        // transform int percent into decimals
        user.percent_clicks *= 0.01;
        
        #ifdef DEBUG
            std::cout << user.total_count << " " << user.percent_clicks << " " << user.amount_money_per_clicks << std::endl;
        #endif


        float total_amount { user.total_count * user.percent_clicks * user.amount_money_per_clicks };

        std::cout << "\n you made $" << total_amount << " on this day " << "\n";

    }

    void question_two()
    {
        /*
        Create a struct to hold a fraction. The struct should have an integer numerator and 
        an integer denominator member. Declare 2 fraction variables and read them in from the 
        user. Write a function called multiply that takes both fractions, multiplies them 
        together, and prints the result out as a decimal number. You do not need to reduce 
        the fraction to its lowest terms. 
        */

       struct Fraction
       {
           int numberator;
           int denominator;
       };

       Fraction x {1, 5};
       Fraction y {2, 6};

       Fraction result 
       {
           x.numberator * y.numberator,
           x.denominator * y.denominator           
       };

        std::cout << "the result is: " << result.numberator << "/" << result.denominator << "\n";

        
    }
}