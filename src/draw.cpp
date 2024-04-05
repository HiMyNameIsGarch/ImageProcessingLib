#include <iostream>
#include "../include/size.h"

namespace Draw {
    void drawRectangle(const Size &size) {
        for (uint i = 0; i < size.height(); i++) {
            for (uint j = 0; j < size.width(); j++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }

}
