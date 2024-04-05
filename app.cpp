#include "include/point.h"
#include "include/rectangle.h"
#include <iostream>

int main() {
    std::cout << "asdasdasd!" << std::endl;
    Point p = Point(1, 2);
    Rectangle r1 = Rectangle(p, Size(3, 4));
    Rectangle r2 = Rectangle(p, Size(3, 4));
    r1 & r2;
    r1 & r2;
    return 0;
}
