#pragma once
#ifndef POINT_H
#define POINT_H

class Point {

private:
    unsigned int m_x;
    unsigned int m_y;

public:
    Point(); // Init point at (0,0)
    Point(unsigned int x, unsigned int y);

    // Getters
    unsigned int x() const { return m_x; };
    unsigned int y() const { return m_y; };

    // Setters
    void setX(unsigned int x);
    void setY(unsigned int y);
};

#endif
