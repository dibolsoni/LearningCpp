#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Teacher.h"

#include <string>
#include <functional>
#include <vector>
#include <iostream>

class Department
{
private:
    std::vector<std::reference_wrapper<const Teacher>> m_teachers{};
 
public:
    void add(const Teacher& teacher); 
 
    friend std::ostream& operator<<(std::ostream& out, const Department& department);
};

#endif