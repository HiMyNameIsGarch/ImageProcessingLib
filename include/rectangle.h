#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "point.h"
#include "size.h"

class Rectangle {
private:
    Point m_topLeft;
    Size m_size;

public:
    Rectangle();
    Rectangle(const Point &topLeft, const Size &size);
    Rectangle(int x, int y, int width, int height);

    // Getters
    Point topLeft() const { return m_topLeft; };
    Size size() const { return m_size; };

    // Setters
    void setTopLeft(const Point &topLeft);
    void setSize(const Size &size);

    // Operators
    void operator+(const Point &point);
    void operator-(const Point &point);

    // The intersection between 2 rectangles
    Rectangle operator&(const Rectangle &r1) const;
    // The union between 2 rectangles
    Rectangle operator|(const Rectangle &rectangle) const;

};

#endif
