#include "../include/point.h"

Point::Point() :
    m_x(0), m_y(0) {}

Point::Point(unsigned int x, unsigned int y) :
    m_x(x), m_y(y) {}

void Point::setX(unsigned int x) {
    m_x = x;
}

void Point::setY(unsigned int y) {
    m_y = y;
}
