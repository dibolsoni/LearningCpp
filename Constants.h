#pragma once
#include <cstdint>

namespace constants
{
    inline const double pi = 3.14159; //inline(c++17) constant on runtime
    inline constexpr double pi2 {3.14159}; //inline const only on compile time
    inline const std::int_fast16_t days_per_week {7}; // fastest type int
    inline const std::int_least16_t days_per_week2 {7}; // fastest type int
    inline constexpr int max_class_size {30};

} // namespace constants
