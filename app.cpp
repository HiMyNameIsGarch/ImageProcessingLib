#include "include/rectangle.h"
#include "include/point.h"
#include "include/image.h"
#include <iostream>

int main() {
    Image img = Image();
    // std::cout << img;
    // img = Image::ones(10, 10);
    // std::cout << img;
    // img = img * 3;
    // std:: cout << img;
    img.load("./samples/load/small.pgm");
    std::cout << img;
    img.save("./samples/saved/small.pgm");
    return 0;
}
