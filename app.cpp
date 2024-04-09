// #include "include/imageProcessing/convolution.h"
#include "include/draw.h"
#include "include/image.h"

int main() {
    Image img = Image();
    img.load("./samples/load/barbara.ascii.pgm");
    // Point p1 = Point(0, 0);
    // Point p2 = Point(255, 255);
    // drawLine(img, p1, p2, 255);
    int radius = 100;
    Point center = Point(255, 255);
    drawCircle(img, center, radius, 255);
    img.save("./samples/saved/barbara.line.pgm");
    return 0;
}
