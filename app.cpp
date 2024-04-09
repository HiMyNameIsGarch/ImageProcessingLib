#include "include/imageProcessing/convolution.h"
#include "include/image.h"

int main() {
    Image img = Image();
    img.load("./samples/load/barbara.ascii.pgm");
    Convolution g = Convolution(KernelType::box);
    Image dst = Image(img.size());
    g.process(img, dst);
    dst.save("./samples/saved/barbara.ascii.pgm");
    return 0;
}
