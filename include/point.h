#pragma once
#ifndef POINT_H
#define POINT_H

class Point {

private:
    int m_x;
    int m_y;

public:
    Point(); // Init point at (0,0)
    Point(int x, int y);

    // Getters
    int x() const { return m_x; };
    int y() const { return m_y; };

    // Setters
    void setX(int x);
    void setY(int y);
};

#endif
