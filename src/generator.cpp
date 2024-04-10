#include "../include/generator.h"
#include "../include/draw.h"
#include "../include/rectangle.h"
#include "../include/imageProcessing/convolution.h"
#include "../include/imageProcessing/gammaCorrection.h"
#include "../include/imageProcessing/brightness.h"
#include <iostream>

using std::cout;
using std::endl;

void generateConvolution() {
    cout << "Begin generating convolution" << endl;
    Image img = Image();
    img.load("./samples/load/sample.pgm");

    cout << "Generate Box Kernel" << endl;

    Image dst = Image(img.size());
    Convolution conv = Convolution(KernelType::box);
    conv.process(img, dst);
    dst.save("./samples/saved/sample-convolution.pgm");

    cout << "Generate Mean Blur" << endl;
    dst = Image(img.size());
    conv = Convolution(KernelType::meanBlur);
    conv.process(img, dst);
    dst.save("./samples/saved/sample-mean-blur.pgm");

    cout << "Generate Gaussian Blur" << endl;
    dst = Image(img.size());
    conv = Convolution(KernelType::gaussianBlur);
    conv.process(img, dst);
    dst.save("./samples/saved/sample-gaussian-blur.pgm");

    cout << "Generate Vertical Sobel" << endl;
    dst = Image(img.size());
    conv = Convolution(KernelType::verticalSobel);
    conv.process(img, dst);
    dst.save("./samples/saved/sample-vertical-sobel.pgm");

    cout << "Generate Horizontal Sobel" << endl;
    dst = Image(img.size());
    conv = Convolution(KernelType::horizontalSobel);
    conv.process(img, dst);
    dst.save("./samples/saved/sample-horizontal-sobel.pgm");
}

void generateGamma() {
    cout << "Begin testing gamma" << endl;
    Image img = Image();
    img.load("./samples/load/sample.pgm");
    Image dst = Image(img.size());
    GammaCorrection gamma = GammaCorrection(0.65);
    gamma.process(img, dst);
    dst.save("./samples/saved/sample-gamma-dark.pgm");
    GammaCorrection gamma2 = GammaCorrection(1.35);
    gamma2.process(img, dst);
    dst.save("./samples/saved/sample-gamma-light.pgm");

}

void generateBrightness() {
    cout << "Begin testing brightness" << endl;
    Image img = Image();
    img.load("./samples/load/sample.pgm");
    Image dst = Image(img.size());
    Brightness brightness = Brightness(1, 35);
    brightness.process(img, dst);
    dst.save("./samples/saved/sample-brightness.pgm");

}

void generateDraw() {
    Image baseImg = Image();
    baseImg.load("./samples/load/sample.pgm");
    Image img = baseImg;

    // Draw line
    drawLine(img, Point(0,0), Point(255, 255), 255);
    img.save("./samples/saved/sample-line.pgm");
    img = baseImg;

    // Draw rectangle by points
    drawRectangle(img, Point(10,10), Point(100, 100), 255);
    img.save("./samples/saved/sample-rectangle-by-points.pgm");
    img = baseImg;

    // Draw rectangle
    drawRectangle(img, Rectangle(Point(22, 22), Size(200, 200)), 255);
    img.save("./samples/saved/sample-rectangle.pgm");
    img = baseImg;

    // Draw circle
    drawCircle(img, Point(128, 128), 50, 255);
    img.save("./samples/saved/sample-circle.pgm");
}
