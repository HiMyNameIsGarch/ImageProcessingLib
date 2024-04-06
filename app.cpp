// #include "include/imageProcessing/convolution.h"
#include "include/image.h"

int main() {
    Image imgSize3 = Image(3,3);
    Image img = Image(imgSize3);
    std::cout << img;
    img = Image::zeros(4,3);
    std::cout << img;
    img = Image::ones(4,3);
    std::cout << img;
    img = Image::ones(4,4);
    std::cout << img;
    // img.load("./samples/load/barbara.ascii.pgm");
    // Convolution g = Convolution(nullptr);
    // Image dst = Image(img.size());
    // g.process(img, dst);
    // dst.save("./samples/saved/barbara.ascii.pgm");
    return 0;
}
