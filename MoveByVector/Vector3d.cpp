#include "Vector3d.h"

#include <iostream>

inline void Vector3d::print() const
{
    std::cout << "Vector(" << this->m_x << " , " << this->m_y << " , " << this->m_z << ")\n";
}


void moveByVector(const Vector3d &v)
{
    // Add the vector components to the corresponding point coordinates
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}
