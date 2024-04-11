#include "../include/rectangle.h"
#include <algorithm>

using std::min;
using std::max;

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

// The intersection between 2 rectangles
Rectangle Rectangle::operator&(const Rectangle &rectangle) const {
    int x1 = std::max(m_topLeft.x(), rectangle.m_topLeft.x());
    int y1 = std::max(m_topLeft.y(), rectangle.m_topLeft.y());
    int x2 = std::min(m_topLeft.x() + m_size.width(), rectangle.m_topLeft.x() + rectangle.m_size.width());
    int y2 = std::min(m_topLeft.y() + m_size.height(), rectangle.m_topLeft.y() + rectangle.m_size.height());

    if (x2 < x1 || y2 < y1) {
        // No intersection
        return Rectangle();
    } else {
        int width = x2 - x1;
        int height = y2 - y1;
        return Rectangle(x1, y1, width, height);
    }
    return rectangle;
}

// The union between 2 rectangles
Rectangle Rectangle::operator|(const Rectangle &rectangle) const {
    int x1 = min(m_topLeft.x(), rectangle.m_topLeft.x());
    int y1 = min(m_topLeft.y(), rectangle.m_topLeft.y());
    int x2 = max(m_topLeft.x() + m_size.width(), rectangle.m_topLeft.x() + rectangle.m_size.width());
    int y2 = max(m_topLeft.y() + m_size.height(), rectangle.m_topLeft.y() + rectangle.m_size.height());

    int width = x2 - x1;
    int height = y2 - y1;

    return Rectangle(x1, y1, width, height);
    return rectangle;
}
