#include "../include/rectangle.h"

Rectangle::Rectangle() {
    m_topLeft = Point();
    m_size = Size();
}

Rectangle::Rectangle(const Point &topLeft, const Size &size) {
    m_topLeft = topLeft;
    m_size = size;
}

// Optional??
Rectangle::Rectangle(int x, int y, int width, int height) {
    m_topLeft = Point(x, y);
    m_size = Size(width, height);
}

void Rectangle::setTopLeft(const Point &topLeft) {
    m_topLeft = topLeft;
}

void Rectangle::setSize(const Size &size) {
    m_size = size;
}

void Rectangle::operator+(const Point &point) {
    m_topLeft.setX(m_topLeft.x() + point.x());
    m_topLeft.setY(m_topLeft.y() + point.y());
}

void Rectangle::operator-(const Point &point) {
    m_topLeft.setX(m_topLeft.x() - point.x());
    m_topLeft.setY(m_topLeft.y() - point.y());
}

// The intersectoin between 2 rectangles
Rectangle Rectangle::operator&(const Rectangle &rectangle) const {
    return Rectangle();
}

// The union between 2 rectangles
Rectangle Rectangle::operator|(const Rectangle &rectangle) const {
    return Rectangle();
}
