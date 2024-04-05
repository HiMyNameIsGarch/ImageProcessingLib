#include "include/imageProcessing/convolution.h"
#include "include/imageProcessing/gammaCorrection.h"
#include "include/rectangle.h"
#include "include/point.h"
#include "include/image.h"
#include <iostream>
#include "include/imageProcessing//brightness.h"

int main() {
    Image img = Image();
    // std::cout << img;
    // img = Image::ones(10, 10);
    // std::cout << img;
    // img = img * 3;
    // std:: cout << img;
    img.load("./samples/load/barbara.ascii.pgm");
    Convolution g = Convolution(nullptr);
    Image dst = Image(img.size());
    g.process(img, dst);
    dst.save("./samples/saved/barbara.ascii.pgm");
    return 0;
}
