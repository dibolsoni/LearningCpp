#ifndef VECTOR_H
#define VECTOR_H

#include "Point3d.h" // for declaring Point3d::moveByVector() as a friend

class Vector3d
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public: 
    Vector3d(double x=0.0, double y=0.0, double z=0.0)
        : m_x{x}, m_y{y}, m_z{z}{}

    inline void print() const;

    friend void Point3d::moveByVector(const Vector3d &v);
};


#endif