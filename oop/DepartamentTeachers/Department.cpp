#include "Department.h"

void Department::add(const Teacher& teacher) 
{
    m_teachers.push_back(teacher);
}

std::ostream& operator<<(std::ostream& out, const Department& department) 
{
    out << "Department: ";

    for (const auto& teacher : department.m_teachers)
    {
        out << teacher.get().getName() << ' ';
    }

    out << '\n';

    return out;
}


