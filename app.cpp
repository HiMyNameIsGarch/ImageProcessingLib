#include "include/rectangle.h"
#include "include/point.h"
#include "include/image.h"
#include <iostream>

int main() {
    Image img = Image(Size(2,2));
    std::cout << img;
    img = Image::zeros(10, 10);
    std::cout << img;
    return 0;
}
