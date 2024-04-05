#include "../include/rectangle.h"

#include <iostream>

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
    // // If the rectangles don't intersect
    // // return a rectangle with a size of 0
    // if (m_topLeft.x() > rectangle.m_topLeft.x() + rectangle.m_size.width() ||
    //     m_topLeft.y() > rectangle.m_topLeft.y() + rectangle.m_size.height() ||
    //     m_topLeft.x() + m_size.width() < rectangle.m_topLeft.x() ||
    //     m_topLeft.y() + m_size.height() < rectangle.m_topLeft.y()) {
    //     return Rectangle();
    // }
    // // If the rectangles intersect
    // // return a rectangle with the intersection
    // uint x = std::max(m_topLeft.x(), rectangle.m_topLeft.x());
    // uint y = std::max(m_topLeft.y(), rectangle.m_topLeft.y());
    // uint width = std::min(m_topLeft.x() + m_size.width(), rectangle.m_topLeft.x() + rectangle.m_size.width()) - x;
    // uint height = std::min(m_topLeft.y() + m_size.height(), rectangle.m_topLeft.y() + rectangle.m_size.height()) - y;
    // return Rectangle(x, y, width, height);
    return rectangle;
}

// The union between 2 rectangles
Rectangle Rectangle::operator|(const Rectangle &rectangle) const {
    // Compute the union between 2 rectangles
    // The union is a rectangle that contains both rectangles
    //
    // The top left point of the union is the minimum x and y of the 2 rectangles
    // The size of the union is the maximum x and y of the 2 rectangles
    // minus the top left point of the union
    // uint x = std::min(m_topLeft.x(), rectangle.m_topLeft.x());
    // uint y = std::min(m_topLeft.y(), rectangle.m_topLeft.y());
    // uint width = std::max(m_topLeft.x() + m_size.width(), rectangle.m_topLeft.x() + rectangle.m_size.width()) - x;
    // uint height = std::max(m_topLeft.y() + m_size.height(), rectangle.m_topLeft.y() + rectangle.m_size.height()) - y;
    // return Rectangle(x, y, width, height);
    return rectangle;
}
